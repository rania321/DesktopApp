#include "ambulancec.h"
#include<QSqlQuery>
#include<QDebug>
#include<QSqlQueryModel>
#include<QObject>
#include <QFileDialog>
#include <QFileInfo>
#include <QPrinter>
#include <QTextDocument>
#include <QSqlQuery>
#include<QCalendarWidget>
#include <QTextCharFormat>
AmbulanceC::AmbulanceC()
{

    mat=" ";prix=0; etat=" ";date=" " ;
}

AmbulanceC::AmbulanceC(QString mat,double prix,QString etat,QString date)
{this->mat=mat;this->prix=prix;this->etat=etat;this->date=date;}
QString AmbulanceC:: getmat(){return mat; }
double AmbulanceC:: getprix(){return prix;}
QString AmbulanceC::getetat(){return etat;}
QString AmbulanceC:: getdate(){return date;}
void AmbulanceC::setmat(QString mat){this->mat=mat;}
void AmbulanceC::setprix(double prix){this->prix=prix;}
void AmbulanceC::setetat(QString etat){this->etat=etat;}
void AmbulanceC::setdate(QString date){this->date=date;}
bool AmbulanceC::ajouter()
{

     QString prix_string=QString::number(prix);
    QSqlQuery query;

       query.prepare("INSERT INTO ambulances (MATAMB,PRIXAMB,ETATAMB,DATE_ENT_AMB) "
                     "VALUES (:MATAMB, :PRIXAMB, :ETATAMB, :DATE_ENT_AMB)");
       query.bindValue(0,mat);
       query.bindValue(1, prix_string);
       query.bindValue(2, etat);
       query.bindValue(3, date);
       return  query.exec();

}

bool AmbulanceC::supprimer(QString mat)
{
    QSqlQuery query;

       query.prepare("Delete from ambulances where MATAMB=:mat");
       query.bindValue(0,mat);

       return  query.exec();




}


bool AmbulanceC::modifier()
{
   QSqlQuery query;
 QString prix_string=QString::number(prix);

      query.prepare("update ambulances set MATAMB=:mat,PRIXAMB=:prix,ETATAMB=:etat,DATE_ENT_AMB=:date where MATAMB=:mat");


      query.bindValue(0,mat);
      query.bindValue(1, prix_string);
      query.bindValue(2, etat);
      query.bindValue(3, date);
      query.bindValue(4, mat);
      return  query.exec();






      /* query.bindValue(":MATAMB",mat);
       query.bindValue(":PRIXAMB", prix);
       query.bindValue(":ETATAMB", etat);
       query.bindValue(":DATE_ENT_AMB", date);
       return  query.exec();*/

}

QSqlQueryModel* AmbulanceC::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

        model->setQuery("SELECT * FROM ambulances");
        // MATAMB,PRIXAMB,ETATAMB,DATE_ENT_AMB
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Matricule"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("etat"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("date d'entretient"));



        return model;
}
QSqlQueryModel * AmbulanceC::afficheroncombomat()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from ambulances");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("matricule"));
    return model;
}



//tri
QSqlQueryModel *AmbulanceC::affichermat()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from ambulances order by MATAMB");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("MATAMB"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("prixAMB"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("etatAMB"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATE_ENT_AMB"));
    return model;
}
QSqlQueryModel *AmbulanceC::afficheretat()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from ambulances order by ETATAMB");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("MATAMB"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("prixAMB"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("etatAMB"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATE_ENT_AMB"));
    return model;
}
QSqlQueryModel *AmbulanceC::afficherprix()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from ambulances order by PRIXAMB");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("MATAMB"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("prixAMB"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("etatAMB"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATE_ENT_AMB"));
    return model;
}
//PDF
void AmbulanceC::CREATION_PDF()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
       if (QFileInfo(fileName).suffix().isEmpty())
           { fileName.append(".pdf"); }

       QPrinter printer(QPrinter::PrinterResolution);
       printer.setOutputFormat(QPrinter::PdfFormat);
       printer.setPaperSize(QPrinter::A4);
       printer.setOutputFileName(fileName);

       QTextDocument doc;
       QSqlQuery q;
       q.prepare("SELECT * FROM employe ");
       q.exec();
       QString pdf="<br> <h1  style='color:blue'>LISTE DES employe  <br></h1>\n <br> <table>  <tr>  <th>CIN </th> <th>NOM </th> <th>PRENOM  </th> <th>AGE  </th><th>TEL  </th><th>ADRESS   </th> </tr>" ;
   //br traja ll star oel tr tzidlek colonne th tzidlek ligne h1 asghrr size o akbr size h6 //

       while ( q.next())
           {

           pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+" " + q.value(1).toString() +"</td>   <td>" +q.value(2).toString() +" <td>" +q.value(3).toString() +" <td>" +q.value(4).toString() +" <td>" +q.value(5).toString() +" "" " "</td> </td>" ;
       }
       doc.setHtml(pdf);
       doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
       doc.print(&printer);


}

//calendrier
bool AmbulanceC::ajouterD(QCalendarWidget* calendarwidget,QString EVENT)
{  QDate DATEENT;
    DATEENT=calendarwidget->selectedDate();
    QTextCharFormat format;
    format.setBackground(Qt::red);
    calendarwidget->setDateTextFormat(DATEENT,format);
    QSqlQuery query;
    query.prepare("INSERT INTO DATEENT (DATENT,EVENT)"
                  "VALUES(:DATEENT,:EVENT)");
    query.bindValue(":DATEENT",DATEENT);
    query.bindValue(":EVENT",EVENT);
    return query.exec();

}
bool AmbulanceC::supprimerD(QCalendarWidget* calendarwidget)
{
    QSqlQuery query;
    QDate DATEENT;
    DATEENT=calendarwidget->selectedDate();
    QTextCharFormat format;
    format.setBackground(Qt::blue);
    calendarwidget->setDateTextFormat(DATEENT,format);
    DATEENT=calendarwidget->selectedDate();
    query.prepare("DELETE FROM DATEENT WHERE DATEENT = :DATENT");
    query.bindValue(":DATEENT",DATEENT);
    return query.exec();
}

bool AmbulanceC::afficherD(QCalendarWidget* calendarwidget, QLineEdit* qle)
{
   QDate selectedDate = calendarwidget->selectedDate();
   QString sqlQuery = "SELECT EVENT FROM DATEENT WHERE DATEENT = :selectedDate";
   QSqlQuery query;
   query.prepare(sqlQuery);
   query.bindValue(":selectedDate",selectedDate);
   if(!query.exec()){
   } else if (!query.first()){
       return false; } else {
       QString EVENT=query.value(0).toString();
       qle->setText(EVENT);
       return true;
   }
   return true;

}

/*QDate AmbulanceC::recupererdate(QString event) {
    QSqlQuery query;
    query.prepare("SELECT DATEENT FROM DATEENT WHERE EVENT = :event");
    query.bindValue(":event", event);
    if (query.exec() && query.first()) {
        return query.value(0).toDate();
    }
    // handle errors here, e.g. return a default date
    return QDate();
}*/
QDate AmbulanceC::recupererdate(QCalendarWidget* calendarwidget) {
    QDate selectedDate = calendarwidget->selectedDate();
    QString sqlQuery = "SELECT EVENT FROM DATEENT WHERE DATEENT = :selectedDate";
    QSqlQuery query;
    query.prepare(sqlQuery);
    query.bindValue(":selectedDate",selectedDate);
    if(!query.exec()){
        // handle errors here, e.g. return a default date
        return QDate();
    } else if (!query.first()){
        // handle no date found for selectedDate here, e.g. return a default date
        return QDate();
    } else {
        QString EVENT=query.value(0).toString();
        return selectedDate;
    }
}

QSqlQueryModel * AmbulanceC ::afficherGazA()
    {

        QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from GAZ");


            return model;
    }
