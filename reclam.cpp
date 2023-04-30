#include "reclam.h"
#include <QSqlQuery>
#include "connection.h"

reclam::reclam()
{

}

reclam::reclam(QString nom,QString email,QString rec,int CIN,int typeRec,QDate date)
{
    srand(time(0));
    this->ID=rand();
    this->nom=nom;
    this->email=email;
    this->rec=rec;
    this->CIN=CIN;
    this->typeRec=typeRec;
    this->date=date;
}

bool reclam::ajouter()
{

    QSqlQuery query;
    query.prepare("INSERT INTO RECLAMATION(ID,NOM,CIN,EMAIL,DATEREC,REC,TYPEREC)" "VALUES(:id,:nom,:cin,:email,:daterec,:rec,:typerec)");
    query.bindValue(":id",ID);
    query.bindValue(":nom",nom);
    query.bindValue(":cin",CIN);
    query.bindValue(":email",email);
    query.bindValue(":daterec",date);
    query.bindValue(":rec",rec);
    query.bindValue(":typerec",typeRec);
    return query.exec();
}
bool reclam::modifier(int id){
    QSqlQuery query;

    QString SqlQuery = "UPDATE RECLAMATION "
                       "set nom=:nom , cin=:cin , email=:email , daterec=:daterec , rec=:rec where id=:id;";
    query.prepare(SqlQuery);


    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":cin",CIN);
    query.bindValue(":email",email);
    query.bindValue(":daterec",date);
    query.bindValue(":rec",rec);
    query.bindValue(":typerec",typeRec);

    return query.exec();
}
QSqlQueryModel* reclam::afficher()
{
    QSqlQueryModel*model=new QSqlQueryModel();
    model->setQuery("select * from RECLAMATION");
    return  model;
}
bool reclam::supprimer( int id) {
    QSqlQuery query;
    query.prepare("delete  from RECLAMATION where ID= :id");
     query.bindValue(":id",id);

     return query.exec();
}
bool reclam::researchCIN(int cin)
{

    QSqlQuery query;
    QSqlQueryModel* model = new QSqlQueryModel();

    model->setQuery(QString("Select * from RECLAMATION where cin = %1;").arg(cin));
    if(model->rowCount()>0)
        return  true;
    return false;
}

bool reclam::researchCINID(int cin,int id)
{

    QSqlQuery query;
    QSqlQueryModel* model = new QSqlQueryModel();

    model->setQuery(QString("Select * from RECLAMATION where cin = %1 AND id != %2;").arg(cin).arg(id));
    if(model->rowCount()>0)
        return  true;
    return false;
}

QSqlQueryModel * reclam::researcher(QString recherche)
{
    QSqlQueryModel*model=new QSqlQueryModel();
    model->setQuery("select * from RECLAMATION where nom like '%"+recherche+"%' OR cin like '%"+recherche+"%' OR email like '%"+recherche+"%' OR daterec like '%"+recherche+"%' OR rec like '%"+recherche+"%' OR id like '%"+recherche+"%'");
    return  model;
}

QSqlQueryModel * reclam::researcherEtap(int etat)
{
    QSqlQueryModel*model=new QSqlQueryModel();
    model->setQuery(QString("select * from RECLAMATION Where TYPEREC = %1").arg(etat));
    return  model;
}

bool reclam::modifierLoggin (int loggin)
{
    QSqlQuery query;

    QString SqlQuery = QString("UPDATE STATUS set LOG=%1").arg(loggin);
    query.prepare(SqlQuery);
    return query.exec();
}
int   reclam::researchLogin()
{
    QSqlQuery query;
    query.prepare("SELECT LOG FROM STATUS");
    if (query.exec() && query.first()) {
        return query.value(0).toInt();
    } else {
        return -1; // or some other error value
    }
}
