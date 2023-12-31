#include "reclamation.h"
#include "ui_reclamation.h"
#include "reclam.h"
#include <QMessageBox>
#include <QDebug>
#include <QGridLayout>
#include <QSqlRecord>
#include <QSortFilterProxyModel>
#include <QTimer>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QChartView>
#include <QtCharts/QBarCategoryAxis>
#include <QDir>
#include <QPdfWriter>
#include <QPainter>
#include <QTextDocument>
#include <QDesktopServices>
#include <QUrl>
#include <QJsonArray>
#include <QJsonObject>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include "smtp.h"
#include "mainwindow.h"
reclamation::reclamation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::reclamation)
{
    ui->setupUi(this);
    refresh();
    connect(ui->tableView, SIGNAL(clicked(const QModelIndex &)), this, SLOT(onTableClicked(const QModelIndex &)));
    int ret = A.connect_arduino();
    switch(ret)
    {
        case 0:
            qDebug()<<"Arduino is available and connected";
        break;
        case 1:
            qDebug()<<"Arduino is available and not connected";
        break;
        case -1:
            qDebug()<<"Arduino is not available";
        break;
    }

    QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(checkSerial()));

    QTimer* m_databaseTimer = new QTimer(this);
    connect(m_databaseTimer, &QTimer::timeout, this, [this]{
            int login = Rtmp.researchLogin();

            if(login ==1)
            {
                ui->loggedIn->setText("Logged in");
                ui->loggedIn->setStyleSheet("color:green");
            }else
            {
                ui->loggedIn->setText("Not Logged in");
                ui->loggedIn->setStyleSheet("color:red");
            }
});
    m_databaseTimer->start(1000);
}

void reclamation::checkSerial()
{
    QByteArray data = A.read_from_arduino();
    QString buffer = QString::fromLatin1(data);

    Rtmp.modifierLoggin(buffer.toInt());

}
void reclamation::refresh()
{
    QSortFilterProxyModel *tri = new QSortFilterProxyModel();
    tri->setSourceModel(Rtmp.afficher());
    ui->tableView->setModel(tri);


    QtCharts::QBarSet *set = new QtCharts::QBarSet("type");
    QStringList categories;

    categories<<"Validée"<<"Non Validée";

    *set <<Rtmp.researcherEtap(1)->index(0,0).data().toInt()<<Rtmp.researcherEtap(0)->index(0,0).data().toInt();

    QtCharts::QBarSeries *series = new QtCharts::QBarSeries(this);
    series->append(set);


    QtCharts::QChart *chart = new QtCharts::QChart();
    chart->setTitle("Les types de reclamations");
    chart->createDefaultAxes();
    chart->addSeries(series);


    QtCharts::QBarCategoryAxis *axis = new QtCharts::QBarCategoryAxis();
    axis->append(categories);
    chart->setAxisX(axis, series);


    QtCharts::QChartView * m_chartView = new QtCharts::QChartView(chart, this);


    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(m_chartView);

    qDeleteAll(ui->frame->children());
    ui->frame->setLayout(layout);
}

reclamation::~reclamation()
{
    delete ui;
}

void reclamation::onTableClicked(const QModelIndex &index)
{
    select_reclamation=index.row();
}

void reclamation::on_reclamation_ajouter_clicked()
{

    QString nom = ui->reclamationEdit_Nom->text();
    QString email = ui->reclamationEdit_Email->text();
    QString rec= ui->reclamationEdit_Reclamation->toPlainText();
    int cin= ui->reclamationEdit_CIN->text().toInt();
    int typeRec= 0;
    QDate date= ui->reclamationEdit_date->date();

    if(nom == "" || email == "" || rec == "")
    {
        QMessageBox::warning(nullptr,QObject::tr("Error"),
                                 QObject::tr("Fields empty\n"
                                             "Click cancel to exit."),QMessageBox::Cancel);
        return;
    }

    if(cin<10000000 || cin>99999999)
    {
        QMessageBox::warning(nullptr,QObject::tr("Error"),
                                 QObject::tr("CIN must contain 8 digits\n"
                                             "Click cancel to exit."),QMessageBox::Cancel);
        return;
    }

    QRegExp mailCondition("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b");
    mailCondition.setCaseSensitivity(Qt::CaseInsensitive);
    mailCondition.setPatternSyntax(QRegExp::RegExp);

    if(!mailCondition.exactMatch(email))
    {
        QMessageBox::warning(nullptr,QObject::tr("Error"),
                                 QObject::tr("Email invalid\n"
                                             "Click cancel to exit."),QMessageBox::Cancel);
        return;
    }

    if(Rtmp.researchCIN(cin))
    {
        QMessageBox::warning(nullptr,QObject::tr("Error"),
                                 QObject::tr("CIN already exists\n"
                                             "Click cancel to exit."),QMessageBox::Cancel);
        return;
    }

    reclam reclamation(nom,email,rec,cin,typeRec,date);
    QString password = ui->password->text();
    if(password != "")
    {
        if(reclamation.ajouter())
        {
            QFile f("C:/Users/DELL/OneDrive/Bureau/PROJET/historic.txt");

            if(!f.open(QFile::WriteOnly |QIODevice::Append | QFile::Text))
            {
                QMessageBox::warning(this,"title","file not open");
                return;
            }
            QTextStream outt(&f);
            QString text = "  ajouter une reclamation \r\n";
            QString sDate = QDateTime::currentDateTime().toString("dddd dd MMMM yyyy hh:mm:ss.zzz :");
            outt << sDate;
            outt << text ;
            f.flush();
            f.close();

            Smtp* smtp = new Smtp("mohamedaziz.grissa@esprit.tn",password, "smtp.gmail.com");
            smtp->sendMail("mohamedaziz.grissa@esprit.tn", "mohamedaziz.grissa@esprit.tn" , "Added reclamation",
                           "Added the following Nom:"+nom+" Email:"+email+" Reclamation:"+rec);

            QMessageBox::information(nullptr,QObject::tr("Added"),
                                     QObject::tr("Added successfully\n"
                                                 "Click cancel to exit."),QMessageBox::Cancel);
            qDebug() << "Added successfully";

            ui->reclamationEdit_Nom->setText("");
            ui->reclamationEdit_Email->setText("");
            ui->reclamationEdit_Reclamation->setPlainText("");
            ui->reclamationEdit_CIN->setText("");

            refresh();
        }
        else{

            QMessageBox::warning(nullptr,QObject::tr("Error"),
                                     QObject::tr("Failed to add\n"
                                                 "Click cancel to exit."),QMessageBox::Cancel);
            qDebug() << "Error";
        }
    }else{

        QMessageBox::warning(nullptr,QObject::tr("Error"),
                                 QObject::tr("password empty\n"
                                             "Click cancel to exit."),QMessageBox::Cancel);
        qDebug() << "Error";
    }


}

void reclamation::on_reclamation_delete_clicked()
{
    if(select_reclamation == -1)
        return;

    int id = ui->tableView->model()->index(select_reclamation,0).data().toInt();
        if(Rtmp.supprimer(id))
    {
        QFile f("C:/Users/DELL/OneDrive/Bureau/PROJET/historic.txt");

            if(!f.open(QFile::WriteOnly |QIODevice::Append | QFile::Text))
            {
                QMessageBox::warning(this,"title","file not open");
                return;
            }
            QTextStream outt(&f);
            QString text = "  supprimer une reclamation \r\n";
            QString sDate = QDateTime::currentDateTime().toString("dddd dd MMMM yyyy hh:mm:ss.zzz :");
            outt << sDate;
            outt << text ;
            f.flush();
            f.close();
            QString password = ui->password->text();
            Smtp* smtp = new Smtp("mohamedaziz.grissa@esprit.tn",password, "smtp.gmail.com");
            smtp->sendMail("mohamedaziz.grissa@esprit.tn", "mohamedaziz.grissa@esprit.tn" , "Removed reclamation",
                           QString("Removed reclamation id:%1").arg(id));

        QMessageBox::information(nullptr,QObject::tr("Deleted"),
                                 QObject::tr("Reclamation deleted successfully\n"
                                             "Click cancel to exit."),QMessageBox::Cancel);
        select_reclamation = -1;
        refresh();
    }
    else
    {
        QMessageBox::warning(nullptr,QObject::tr("Error"),
                                 QObject::tr("cant delete reclamation\n"
                                             "Click cancel to exit."),QMessageBox::Cancel);

    }
}

void reclamation::on_reclamation_modifier_show_clicked()
{
    if(select_reclamation == -1)
        return;

    ui->reclamationEdit_Nom_2->setText(ui->tableView->model()->index(select_reclamation,1).data().toString());
    ui->reclamationEdit_CIN_2->setText(ui->tableView->model()->index(select_reclamation,2).data().toString());
    ui->reclamationEdit_Email_2->setText(ui->tableView->model()->index(select_reclamation,3).data().toString());
    ui->reclamationEdit_date_2->setDate(ui->tableView->model()->index(select_reclamation,4).data().toDate());
    ui->reclamationEdit_Reclamation_2->setPlainText(ui->tableView->model()->index(select_reclamation,5).data().toString());
    ui->stackedWidget->setCurrentIndex(1);
}

void reclamation::on_reclamation_annuler_clicked()
{
    select_reclamation = -1;
    ui->stackedWidget->setCurrentIndex(0);
}

void reclamation::on_reclamation_modifier_clicked()
{
    int id = ui->tableView->model()->index(select_reclamation,0).data().toInt();

    QString nom = ui->reclamationEdit_Nom_2->text();
    QString email = ui->reclamationEdit_Email_2->text();
    QString rec= ui->reclamationEdit_Reclamation_2->toPlainText();
    int cin= ui->reclamationEdit_CIN_2->text().toInt();
    int typeRec= 0;
    QDate date= ui->reclamationEdit_date_2->date();

    if(nom == "" || email == "" || rec == "")
    {
        QMessageBox::warning(nullptr,QObject::tr("Error"),
                                 QObject::tr("Fields empty\n"
                                             "Click cancel to exit."),QMessageBox::Cancel);
        return;
    }

    if(cin<10000000 || cin>99999999)
    {
        QMessageBox::warning(nullptr,QObject::tr("Error"),
                                 QObject::tr("CIN must contain 8 digits\n"
                                             "Click cancel to exit."),QMessageBox::Cancel);
        return;
    }

    QRegExp mailCondition("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b");
    mailCondition.setCaseSensitivity(Qt::CaseInsensitive);
    mailCondition.setPatternSyntax(QRegExp::RegExp);

    if(!mailCondition.exactMatch(email))
    {
        QMessageBox::warning(nullptr,QObject::tr("Error"),
                                 QObject::tr("Email invalid\n"
                                             "Click cancel to exit."),QMessageBox::Cancel);
        return;
    }
    if(Rtmp.researchCINID(cin,id))
    {
        QMessageBox::warning(nullptr,QObject::tr("Error"),
                                 QObject::tr("CIN already exists\n"
                                             "Click cancel to exit."),QMessageBox::Cancel);
        return;
    }
    reclam reclamation(nom,email,rec,cin,typeRec,date);

    if(reclamation.modifier(id))
    {
        QFile f("C:/Users/DELL/OneDrive/Bureau/PROJET/historic.txt");

            if(!f.open(QFile::WriteOnly |QIODevice::Append | QFile::Text))
            {
                QMessageBox::warning(this,"title","file not open");
                return;
            }
            QTextStream outt(&f);
            QString text = "  modifier une reclamation \r\n";
            QString sDate = QDateTime::currentDateTime().toString("dddd dd MMMM yyyy hh:mm:ss.zzz :");
            outt << sDate;
            outt << text ;
            f.flush();
            f.close();

            QString password = ui->password->text();
            Smtp* smtp = new Smtp("mohamedaziz.grissa@esprit.tn",password, "smtp.gmail.com");
            smtp->sendMail("mohamedaziz.grissa@esprit.tn", "mohamedaziz.grissa@esprit.tn" , "Modifier reclamation",
                           "Modifier the following Nom:"+nom+" Email:"+email+" Reclamation:"+rec);
        QMessageBox::information(nullptr,QObject::tr("Modify"),
                                 QObject::tr("Modify successfully\n"
                                             "Click cancel to exit."),QMessageBox::Cancel);

        ui->reclamationEdit_Nom_2->setText("");
        ui->reclamationEdit_Email_2->setText("");
        ui->reclamationEdit_Reclamation_2->setPlainText("");
        ui->reclamationEdit_CIN_2->setText("");

        select_reclamation = -1;
        ui->stackedWidget->setCurrentIndex(0);
        refresh();
    }
    else{

        QMessageBox::warning(nullptr,QObject::tr("Error"),
                                 QObject::tr("Failed to Modify\n"
                                             "Click cancel to exit."),QMessageBox::Cancel);
        qDebug() << "Error";
    }
}

void reclamation::on_reclamation_modifier_show_2_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void reclamation::on_reclamation_modifier_show_5_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
}

void reclamation::on_pushButton_6_clicked()
{
    QString research = ui->lineEdit->text();

    if(research == "")
        refresh();
    else
    {
        ui->tableView->setModel(Rtmp.researcher(research));
    }
}

void reclamation::on_reclamation_modifier_show_6_clicked()
{

    if(select_reclamation == -1)
        return;

    QString nom = ui->tableView->model()->index(select_reclamation,1).data().toString();
    QString cin = ui->tableView->model()->index(select_reclamation,2).data().toString();
    QString email = ui->tableView->model()->index(select_reclamation,3).data().toString();
    QString date = ui->tableView->model()->index(select_reclamation,4).data().toString();
    QString reclamation = ui->tableView->model()->index(select_reclamation,5).data().toString();

    QString pdfDir = QDir::currentPath() + "/pdf";
    QDir().mkpath(pdfDir);

    QString filePath = pdfDir + "/"+nom+".pdf";

    QPdfWriter writer(filePath);
    writer.setPageSizeMM(QSizeF(50, 50));

    QPainter painter(&writer);
    painter.scale(2, 2);

    QTextDocument doc;

    QString html =
    "<div align=right>"
       "Nom: "+nom+""
       "cin: "+cin+"<br>"
       "email: "+email+"<br>"
       "Date: "+date+"<br>"
       "reclamation: "+reclamation+"<br>"
    "</div>";

    doc.setHtml(html);
    doc.drawContents(&painter);

    QDesktopServices::openUrl(QUrl::fromLocalFile(filePath));
    select_reclamation = -1;
}

void reclamation::on_reclamation_modifier_show_4_clicked()
{
        QString userInput = ui->lineEdit_2->text();
        if (!userInput.isEmpty()) {
            // Append user input to conversation
            QString userMessage = "<div style=' border-radius: 10px;"
                                  "padding: 10px;'><strong>User:</strong> " +
                                  userInput + "</div>";
            ui->textEdit->append(userMessage);
            QJsonArray conversationJsonArray;
            QJsonObject messageJsonObject{
                {"role", "system"},
                {"content",
                 "You are an Assistant in an Ambulance Management System"}};
            conversationJsonArray.append(messageJsonObject);
            // Iterate over each line in the QTextEdit
            for (QString line : ui->textEdit->toPlainText().split("\n")) {
                line = line.trimmed();

                if (line.startsWith("User: ")) {
                    QString messageContent = line.mid(6); // Remove "User: " prefix
                    QJsonObject messageJsonObject{{"role", "user"},
                                                  {"content", messageContent}};
                    conversationJsonArray.append(messageJsonObject);
                } else if (line.startsWith("AI: ")) {
                    QString messageContent = line.mid(4); // Remove "AI: " prefix
                    QJsonObject messageJsonObject{{"role", "assistant"},
                                                  {"content", messageContent}};
                    conversationJsonArray.append(messageJsonObject);
                }
            }

            // Create JSON request
            QJsonObject request;
            request.insert("model", "gpt-3.5-turbo");
            request.insert("messages", conversationJsonArray);

            // Send request to OpenAI API
            QUrl url("https://api.openai.com/v1/chat/completions");
            QNetworkRequest req(url);
            req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
            req.setRawHeader(
                "Authorization",
                "Bearer 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");
            QNetworkAccessManager *manager = new QNetworkAccessManager(this);

            QNetworkReply *reply =
                manager->post(req, QJsonDocument(request).toJson());
            ui->reclamation_modifier_show_4->setEnabled(false);
            // Connect signals and slots
            connect(reply, &QNetworkReply::finished, this, [reply, this]() {
                if (reply->error() == QNetworkReply::NoError) {
                    // Parse response JSON
                    QJsonObject response =
                        QJsonDocument::fromJson(reply->readAll()).object();
                    QString text = response.value("choices")
                                       .toArray()
                                       .at(0)
                                       .toObject()
                                       .value("message")
                                       .toObject()
                                       .value("content")
                                       .toString();
                    // Append response to conversation
                    QString aiResponse = "<div style='background-color: #fff; "
                                         "border-radius: 10px; "
                                         "border: 1px solid #ccc; "
                                         "padding: 10px;'><strong>AI:</strong> " +
                                         text.trimmed().replace("\n\n", "<br>") +
                                         "</div>";
                    ui->textEdit->append("AI: " +
                                         text.trimmed().replace("\n\n", "\n"));
                    ui->reclamation_modifier_show_4->setEnabled(true);
                } else {
                    qDebug() << reply->errorString();
                }
                reply->deleteLater();
            });
        }

        // Clear user input field
        ui->lineEdit_2->clear();

}

void reclamation::on_reclamation_modifier_show_3_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void reclamation::on_reclamation_modifier_show_7_released()
{
    ui->stackedWidget_2->setCurrentIndex(2);

}
