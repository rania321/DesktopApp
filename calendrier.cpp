#include "calendrier.h"
#include "ui_calendrier.h"
#include "ambulancec.h"
#include"ambulancei.h"
#include<QSqlQuery>
#include<QMessageBox>


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
{   // Get the selected date from the calendar widget
    QDate date = ui->calendarWidget->selectedDate();

    // Prepare an SQL query to select the event for the selected date from the database table
    QSqlQuery query;
    query.prepare("SELECT EVENT FROM DATEENT WHERE DATENT = TO_DATE(:date, 'YYYY-MM-DD')");
    query.bindValue(":date", date.toString("yyyy-MM-dd"));
    // Execute the SQL query and check if it was successful
    if (query.exec()) {
        // If the query was successful, retrieve the event from the query result and display it in a message box
        if (query.next()) {
            QString event = query.value(0).toString();
            ui->le_affdate->setText(event);
        } else {
            QMessageBox::information(this, tr("Event"), tr("No event found for the selected date."));
        }
    }
}

void calendrier::on_pb_ajoutdate_clicked()
{  AmbulanceC A;
    A.ajouterD(ui->calendarWidget,ui->le_ajoutdate->text());


    // Get the selected date from the calendar widget and the event description from the line edit
       QDate date = ui->calendarWidget->selectedDate();
       QString event = ui->le_ajoutdate->text();

       // Prepare an SQL query to insert the date and event into the database table
       QSqlQuery query;
       query.prepare("INSERT INTO DATEENT (DATENT, EVENT) VALUES (:date, :event)");
       query.bindValue(":date", date.toString("yyyy-MM-dd"));
       query.bindValue(":event", event);

       // Execute the SQL query and check if it was successful
       if (query.exec()) {
           // If the query was successful, set the text format for the selected date to highlight it in the calendar widget
           QTextCharFormat format;
           format.setBackground(Qt::red);
           ui->calendarWidget->setDateTextFormat(date, format);
       } else {
         /*  // If the query failed, display an error message
           QMessageBox::critical(this, tr("Error"), tr("Failed to add date and event"));*/
       }


}



void calendrier::on_pb_suppD_clicked()
{  AmbulanceC A;
    A.supprimerD(ui->calendarWidget);
    // Get the selected date from the calendar widget
        QDate date = ui->calendarWidget->selectedDate();

        // Prepare an SQL query to delete the date and event from the database table
        QSqlQuery query;
        query.prepare("DELETE FROM DATEENT WHERE DATENT = :date");

           query.bindValue(0,date);

      query.exec();
}
