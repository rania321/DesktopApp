#include "employe2c.h"
#include"QtDebug"
#include<QObject>
#include<QSqlError>
#include"mainwindow.h"
#include "QSqlQuery "
#include <QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include<QSqlQueryModel>


Employe::Employe(){
    CINE=0;
    NOME=" ";
    PRENOME=" ";
    SALAIRE=0;
    METIER=" ";

}
Employe::Employe(int CINE,QString NOME,int SALAIRE,QString METIER,QString PRENOME){
    this->CINE=CINE;
     this->NOME=NOME;
     this->PRENOME=PRENOME;
     this->SALAIRE=SALAIRE;
     this->METIER=METIER;


}
int Employe::getCINE() {
    return CINE;
}

QString Employe::getNOME() {
    return NOME;
}

QString Employe::getPRENOME() {
    return PRENOME;
}

int Employe::getSALAIRE() {
    return SALAIRE;
}

QString Employe::getMETIER() {
    return METIER;
}

void Employe::setCINE(int cine) {
    CINE = cine;
}

void Employe::setNOME(QString nome) {
    NOME = nome;
}

void Employe::setPRENOME(QString prenome) {
    PRENOME = prenome;
}

void Employe::setSALAIRE(int salaire) {
    SALAIRE = salaire;
}

void Employe::setMETIER(QString metier) {
    METIER = metier;
}
bool Employe::ajouter()
{

    //bool test=false;
    QSqlQuery query;
    QString CINE_string = QString::number(CINE);
     QString SALAIRE_string = QString::number(SALAIRE);
         query.prepare("INSERT INTO EMPLOYE (CINE, NOME, PRENOME,SALAIRE,METIER) "
                       "VALUES (:CINE, :forename, :surname, :SALAIRE, :METIER)");
         query.bindValue(":CINE", CINE_string);
         query.bindValue(":forename", NOME);
         query.bindValue(":surname", PRENOME);
          query.bindValue(":SALAIRE", SALAIRE_string);
           query.bindValue(":METIER", METIER);
         return  query.exec();

    //return test;
}
QSqlQueryModel* Employe::afficher(){

    QSqlQueryModel* model=new QSqlQueryModel();



        model->setQuery("SELECT * FROM EMPLOYE");
        model->setHeaderData(0, Qt::Horizontal,QObject::tr("CINE"));
        model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOME"));
        model->setHeaderData(2, Qt::Horizontal,QObject::tr("SALAIRE"));
        model->setHeaderData(3, Qt::Horizontal,QObject::tr("METIER"));
         model->setHeaderData(4, Qt::Horizontal,QObject::tr("PRENOME"));


    return model;



}
bool Employe::supprimer(int CINE){
    QSqlQuery query;
    QString CINE_string = QString::number(CINE);
         query.prepare("Delete from employe where CINE=:CINE ");
         query.bindValue(0,CINE);
         return  query.exec();
}
bool Employe::modifier()
{

    QSqlQuery query;
      //  QString res= QString(cin);
        QString CIN_STRING=QString::number(CINE);
        QString SAL_STRING= QString::number(SALAIRE);
        query.prepare("UPDATE EMPLOYE SET CINE='"+CIN_STRING+"',NOME='"+NOME+"',SALAIRE='"+SAL_STRING+"',METIER='"+METIER+"',PRENOME='"+PRENOME+"' WHERE CINE='"+CIN_STRING+"'");

         query.bindValue(0,CIN_STRING);
          query.bindValue(1, NOME );
           query.bindValue(2,SAL_STRING);
          query.bindValue(3, METIER);
            query.bindValue(4, PRENOME);

          return query.exec() ;
}
void Employe::CREATION_PDF()
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
/*QSqlQueryModel* Employe::rechercheC(int CINE)

 {
    QSqlQueryModel* model=new QSqlQueryModel() ;
        QString cin_string = QString::number(CINE);

       model->setQuery("select * from employe where CINE='"+cin_string+"'");
       model->setHeaderData(0, Qt::Horizontal, QObject::tr("CINE"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOME"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("SALAIRE"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("METIER"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("PRENOME"));




       return model;
}*/
QSqlQueryModel* Employe::afficherencomboemploye()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select cine from employe");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("cine"));
    return model;
}
QSqlQueryModel* Employe::afficherparsaliare()
{

    QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery("SELECT * FROM EMPLOYE ORDER BY SALAIRE ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("CINE"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOME"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("SALAIRE"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("METIER"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRENOME"));
        return model;
}
QSqlQueryModel* Employe::afficherparcin(){

QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM EMPLOYE ORDER BY CINE ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CINE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOME"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("SALAIRE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("METIER"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRENOME"));
    return model;}
QSqlQueryModel* Employe::afficherparnom(){
    QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery("SELECT * FROM EMPLOYE ORDER BY NOME ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("CINE"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOME"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("SALAIRE"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("METIER"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRENOME"));
        return model;

}
bool Employe::modifierEtapDuMoteur(int etap){

    QSqlQuery query;
        query.prepare(QString("UPDATE Moteur SET ETAP=%1").arg(etap));


          return query.exec() ;
}
