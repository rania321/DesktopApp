#include "ambulancei.h"
#include "ui_ambulancei.h"
#include"calendrier.h"
#include"ambulancec.h"
#include"exportexcelobject.h"
#include <QApplication>
#include <QMessageBox>
#include<QDebug>
#include<QIntValidator>
#include <QSqlQuery>
#include <QFileDialog>
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QColor>
#include <QPrinter>






AmbulanceI::AmbulanceI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AmbulanceI)
{
    ui->setupUi(this);
  // ui->le_mat->setValidator(new QIntValidator(0, 9999999, this));
    ui->le_prix->setValidator(new QDoubleValidator(0.0, 1000000.0, 2, this));//MIN 0,MAX 1000000 , 2 décimales

    QString matricul_pattern = "^[A-Z]{2}\\d{4}$"; // Expression régulière pour l'immatriculation
    QRegExp matricul_regex(matricul_pattern); // Créer une expression régulière à partir du pattern
    QValidator *immatriculation_validator = new QRegExpValidator(matricul_regex, this); // Créer un validateur à partir de l'expression régulière
    ui->le_mat->setValidator(immatriculation_validator); // Appliquer le validateur au champ d'édition de l'immatriculation

    ui->tabamb->setModel(A.afficher());
    ui->comboBox_suppamb->setModel(A.afficheroncombomat());

    int ret=Ar.connect_arduino(); // lancer la connexion à arduino
            switch(ret){
            case(0):qDebug()<< "arduino is available and connected to : "<< Ar.getarduino_port_name();
                break;
            case(1):qDebug() << "arduino is available but not connected to :" <<Ar.getarduino_port_name();
               break;
            case(-1):qDebug() << "arduino is not available";
            }
             QObject::connect(Ar.getserial(),SIGNAL(readyRead()),this,SLOT(update_labelA())); // permet de lancer
             //le slot update_label suite à la reception du signal readyRead (reception des données).


}

AmbulanceI::~AmbulanceI()
{
    delete ui;
}

void AmbulanceI::on_pushButton_7_clicked()
{
    calendrier calendrier;
    calendrier.setModal(true);
    calendrier.exec();
}

void AmbulanceI::on_pb_ajout_clicked()
{
    QString mat=ui->le_mat->text();
    double prix=ui->le_prix->text().toDouble();
    QString etat=ui->le_etat->text();
    QString date=ui->le_date->text();
     AmbulanceC A(mat,prix,etat,date);
     bool test=A.ajouter();
     QMessageBox msgBox;
     if(test)

       { msgBox.setText("Ajout avec succes");
        ui->tabamb->setModel(A.afficher());
        ui->comboBox_suppamb->setModel(A.afficheroncombomat());

     }
     else
         msgBox.setText("Echec d'ajout");
         msgBox.exec();
     }

void AmbulanceI::on_pb_supp_clicked()
{
 AmbulanceC A1;
 bool test=A1.supprimer(ui->comboBox_suppamb->currentText());
 if (test)
 {ui->tabamb->setModel(A.afficher());
     QMessageBox::information(nullptr,QObject::tr("ok"),
                              QObject::tr("suppression successful.\n"),
     QMessageBox::Cancel);
     ui->comboBox_suppamb->setModel(A.afficheroncombomat());
 }
 QMessageBox::critical(nullptr,QObject::tr("supprimer not open"),
                       QObject::tr("click cancel to exist"),
                       QMessageBox::Cancel);







    /*  AmbulanceC A1; A1.setmat(ui->le_supp->text());
    bool test=A1.supprimer(A1.getmat());
    QMessageBox msgBox;
    if(test)

     {  msgBox.setText("suppression avec succes");
    ui->tabamb->setModel(A.afficher());
    ui->comboBox_suppamb->setModel(A.afficheroncombomat());
    }


    else
        msgBox.setText("Echec de suppression");
        msgBox.exec();*/
    }
void AmbulanceI::on_comboBox_suppamb_currentIndexChanged(int index)
{
ui->comboBox_suppamb->currentText();
}





void AmbulanceI::on_pb_modif_clicked()
{
    QString mat=ui->le_mat->text();
    double prix=ui->le_prix->text().toDouble();
    QString etat=ui->le_etat->text();
    QString date=ui->le_date->text();

     AmbulanceC A(mat,prix,etat,date);

     bool test=A.modifier();

     if(test)
    {
       QMessageBox::information(nullptr,QObject::tr("ok"),
                                QObject::tr("modification effectué.\n"
                                            "clic cancel to exit."),QMessageBox::Cancel);
     ui->tabamb->setModel(A.afficher());
     ui->comboBox_suppamb->setModel(A.afficheroncombomat());
    }
     else
     QMessageBox::critical(nullptr,QObject::tr("not OK"),
                          QObject::tr("modification non effectué.\n"
                                      "click cancel to exit."),QMessageBox::Cancel);




     }

void AmbulanceI::on_tabamb_activated(const QModelIndex &index)
{
    QAbstractItemModel *model = ui->tabamb->model();
    QModelIndexList selectedIndexes= ui->tabamb->selectionModel()->selectedIndexes();
    QString primaryKeyValue = model->data(model->index(selectedIndexes.at(0).row(),0)).toString();
    QSqlQuery query;
    query.prepare("select * from ambulances where MATAMB=?");
    query.bindValue(0,primaryKeyValue);
    query.exec();
    if (query.next())
    {
        ui->le_mat->setText(query.value(0).toString());
        ui->le_prix->setText(query.value(1).toString());
        ui->le_etat->setText(query.value(2).toString());
        ui->le_date->setDate(query.value(3).toDate());

}
}




void AmbulanceI::on_recherche_textChanged(const QString &arg1)
{ QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery *query=new QSqlQuery();

    query->prepare("SELECT * FROM ambulances WHERE MATAMB like'"+arg1+"%' or PRIXAMB like '"+arg1+"%' or ETATAMB like '"+arg1+"%' or DATE_ENT_AMB like '"+arg1+"%'");
    query->exec();
    if(query->next()){
        model->setQuery(*query);
        ui->tabamb->setModel(model);

    }
   /* else
           {QMessageBox::critical(nullptr,QObject::tr("SEARCH"),
                               QObject::tr("NO MATCH FOUND!\n"
                                           "Click cancel to exit."),QMessageBox::Cancel);
                ui->recherche->clear();}*/

}







void AmbulanceI::on_pb_excel_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                    tr("Excel Files (*.xls)"));
    if (fileName.isEmpty())
        return;

    ExportExcelObject obj(fileName, "ambulances", ui->tabamb);

    //colums to export
    obj.addField(0, "matriculeAMB", "char(10)");
    obj.addField(1, "prixAMB", "char(20)");
    obj.addField(2, "etatAMB", "char(20)");
    obj.addField(3, "dateAMB", "char(20)");




    int retVal = obj.export2Excel();
    if( retVal > 0)
    {
        QMessageBox::information(this, tr("Done"),
                                 QString(tr("%1 records exported!")).arg(retVal)
                                 );
    }
}


void AmbulanceI::on_pushButton_8_clicked()
{

}

void AmbulanceI::on_stat_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

                model->setQuery("SELECT ETATAMB FROM ambulances WHERE  ETATAMB='EN BONNE ETAT' ");
                float countC=model->rowCount();

                model->setQuery("SELECT  ETATAMB FROM ambulances WHERE  ETATAMB='EN PANNE' ");
                float countEC=model->rowCount();

                float total=countC+countEC;

                        QPieSeries *series = new QPieSeries();
                        series->append("EN BONNE ETAT",countC);
                        series->append("EN BONNE ETAT",countEC);

                        if (countC!=0)
                        {QPieSlice *slice = series->slices().at(0);
                            slice->setLabel("EN BONNE ETAT "+QString("%1%").arg(100*slice->percentage(),3,'f',1));
                            slice->setLabelVisible();
                            slice->setPen(QPen(Qt::black));
                        }
                        if ( countEC!=0)
                        {

                            QPieSlice *slice1 = series->slices().at(1);

                            slice1->setLabel("EN PANNE "+QString("%1%").arg(100*slice1->percentage(),3,'f',1));
                            slice1->setLabelVisible();
                            slice1->setBrush(QColor(Qt::cyan));
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
                        chartView->resize(400,200);

                        chartView->setParent(ui->frame);
                        chart->legend()->hide();
                        chartView->show();


}

void AmbulanceI::on_comboBox_tri_ambu_currentIndexChanged(const QString &arg1)
{
    ui->comboBox_tri_ambu->currentText();
}

void AmbulanceI::on_pb_trierA_clicked()
{
    QString mat=ui->le_mat->text();
    double prix=ui->le_prix->text().toDouble();
    QString etat=ui->le_etat->text();
    QString date=ui->le_date->text();
    AmbulanceC A(mat,prix,etat,date);

    if (ui->comboBox_tri_ambu->currentText()=="Matricule"){
        ui->tabamb->setModel(A.affichermat());
    }
    else if (ui->comboBox_tri_ambu->currentText()=="Etat"){
        ui->tabamb->setModel(A.afficheretat());
    }
    else if(ui->comboBox_tri_ambu->currentText()=="Prix"){
        ui->tabamb->setModel(A.afficherprix());
    }
    else ui->tabamb->setModel(A.afficher());


}

void AmbulanceI::on_pb_pfdA_clicked()
{

  QString strStream;
    strStream = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(strStream).suffix().isEmpty()) {
        strStream.append(".pdf");
    }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(strStream);

    QTextStream out(&strStream);

    const int rowCount = ui->tabamb->model()->rowCount();
    const int columnCount = ui->tabamb->model()->columnCount();

    out << "<html>\n"
            "<head>\n"
            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
            "<title>LISTE AMBULANCES<title>\n"
            "</head>\n"
            "<body bgcolor=#ffffff link=#5000A0>\n"
            "<h1 style=\"text-align: center;\"><strong> LISTE AMBULANCES </strong></h1>"
            "<table style=\"text-align: center; font-size: 10px;\" border=1>\n ";

    // headers
    out << "<thead><tr bgcolor=#d6e5ff>";
    for (int column = 0; column < columnCount; column++) {
        if (!ui->tabamb->isColumnHidden(column)) {
            out << QString("<th>%1</th>").arg(ui->tabamb->model()->headerData(column, Qt::Horizontal).toString());
        }
    }
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tabamb->isColumnHidden(column)) {
                QString data = ui->tabamb->model()->data(ui->tabamb->model()->index(row, column)).toString().simplified();
                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
        }
        out << "</tr>\n";
    }
    out << "</table>\n"
            "<div style=\"position:absolute; bottom:0; right:0; width:30%; height:30%;\">"
            "<img src=\"C:/Users/Rania/Pictures/logo.png\" width=\"100%\" height=\"100%\"></div>"
            "</body>\n"
            "</html>\n";

    QTextDocument document;
    document.setHtml(strStream);
    document.print(&printer);
}



void AmbulanceI:: update_labelA()
{
    data=Ar.read_from_arduino();

    if(data=="1"){

        ui->etatardA->setText("ALERTE!!");
        ui->etatardA->setText("ALERTE!!");
        ui->etatardA->setText("ALERTE!!");
        ui->etatardA->setText("ALERTE!!");// si les données reçues de arduino via la liaison série sont égales à 1
    // alors afficher ON
        QSqlQuery query;
            query.prepare("INSERT INTO GAZ (DETECT, DATEG) VALUES (:DETECT, :DATEG)");
            query.bindValue(":DETECT", "DETECTION");
            query.bindValue(":DATEG", QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
            query.exec();


}else if (data == "0")
  ui->etatardA->setText("Normal");   // si les données reçues de arduino via la liaison série sont égales à 0
     //alors afficher ON
}



void AmbulanceI::on_pb_ONA_clicked()
{
    Ar.write_to_arduino("1");//envoyer 1 a ard
}

void AmbulanceI::on_pb_OFFA_clicked()
{
       Ar.write_to_arduino("0");
}

void AmbulanceI::on_pb_gazA_clicked()
{
    AmbulanceC A;
    ui->tab_gazA->setModel(A.afficherGazA());
}
