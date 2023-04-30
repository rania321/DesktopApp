#include "materiel.h"

#include <QSqlQuery>
#include <QtDebug>


#include<QSqlQueryModel>
#include<QObject>

Materiel::Materiel()
{
idmat=0; nommat=" "; prixmat=0; dispomat=" ";}

Materiel::Materiel(int idmat,QString nommat,int prixmat,QString dispomat)
{this->idmat=idmat;this->nommat=nommat;this->prixmat=prixmat;this->dispomat=dispomat;}
int Materiel:: getidmat(){return idmat;}
QString Materiel::getnommat(){return nommat;}
int Materiel::getprixmat(){return prixmat;}
QString Materiel::getdispomat(){return dispomat;}
void Materiel::setidmat(int idmat){this->idmat=idmat;}
void Materiel::setnommat(QString nommat){this->nommat=nommat;}
void Materiel::setprixmat(int prixmat){this->prixmat=prixmat;}
void Materiel::setdispomat(QString dispomat){this->dispomat=dispomat;}

bool Materiel::ajouterm()
{QSqlQuery query;

    query.prepare("INSERT INTO Materiel (idmat,prixmat,nommat,dispomat) "
                        "VALUES (:idmat, :prixmat,:nommat ,:dispomat)");
     query.bindValue(":idmat",idmat);
    query.bindValue(":prixmat",prixmat);
    query.bindValue(":nommat",nommat);
    query.bindValue(":dispomat",dispomat);



    return    query.exec();

}

QSqlQueryModel* Materiel::afficherm()
{
    QSqlQueryModel* model= new QSqlQueryModel();
          model->setQuery("SELECT* FROM Materiel");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("dispo"));
    return model;
}
bool Materiel::supprimerm(int idmat)
{
    QSqlQuery query;

    query.prepare("delete from Materiel where idmat=:idmat");

          query.bindValue(":idmat", idmat);


    return query.exec();
}
bool Materiel::modifierm(int idmat,int prixmat,  QString nommat, QString dispomat )
{

    QSqlQuery query;
    query.prepare("UPDATE Materiel SET nommat= :nommat, dispomat= :dispomat,prixmat=:prixmat where idmat= :idmat ");
    query.bindValue(":idmat", idmat);
    query.bindValue(":nommat", nommat);
    query.bindValue(":dispomat",dispomat);
     query.bindValue(":prixmat",prixmat);
            return    query.exec();

}
QSqlQueryModel *Materiel::afficher_idmat()
{
  QSqlQueryModel *model=new QSqlQueryModel();
  model->setQuery("select * from Materiel order by idmat");
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("dispo"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix"));
        return model;
}
QSqlQueryModel *Materiel::afficher_nommat()
{
  QSqlQueryModel *model=new QSqlQueryModel();
  model->setQuery("select * from Materiel order by nommat");
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("dispo"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix"));
        return model;
}
QSqlQueryModel *Materiel::afficher_prixmat()
{
  QSqlQueryModel *model=new QSqlQueryModel();
  model->setQuery("select * from Materiel order by prixmat");
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("dispo"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix"));
        return model;
}
QSqlQueryModel * Materiel :: affichercheroncomboc()
{
    QSqlQueryModel * model =new
     QSqlQueryModel();
    model ->setQuery("select idmat from Materiel");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    return model;
}

QSqlQueryModel * Materiel ::tri(QString tripar,QString triordre)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM Materiel ORDER BY " + tripar + " " + triordre);
    return model;
}
