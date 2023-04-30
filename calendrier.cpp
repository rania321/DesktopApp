#include "calendrier.h"
#include "ui_calendrier.h"
#include "ambulancec.h"
#include"ambulancei.h"


calendrier::calendrier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::calendrier)
{
    ui->setupUi(this);
    AmbulanceC A;
    A.afficherD(ui->calendarWidget,ui->le_affdate);
  //  QList<QDate> dates=A.recupererdate(ui->calendarWidget);
}

calendrier::~calendrier()
{
    delete ui;

}

void calendrier::on_pb_affdate_clicked()
{   AmbulanceC A;
//   QList<QDate> dates=A.recupererdate(ui->calendarWidget);
     ui->le_affdate->setText(ui->le_ajoutdate->text());
}

void calendrier::on_pb_ajoutdate_clicked()
{  AmbulanceC A;
    A.ajouterD(ui->calendarWidget,ui->le_ajoutdate->text());
//  QList<QDate> dates=A.recupererdate(ui->calendarWidget);


}



void calendrier::on_pb_suppD_clicked()
{  AmbulanceC A;
    A.supprimerD(ui->calendarWidget);
   // QList<QDate> dates=A.recupererdate(ui->calendarWidget);


}
