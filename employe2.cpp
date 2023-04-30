#include "employe2.h"
#include "ui_employe2.h"
#include "mainwindow.h"
//#include "ui_mainwindow.h"
#include "employe2c.h"
#include <QMessageBox>
#include<QIntValidator>
#include <QtPrintSupport/QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include <QDate>
#include<QFileDialog>
#include <QTextDocument>
#include <QTextStream>
#include<QFile>
#include <QSslSocket>
#include <QAbstractSocket>
#include"login2.h"
#include "notification.h"
#include <QSqlQueryModel>
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QThread>
#include"arduinoe.h"

employe2::employe2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::employe2)
{
    ui->setupUi(this);
    ui->le_cin->setValidator(new QIntValidator(0,9999999,this));
    ui->tab_employe->setModel(E.afficher());
      ui->comboBox_SUPP->setModel(E.afficherencomboemploye());
       ui->comboBox_SUPP->clear();
       //ui->comboBoxtri->setModel(E.afficher());
       ui->comboBoxtri->addItem("par salaire");
       ui->comboBoxtri->addItem("par id");
        ui->comboBoxtri->addItem("par nom");
    int ret = A.connect_arduino();

    switch (ret) {
    case 0:
        qDebug()<<"Ard available and connected"
               <<A.getarduino_port_name();
        break;
    case 1:
        qDebug()<<"Ard available but not connected"
               <<A.getarduino_port_name();
        break;
    case 2:
        qDebug()<<"Ard failed";
        break;
    }
    connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(checkSeriel()));

    QTimer *timer = new QTimer(this);
   QObject::connect(timer, &QTimer::timeout, [this]() {
      // check for changes to the database
      QSqlQuery query;
      query.prepare("SELECT etap FROM Moteur");
          if (query.exec() && query.next()) {
              int etap = query.value(0).toInt();
        if(etap == 1)
        {
            QByteArray byteArray;
            byteArray.append("1");
            A.write_to_arduino(byteArray);
            E.modifierEtapDuMoteur(0);
        }else{

            QByteArray byteArray;
            ui->label_2->setText("OFF");
            ui->label_2->setStyleSheet("color: red; ");
            byteArray.append("0");
            A.write_to_arduino(byteArray);
        }
          }
   });
   timer->start(5000);
}

employe2::~employe2()
{
    delete ui;
}
void employe2::checkSeriel()
{
    QByteArray data = A.read_from_arduino();
    QString buffer = QString::fromLatin1(data);
    bool hasTwo = false;

   for (int i = 0; i < buffer.length(); i++) {
      if (buffer[i] == '2') {
         hasTwo = true;
         break;
      }
   }
   if (hasTwo) {
         qDebug() << "Detected.";
         E.modifierEtapDuMoteur(1);

         ui->label_2->setText("ON");
         ui->label_2->setStyleSheet("color: green; ");
   }
}

void  employe2::on_pb_ajouter_clicked()
{
    Employe E2;
    notification N;
    QString CINE_string = ui->le_cin->text();
    QString NOME = ui->le_nom->text().trimmed(); // trim pour enlever les espaces de debut  fin
    QString PRENOME = ui->le_prenom->text().trimmed(); // trim pour enlever les espaces de debut  fin
    QString SALAIRE_string = ui->le_salaire->text();
    QString METIER = ui->le_metier->text().trimmed(); // trim pour enlever les espaces de debut et fin


    bool cin_ok;
    int CINE = CINE_string.toInt(&cin_ok);
    if (!cin_ok) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Le CIN doit être un nombre entier valide"),
                              QMessageBox::Cancel);
        return;
    }


    bool salaire_ok;
    double SALAIRE = SALAIRE_string.toDouble(&salaire_ok);
    if (!salaire_ok) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Le salaire doit être un nombre valide"),
                              QMessageBox::Cancel);
        return;
    }


    QRegExp lettre_regex("^[a-zA-Z]+$"); // une expression régulière pour des lettres uniquement
    if (NOME.isEmpty() || PRENOME.isEmpty()) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Le nom et le prénom ne peuvent pas être vides"),
                              QMessageBox::Cancel);
        return;
    } else if (!lettre_regex.exactMatch(NOME) || !lettre_regex.exactMatch(PRENOME)) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Le nom et le prénom ne peuvent contenir que des lettres"),
                              QMessageBox::Cancel);
        return;
    }


    if (METIER.isEmpty()) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Le champ du métier ne peut pas être vide"),
                              QMessageBox::Cancel);
        return;
    }

    Employe E(CINE, NOME, SALAIRE, METIER, PRENOME);



    bool success = E.ajouter();
    if (success) {
        N.notification_ajouteremploye();
        QMessageBox::information(nullptr, QObject::tr("ok"),
                    QObject::tr("ajout effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

        //qDebug() << "Data added successfully!";
        ui->tab_employe->setModel(E.afficher())   ;
         ui->comboBox_SUPP->setModel(E2.afficherencomboemploye());


    } else {
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr("ajout non effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        //qDebug() << "Error: Unable to add data.";
    }
}



void  employe2::on_pb_supprimer_clicked()
{
     notification N;

    /*Employe E1; E1.setCINE(ui->le_cin->text().toInt());
    bool test=E1.supprimer(E1.getCINE());
    if (test) {
        N.notification_supprimeremploye();
        QMessageBox::information(nullptr, QObject::tr("ok "),
                    QObject::tr("suppression avec succes.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_employe->setModel(E1.afficher());

    } else {
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                    QObject::tr("echec de suppression.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }*/
     Employe E2;
     bool test=E2.supprimer(ui->comboBox_SUPP->currentText().toInt());
     if (test)
     {ui->tab_employe->setModel(E2.afficher());
         N.notification_supprimeremploye();
         QMessageBox::information(nullptr, QObject::tr("ok "),
                     QObject::tr("suppression avec succes.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
         ui->comboBox_SUPP->setModel(E2.afficherencomboemploye());}
         else
         {
                QMessageBox::critical(nullptr, QObject::tr("not ok"),
                            QObject::tr("echec de suppression.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
            }
}




void employe2::on_button_modifier_clicked()
{
     notification N;
     Employe E2;
    int CINE=ui->le_cin->text().toInt();
    QString NOME=ui->le_nom->text();
    QString PRENOME=ui->le_prenom->text();
    int SALAIRE=ui->le_salaire->text().toInt();
    QString METIER=ui->le_metier->text();

 Employe E(CINE,NOME,SALAIRE,METIER,PRENOME);

      bool test=E.modifier() ;

        QMessageBox msgBox;

        if(test)
           {
            N.notification_modifieremploye();
            msgBox.setText("Modification avec succes.");
          ui->tab_employe->setModel(E.afficher()) ;
             ui->comboBox_SUPP->setModel(E2.afficherencomboemploye());
           }
        else
            msgBox.setText("Echec de Modification.!!!");
            msgBox.exec();
}









void employe2::on_pdf_button_clicked()
{
    QString strStream;
            strStream = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
                if (QFileInfo(strStream).suffix().isEmpty())
                    { strStream.append(".pdf"); }

                QPrinter printer(QPrinter::PrinterResolution);
                printer.setOutputFormat(QPrinter::PdfFormat);
                printer.setPaperSize(QPrinter::A4);
                printer.setOutputFileName(strStream);

                      QTextStream out(&strStream);

                      const int rowCount = ui->tab_employe->model()->rowCount();
                      const int columnCount = ui->tab_employe->model()->columnCount();
                      QString TT = QDateTime::currentDateTime().toString();
                      out <<"<html>\n"
                            "<head>\n"
                             "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                          << "<title>ERP - COMmANDE LIST<title>\n "
                          << "</head>\n"
                          "<body bgcolor=#ffffff link=#5000A0>\n"
                             "<h1 style=\"text-align: center;\"><strong> "+TT+"</strong></h1>"
                            +"<img src=C:\\Users\\USER\\Pictures\\Saved Pictures />" //path
                          "<h1 style=\"text-align: center;\"><strong> *****LISTE DES EMPLOYE ***** </strong></h1>"

                          "<table style=\"text-align: center; font-size: 10px;\" border=1>\n "
                            "</br> </br>";
                      // headers
                      out << "<thead><tr bgcolor=#d6e5ff>";
                      for (int column = 0; column < columnCount; column++)
                          if (!ui->tab_employe->isColumnHidden(column))
                              out << QString("<th>%1</th>").arg(ui->tab_employe->model()->headerData(column, Qt::Horizontal).toString());
                      out << "</tr></thead>\n";

                      // data table
                      for (int row = 0; row < rowCount; row++) {
                          out << "<tr>";
                          for (int column = 0; column < columnCount; column++)
                        {
                              if (!ui->tab_employe->isColumnHidden(column)) {
                                  QString data =ui->tab_employe->model()->data(ui->tab_employe->model()->index(row, column)).toString().simplified();
                                  out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;")); //pas compriis
                              }
                          }
                          out << "</tr>\n";
                      }
                      out <<  "</table>\n"
                          "</body>\n"
                          "</html>\n";

                      QTextDocument document;
                      document.setHtml(strStream);
                      document.print(&printer);

        }


/*void MainWindow::on_recherch_button_clicked()
{


    int CINE=(ui->line->text().toInt());
          ui->tab_employe->setModel(E.rechercheC(CINE));
}*/



void employe2::on_login2_clicked()
{
    login2 *Login = new login2(this);
    Login->setModal(true);
    Login->exec();
    hide();

}

void employe2::on_line_textChanged(const QString &arg1)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery();
    query->prepare("SELECT * FROM employe WHERE CINE LIKE '"+arg1+ "%' or NOME LIKE '"+arg1+"%' or SALAIRE LIKE '"+arg1+"%' or METIER LIKE '"+arg1+"%' or PRENOME LIKE '"+arg1+"%' ");
     query->exec();
     if (query->next()){
    model->setQuery(*query);
        ui->tab_employe->setModel(model);
    }

    else {
        QMessageBox::critical(nullptr, QObject::tr("RECHERCHE"), QObject::tr("AUCUN RÉSULTAT TROUVÉ !\nCliquez sur Annuler pour quitter."), QMessageBox::Cancel);
        ui->line->clear();
    }
}

void employe2::on_stat_clicked()
{
    // Création du modèle de requête SQL
    QSqlQueryModel *model = new QSqlQueryModel();

    // Requête pour compter le nombre d'employés dont le salaire est supérieur à 1000
    model->setQuery("SELECT salaire FROM employe WHERE salaire > 1000");
    int countHautSalaire = model->rowCount();

    // Requête pour compter le nombre d'employés dont le salaire est inférieur ou égal à 1000
    model->setQuery("SELECT salaire FROM employe WHERE salaire <= 1000");
    int countBasSalaire = model->rowCount();

    // Calcul du total des deux nombres
    int total = countHautSalaire + countBasSalaire;

    // Création d'un QPieSeries pour représenter les données
    QPieSeries *series = new QPieSeries();
    series->append("Salaire > 1000", countHautSalaire);
    series->append("Salaire <= 1000", countBasSalaire);

    // Ajout de l'étiquette pour la tranche "Salaire > 1000"
    if (countHautSalaire != 0)
    {
        QPieSlice *sliceHautSalaire = series->slices().at(0);
        sliceHautSalaire->setLabel("Salaire > 1000 " + QString("%1%").arg(100 * sliceHautSalaire->percentage(), 3, 'f', 1));
        sliceHautSalaire->setLabelVisible();
        sliceHautSalaire->setPen(QPen(Qt::black));
    }

    // Ajout de l'étiquette pour la tranche "Salaire <= 1000"
    if (countBasSalaire != 0)
    {
        QPieSlice *sliceBasSalaire = series->slices().at(1);
           sliceBasSalaire->setLabel("Bas salaire " + QString("%1%").arg(100 * sliceBasSalaire->percentage(), 3, 'f', 1));
           sliceBasSalaire->setLabelVisible();
           sliceBasSalaire->setBrush(QColor(Qt::cyan));
    }

    // Création du graphique
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Total: " + QString::number(total));
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // Création de la vue du graphique et affichage dans le widget parent
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    //chartView->setParent(ui->tab_employe);
    chartView->resize(1000, 500);
    chart->legend()->hide();
    chartView->show();

}

void employe2::on_comboBox_SUPP_currentIndexChanged(int CINE)
{
    ui->comboBox_SUPP->currentText();


}


void employe2::on_comboBoxtri_currentIndexChanged(const QString &arg1)
{
   ui->comboBoxtri->currentText();
}

void employe2::on_pushButtontri_clicked()
{


    int CINE=ui->le_cin->text().toInt();
        QString NOME=ui->le_nom->text();
        QString PRENOME=ui->le_prenom->text();
        int SALAIRE=ui->le_salaire->text().toInt();
        QString METIER=ui->le_metier->text();

        Employe E(CINE,NOME,SALAIRE,METIER,PRENOME);

        if(ui->comboBoxtri->currentText() == "par id") {
            ui->tab_employe->setModel(E.afficherparcin());
        }
        else if(ui->comboBoxtri->currentText() == "par nom") {
            ui->tab_employe->setModel(E.afficherparnom());
        }

        else if(ui->comboBoxtri->currentText() == "par salaire") {
            ui->tab_employe->setModel(E.afficherparsaliare());
        }
        else {
            ui->tab_employe->setModel(E.afficher());}
}




