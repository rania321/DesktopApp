#include "materielm.h"
#include "ui_materielm.h"
#include <QMessageBox>
#include<QSystemTrayIcon>
#include <QRegExp>
#include "connection.h"
#include <QFileDialog>
#include <QComboBox>
#include <QPieSeries>
#include <QtCharts/QChartView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QColor>
//#include "qrcode.h"
#include <QtSvg/QSvgRenderer>
#include <fstream>
#include "QPainter"
#include <QDirModel>
#include <QWidget>


#include <QPixmap>
#include<QDirModel>
#include "qrcode.h"
#include <QtSvg/QSvgRenderer>
#include <fstream>
#include<QRegularExpression>


#include <QSystemTrayIcon>



using qrcodegen::QrCode;
using qrcodegen::QrSegment;


materielm::materielm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::materielm)
{
    ui->setupUi(this);
    QRegExp rx("[a-zA-Z]+");
        QValidator *validator = new
                QRegExpValidator (rx,this);
        ui->nomm->setValidator(validator);
        ui->dispom->setValidator(validator);
    ui->tab_mat->setModel(m.afficherm());
    ui->comboBox_supp->setModel(m.affichercheroncomboc());
}

materielm::~materielm()
{
    delete ui;
}
void materielm::on_pb_ajouterm_clicked(){
    Materiel m(ui->idm->text().toInt(),ui->nomm->text(),ui->prixm->text().toInt(),ui->dispom->text());

    bool test= m.ajouterm();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Ajout effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
         ui->tab_mat->setModel(m.afficherm());
         ui->comboBox_supp->setModel(m.affichercheroncomboc());


}
    else
        QMessageBox::critical(nullptr, QObject::tr("not OK"),
                    QObject::tr("Ajout non effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}
/*QString dispom=ui->dispom->text();
if (dispom!= "OUI" || dispom!="NON" )
                {
                    QMessageBox::critical(nullptr, QObject::tr("erreur dispo"),
                                QObject::tr("Valeur dispo : OUI ou NON !\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);

                }*/

void materielm::on_pb_suppm_clicked()
{
    Materiel m1;

    bool test=m1.supprimerm(ui->comboBox_supp->currentText().toInt());
    if (test)
    {
     ui->tab_mat->setModel(m.afficherm());
     QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("suppression successful.\n"),QMessageBox::Cancel);
     ui->comboBox_supp->setModel(m.affichercheroncomboc());
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("supprimer npot open"),QObject::tr("click cancel to exist"),QMessageBox::Cancel);
    }
        //m1.setidmat(ui->idmat_suppm->text().toInt());
        //bool test=m.supprimerm(m1.getidmat());
        //if(test)
        //{
           // QMessageBox::information(nullptr, QObject::tr("OK"),
              //          QObject::tr("Suppression effectuée.\n"
                                  //  "Click Cancel to exit."), QMessageBox::Cancel);
            //ui->tab_mat->setModel(m.afficherm());
            //ui->comboBox_supp->setModel(m.affichercheroncomboc());

    //}
      //  else
        //    QMessageBox::critical(nullptr, QObject::tr("not OK"),
          //              QObject::tr("Suppression non effectuée.\n"
            //                        "Click Cancel to exit."), QMessageBox::Cancel);


void materielm::on_pushButton_2_clicked()
{

    bool    test=m.modifierm(ui->idm->text().toInt(),ui->prixm->text().toInt(),ui->nomm->text(),ui->dispom->text()) ;
          if (test)
          {
                  ui->tab_mat->setModel(m.afficherm());
ui->comboBox_supp->setModel(m.affichercheroncomboc());              QMessageBox::information(nullptr,QObject::tr("OK"),
                                   QObject::tr("modification établie"),
                                   QMessageBox::Ok);}
          else{
          QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                                  QObject::tr("modification non établie"),
                                  QMessageBox::Cancel);

}
}

void materielm::on_comboBox_trimat_currentTextChanged(  const QString &arg1)
{
   ui->comboBox_trimat->currentText();
}

void materielm::on_pushButton_trimat_clicked()
{
    /*int idmat=ui->idm->text().toInt();
        QString nommat=ui->nomm->text();
        int prixmat=ui->prixm->text().toInt();
          QString dispomat=ui->dispom->text();
        Materiel m (idmat,nommat,prixmat,dispomat);
        if(ui->comboBox_trimat->currentText()=="par id"){
            ui->tab_mat->setModel(m.afficher_idmat());

        }
        else if (ui->comboBox_trimat->currentText()=="par nom"){

            ui->tab_mat->setModel(m.afficher_nommat());
        }
        else if (ui->comboBox_trimat->currentText()=="par prix"){

            ui->tab_mat->setModel(m.afficher_prixmat());

        }
        else ui->tab_mat->setModel(m.afficherm());
*/


    if(ui->asc->isChecked())
    {
       ui->tab_mat->setModel(m.tri(ui->comboBox_trimat->currentText(),"asc"));
    }
    if(ui->desc->isChecked())
    {
        ui->tab_mat->setModel(m.tri(ui->comboBox_trimat->currentText(),"desc"));

    }

}

void materielm::on_rechercherm_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
            QSqlQuery   *query= new QSqlQuery();
            query->prepare("SELECT * FROM Materiel WHERE idmat  LIKE'"+arg1+"%' or nommat  LIKE'"+arg1+"%' or dispomat  LIKE'"+arg1+"%' or prixmat LIKE'"+arg1+"%' ");
             query->exec();
             if (query->next()) {
             model->setQuery(*query);
             ui->tab_mat->setModel(model);
             }
             else {
                 QMessageBox::critical(nullptr, QObject::tr("SEARCH"),
                                 QObject::tr("NO MATCH FOUND !.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
                 ui->rechercherm->clear();
             }
}

void materielm::on_tab_mat_activated(const QModelIndex &index)
{
    QAbstractItemModel *model = ui->tab_mat->model();
        QModelIndexList selectedIndexes = ui->tab_mat->selectionModel()->selectedIndexes();
        int primaryKeyValue = model->data(model->index(selectedIndexes.at(0).row(), 0)).toInt();
        QSqlQuery query;
        query.prepare("select * from Materiel where idmat=?");
        query.bindValue(0,primaryKeyValue);
        query.exec();

        if (query.next())
        {
            ui->idm->setText(query.value(0).toString());
            ui->nomm->setText(query.value(1).toString());
            ui->prixm->setText(query.value(2).toString());
            ui->dispom->setText(query.value(3).toString());

        }
}

void materielm::on_pb_statm_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();

                model->setQuery("SELECT dispomat FROM Materiel WHERE  dispomat='oui' ");
                float countC=model->rowCount();

                model->setQuery("SELECT  dispomat FROM Materiel WHERE  dispomat='non' ");
                float countEC=model->rowCount();

                float total=countC+countEC;

                        QPieSeries *series = new QPieSeries();
                        series->append("oui",countC);
                        series->append("non",countEC);

                        if (countC!=0)
                        {QPieSlice *slice = series->slices().at(0);
                            slice->setLabel("oui "+QString("%1%").arg(100*slice->percentage(),3,'f',1));
                            slice->setLabelVisible();
                            //slice->setPen(QPen(Qt::black));
                        }
                        if ( countEC!=0)
                        {
                            QPieSlice *slice1 = series->slices().at(1);
                            slice1->setLabel("non "+QString("%1%").arg(100*slice1->percentage(),3,'f',1));
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
                        chartView->resize(400,200);

                        chartView->setParent(ui->horizontalFrame);
                        chart->legend()->hide();
                        chartView->show();
}

void materielm::on_pb_pdfm_clicked()
{
    QPdfWriter pdf("C:/Users/msi/Desktop/Materiel.pdf");

                  QPainter painter(&pdf);
                  QString TT = QDateTime::currentDateTime().toString();
                  int i = 4000;
                         painter.setPen(Qt::darkCyan);
                         painter.setFont(QFont("Time New Roman", 25));
                         painter.drawText(3000,1400,"Your PDF");
                         painter.setPen(Qt::black);
                         painter.setFont(QFont("Time New Roman", 15));
                         painter.drawRect(100,100,9400,2500);
                         painter.drawRect(100,3000,9400,500);
                         painter.setFont(QFont("Time New Roman", 9));
                         painter.drawText(400,3300,"id");
                         painter.drawText(1350,3300,"nom");
                         painter.drawText(2200,3300,"prix");
                         painter.drawText(4500,3300,"dispo");
                         painter.drawRect(100,3000,9400,10000);

                         QSqlQuery query;
                         query.prepare("select * from Materiel");
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
                         QMessageBox::information(this, QObject::tr("PDF Saved Successfuly!"),
                         QObject::tr("PDF Saved Successfuly!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
}

void materielm::on_codeqr_clicked()
{

        if(ui->tab_mat->currentIndex().row()==-1)
                   QMessageBox::information(nullptr, QObject::tr("Suppression"),
                                            QObject::tr("Veuillez Choisir un materiel du Tableau.\n"
                                                        "Click Ok to exit."), QMessageBox::Ok);
               else
               {




                       int id=ui->tab_mat->model()->data(ui->tab_mat->model()->index(ui->tab_mat->currentIndex().row(),0)).toInt();

                 const QrCode qr = QrCode::encodeText(std::to_string(id).c_str(), QrCode::Ecc::LOW);
                    std::ofstream myfile;
                    myfile.open ("qrcode.svg") ;
                    myfile << qr.toSvgString(1);
                    myfile.close();
                    QSvgRenderer svgRenderer(QString("qrcode.svg"));                                                               ///rendre l'image

                    QPixmap pix( QSize(140, 140) );
                    QPainter pixPainter( &pix );
                    svgRenderer.render( &pixPainter );
                    ui->label_qrcode->setPixmap(pix);
               }
}

void materielm::on_comboBox_supp_currentIndexChanged(int index)
{
 ui->comboBox_supp->currentText();
}
