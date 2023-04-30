#include "client.h"
#include "ui_client.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QSqlQueryModel>
#include<QObject>
#include <QPainter>
#include <QPdfWriter>
#include <QtPrintSupport/QPrintPreviewDialog>
#include <QFile>
#include <QDateTime>
#include <QTextStream>
#include <QPieSeries>
#include <QtCharts/QChartView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QColor>
#include"arduino.h"
#include<QNetworkRequest>
#include<QNetworkAccessManager>
#include<QNetworkReply>
#include<QAuthenticator>


client::client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::client)
{
    ui->setupUi(this);
    ui->cinc->setValidator(new QIntValidator(0,9999999,this));
    ui->phonec->setValidator(new QIntValidator(0,99999999,this));
    ui->tab_clients->setModel(c.afficherC());
    ui->comboBox_suppC->setModel(c.afficheroncomboc());
    int ret=A.connect_arduino(); // lancer la connexion à arduino
        switch(ret){
        case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
            break;
        case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
           break;
        case(-1):qDebug() << "arduino is not available";
        }
         QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_labelC())); // permet de lancer
         //le slot update_label suite à la reception du signal readyRead (reception des données).

}

client::~client()
{
    delete ui;
}

void client::on_pushButton_7_clicked()
{
    chatbox chatbox;
    chatbox.setModal(true);
    chatbox.exec();
}



void client::on_pb_ajouterC_clicked()
{

    int cinc=ui->cinc->text().toInt();
    QString nomc=ui->nomc->text();
    QString emailc=ui->emailc->text();
    QString adressec=ui->adressec->text();
    int phonec=ui->phonec->text().toInt();
    QString sexec=ui->sexec->text();

    clientc  c(cinc,nomc,emailc,adressec,phonec,sexec);
    if (cinc <= 0 )
                {
                    QMessageBox::critical(nullptr, QObject::tr("id vide"),
                                QObject::tr("Verifiez id !\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);

                }
                else if (nomc =="" || (ui->nomc->text().contains(QRegExp("[^a-zA-Z ]") )))
                {
                    QMessageBox::critical(nullptr, QObject::tr("nom vide ou incorrect"),
                                QObject::tr("Verifiez nom !\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);


                }
               else  if (emailc==""  )
                {
                    QMessageBox::critical(nullptr, QObject::tr("email vide"),
                                QObject::tr("Verifiez email !\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);

                }
                else if (adressec == "" )
                {
                    QMessageBox::critical(nullptr, QObject::tr("adresse vide"),
                                QObject::tr("Verifiez adresse !\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);

                }
                else if (phonec<= 0  )
                {
                    QMessageBox::critical(nullptr, QObject::tr("num tel vide"),
                                QObject::tr("Verifiez num !\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);

                }
                else if (sexec == "" || (ui->sexec->text().contains(QRegExp("[^a-zA-Z ]") )))
                {
                    QMessageBox::critical(nullptr, QObject::tr("femme ou homme"),
                                QObject::tr("Verifiez sexe !\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);

                }
    else{
    bool test=c.ajouterC();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Ajout effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_clients->setModel(c.afficherC());
        ui->comboBox_suppC->setModel(c.afficheroncomboc());
        c.writeLog(ui->cinc->text().toInt(),"A client has been added by cin : ");

}
    else
        QMessageBox::critical(nullptr, QObject::tr("not OK"),
                    QObject::tr("Ajout non effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }


}

void client::on_pb_suppc_clicked()
{
    clientc c;
    bool test=c.supprimerC(ui->comboBox_suppC->currentText().toInt());

    if(test)
    {
        c.writeLog(ui->comboBox_suppC->currentText().toInt(),"A client has been deleted by cin : ");
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Suppression effectuée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_clients->setModel(c.afficherC());
        ui->comboBox_suppC->setModel(c.afficheroncomboc());

}
    else
        QMessageBox::critical(nullptr, QObject::tr("not OK"),
                    QObject::tr("Suppression non effectuée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void client::on_pb_modififerC_clicked()
{
    int cinc=ui->cinc->text().toInt();
    QString nomc=ui->nomc->text();
    QString emailc=ui->emailc->text();
    QString adressec=ui->adressec->text();
    int phonec=ui->phonec->text().toInt();
    QString sexec=ui->sexec->text();

    clientc  c(cinc,nomc,emailc,adressec,phonec,sexec);

    if (cinc <= 0 )
                {
                    QMessageBox::critical(nullptr, QObject::tr("id vide"),
                                QObject::tr("Verifiez id !\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);

                }
                else if (nomc =="" || (ui->nomc->text().contains(QRegExp("[^a-zA-Z ]") )))
    {
        QMessageBox::critical(nullptr, QObject::tr("nom vide ou incorrect"),
                    QObject::tr("Verifiez nom !\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
               else  if (emailc==""  )
                {
                    QMessageBox::critical(nullptr, QObject::tr("email vide ou incorrect"),
                                QObject::tr("Verifiez email !\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);

                }
                else if (adressec == "" || (ui->emailc->text().lastIndexOf("@",-1)>ui->emailc->text().lastIndexOf(".",-1)) || ui->emailc->text().lastIndexOf("@",-1)==-1 || ui->emailc->text().lastIndexOf("@",-1)==-1)
                {
                    QMessageBox::critical(nullptr, QObject::tr("adresse vide ou incorrecte"),
                                QObject::tr("Verifiez adresse !\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);

                }
                else if (phonec<= 0  )
                {
                    QMessageBox::critical(nullptr, QObject::tr("num tel vide ou incorrect"),
                                QObject::tr("Verifiez num !\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);

                }
                else if (sexec == "" || (ui->nomc->text().contains(QRegExp("[^a-zA-Z ]") )))
                {
                    QMessageBox::critical(nullptr, QObject::tr("femme ou homme"),
                                QObject::tr("Verifiez sexe !\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);

                }
            else if (cinc==8 || cinc==100){
        QMessageBox::critical(nullptr, QObject::tr("probleme dans la bd"),
                    QObject::tr("CIN n'existe pas !\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else{
        c.Setcinc(cinc);
        c.Setnomc(nomc);
        c.Setemailc(emailc);
        c.Setphonec(phonec);
        c.Setadressec(adressec);
        c.Setsexec(sexec);

    bool test=c.modifierC();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Modification effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_clients->setModel(c.afficherC());
        ui->comboBox_suppC->setModel(c.afficheroncomboc());
        c.writeLog(ui->cinc->text().toInt(),"A client has been modified by cin : ");

}
    else
        QMessageBox::critical(nullptr, QObject::tr("not OK"),
                    QObject::tr("Modification non effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
}

void client::on_tab_clients_activated(const QModelIndex &index)
{
    QAbstractItemModel *model = ui->tab_clients->model();
    QModelIndexList selectedIndexes = ui->tab_clients->selectionModel()->selectedIndexes();
    int primaryKeyValue = model->data(model->index(selectedIndexes.at(0).row(), 0)).toInt();
    QSqlQuery query;
    query.prepare("select * from CLIENTS where cinc=?");
    query.bindValue(0,primaryKeyValue);
    query.exec();

    if (query.next())
    {
        ui->cinc->setText(query.value(0).toString());
        ui->nomc->setText(query.value(1).toString());
        ui->adressec->setText(query.value(3).toString());
        ui->emailc->setText(query.value(2).toString());
        ui->phonec->setText(query.value(4).toString());
        ui->sexec->setText(query.value(5).toString());
    }
}

void client::on_comboBox_suppC_currentIndexChanged(int index)
{
    ui->comboBox_suppC->currentText();
}

void client::on_comboBox_tri_currentIndexChanged(const QString &arg1)
{
    ui->comboBox_tri->currentText();
}

void client::on_pb_trierC_clicked()
{
    int cinc=ui->cinc->text().toInt();
    QString nomc=ui->nomc->text();
    QString emailc=ui->emailc->text();
    QString adressec=ui->adressec->text();
    int phonec=ui->phonec->text().toInt();
    QString sexec=ui->sexec->text();
    clientc  c(cinc,nomc,emailc,adressec,phonec,sexec);
    if(ui->comboBox_tri->currentText()=="par CIN"){
        ui->tab_clients->setModel(c.afficher_cinc());
    }
    else if (ui->comboBox_tri->currentText()=="par Nom"){

        ui->tab_clients->setModel(c.afficher_nomc());
    }
    else if (ui->comboBox_tri->currentText()=="par Adresse"){

        ui->tab_clients->setModel(c.afficher_adressec());
    }
    else ui->tab_clients->setModel(c.afficherC());

}

void client::on_rechercherC_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
        QSqlQuery   *query= new QSqlQuery();
        query->prepare("SELECT * FROM clients WHERE CINC  LIKE'"+arg1+"%' or NOMC  LIKE'"+arg1+"%' or adressec  LIKE'"+arg1+"%' or phonec LIKE'"+arg1+"%' ");
         query->exec();
         if (query->next()) {
         model->setQuery(*query);
         ui->tab_clients->setModel(model);
         }
         else {
             QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                             QObject::tr("NO MATCH FOUND !.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
             ui->rechercherC->clear();}
}

void client::on_pb_pdfC_clicked()
{
    QPdfWriter pdf("C:/Users/Rania/Desktop/2A3/qt/clientss.pdf");

              QPainter painter(&pdf);
              QImage image("C:/Users/Rania/Desktop/2A3/qt/signature.png");
              QString TT = QDateTime::currentDateTime().toString();
              int i = 4000;
                     painter.setPen(QColor("#5FACD3"));
                     painter.setFont(QFont("Courier New", 25));
                     painter.drawText(2800,1400,"Liste des Clients");
                     painter.setPen(Qt::black);
                     painter.setFont(QFont("Time New Roman", 15));
                     painter.drawRect(100,100,9400,2500);
                     painter.drawRect(100,3000,9400,500);
                     painter.setFont(QFont("Time New Roman", 9));
                     painter.drawText(400,3300,"CIN");
                     painter.drawText(1350,3300,"Nom");
                     painter.drawText(2200,3300,"Email");
                     painter.drawText(4500,3300,"Adresse");
                     painter.drawText(6200,3300,"Phone");
                     painter.drawText(7500,3300,"Sexe");

                     painter.drawRect(100,3000,9400,10000);

                     QSqlQuery query;
                     query.prepare("select * from clients");
                     query.exec();
                     while (query.next())
                     {
                         painter.drawText(400,i,query.value(0).toString());
                         painter.drawText(1350,i,query.value(1).toString());
                         painter.drawText(2200,i,query.value(2).toString());
                         painter.drawText(4500,i,query.value(3).toString());
                         painter.drawText(6400,i,query.value(4).toString());
                         painter.drawText(7500,i,query.value(5).toString());
                         painter.drawText(900,i,query.value(6).toString());

                        i = i + 350;
                     }
                     painter.setPen(Qt::black);
                     painter.setFont(QFont("Time New Roman", 9));
                     painter.drawText(7500,7700,"Signé par : SmartAMB");
                    // painter.drawImage(QRectF(0, 0, image.width(), image.height()), image, QRectF(0, 0, image.width(), image.height())); // Dessiner l'image sur le QPainter
                     QRectF imageRect(7800, pdf.height() - 5800, 688, 848); // Position et taille de la photo de la signature
                         painter.drawImage(imageRect, image, QRectF(0, 0, image.width(), image.height()));
                     painter.end(); // Terminer le dessin sur le QPainter
                     QMessageBox::information(this, QObject::tr("PDF Saved Successfuly!"),
                     QObject::tr("PDF Saved Successfuly!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
}

void client::on_pb_hisC_clicked()
{
    QString filename="C:/Users/Rania/Desktop/2A3/qt/historiques.txt";
        QFile file(filename);
        if(!file.exists()){
            qDebug() << "file doesnt exist "<<filename;
        }else{
            qDebug() << filename<<" file found...";
        }

        QString line;
        ui->history->clear();
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
            QTextStream stream(&file);
            while (!stream.atEnd()){
               line = stream.readLine();
                ui->history->setText(ui->history->toPlainText()+line+"\n");
                qDebug() << "linea: "<<line;
            }
        }
        file.close();
}

void client::on_pb_statC_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

            model->setQuery("SELECT sexec FROM clients WHERE  sexec='femme' ");
            float countC=model->rowCount();

            model->setQuery("SELECT  sexec FROM clients WHERE  sexec='homme' ");
            float countEC=model->rowCount();

            float total=countC+countEC;

                    QPieSeries *series = new QPieSeries();
                    series->append("femme",countC);
                    series->append("homme",countEC);

                    if (countC!=0)
                    {QPieSlice *slice = series->slices().at(0);
                        slice->setLabel("femme "+QString("%1%").arg(100*slice->percentage(),3,'f',1));
                        slice->setLabelVisible();
                        //slice->setPen(QPen(Qt::black));
                    }
                    if ( countEC!=0)
                    {

                        QPieSlice *slice1 = series->slices().at(1);

                        slice1->setLabel("homme "+QString("%1%").arg(100*slice1->percentage(),3,'f',1));
                        slice1->setLabelVisible();
                        //slice1->setBrush(QColor(Qt::cyan));
                    }

                    // Create the chart widget
                    QChart *chart = new QChart();

                    // Add data to chart with title
                    chart->addSeries(series);
                    chart->setTitle("Totale "+ QString::number(total));
                    chart->setAnimationOptions(QChart::SeriesAnimations);

                    // Used to display the chart
                    QChartView *chartView = new QChartView(chart);
                    chartView->setRenderHint(QPainter::Antialiasing);
                    chartView->resize(800,500);

                    chartView->setParent(ui->horizontalFrame);
                    chart->legend()->hide();
                    chartView->show();
}

void client::update_labelC()
{
    data=A.read_from_arduino();

    if(data=="1"){

        ui->etatardC->setText("ALERTE!!");
        ui->etatardC->setText("ALERTE!!");
        ui->etatardC->setText("ALERTE!!");
        ui->etatardC->setText("ALERTE!!");// si les données reçues de arduino via la liaison série sont égales à 1
    // alors afficher ON
        QString account_sid = "AC186682c6de28d2c2a16eef5c43cb45ae";
            QString auth_token = "838fb29fb0d1a3430e95d97565ba7bc4";
            QString from_number = "+16204104554"; // votre numéro Twilio
            QString to_number = "+21699646424"; // numéro de téléphone du destinataire
            QString message = "ALERTE! détection de gaz"; // message à envoyer
            QString picture_url = ""; // URL de l'image, si vous voulez en envoyer une
            bool verbose = true; // afficher les messages de débogage ou non
        sendSMS(account_sid, auth_token, message, from_number, to_number, picture_url, verbose);


}else if (data == "0")
  ui->etatardC->setText("Normal");   // si les données reçues de arduino via la liaison série sont égales à 0
     //alors afficher ON
}



void client::on_pb_ONC_clicked()
{
    A.write_to_arduino("1"); //envoyer 1 à arduino
}


void client::on_pb_OFFC_clicked()
{
    A.write_to_arduino("0");
}

void client::sendSMS(QString account_sid, QString auth_token, QString message, QString from_number, QString to_number, QString picture_url, bool verbose)
{
    if (account_sid.isEmpty() || auth_token.isEmpty() || message.isEmpty() || from_number.isEmpty() || to_number.isEmpty()) {
           qDebug() << "You didn't include all necessary inputs!";
           qDebug() << "Call using -h for help.";
           return;
       }

       QUrl url("https://api.twilio.com/2010-04-01/Accounts/AC186682c6de28d2c2a16eef5c43cb45ae/Messages.json");
       QNetworkRequest request(url);
       QByteArray auth = QString("%1:%2").arg(account_sid, auth_token).toLocal8Bit().toBase64();
       request.setRawHeader("Authorization", "Basic " + auth);
       request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

       QUrlQuery params;
       params.addQueryItem("From", from_number);
       params.addQueryItem("To", to_number);
       params.addQueryItem("Body", message);
       if (!picture_url.isEmpty()) {
           params.addQueryItem("MediaUrl", picture_url);
       }

       QNetworkAccessManager *manager = new QNetworkAccessManager(this);
       QNetworkReply *reply = manager->post(request, params.toString(QUrl::FullyEncoded).toUtf8());

       QObject::connect(reply, &QNetworkReply::finished, [=](){
           QString response = QString(reply->readAll());
           if (reply->error() != QNetworkReply::NoError) {
               qDebug() << "Message send failed.";
               if (verbose && !response.isEmpty()) {
                   qDebug() << "Response:" << response;
               }
           } else {
               if (verbose) {
                   qDebug() << "SMS sent successfully!";
                   qDebug() << "Response:" << response;
               }
           }
           reply->deleteLater();
           manager->deleteLater();
       });

       QObject::connect(manager, &QNetworkAccessManager::authenticationRequired, [&](QNetworkReply *reply, QAuthenticator *authenticator){
           Q_UNUSED(reply);
           authenticator->setUser(account_sid);
           authenticator->setPassword(auth_token);
       });
}
