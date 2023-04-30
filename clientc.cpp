#include "clientc.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QSqlQueryModel>
#include<QObject>
#include <QFile>
#include <QTextStream>
#include <QDateTime>

clientc::clientc()
{

}

clientc::clientc(int cinc, QString nomc, QString emailc, QString adressec, int phonec, QString sexec)
{
    this->cinc=cinc;
    this->nomc=nomc;
    this->emailc=emailc;
    this->adressec=adressec;
    this->phonec=phonec;
    this->sexec=sexec;
}
int clientc::Getcinc(){return cinc;}
QString clientc::Getnomc(){return nomc;}
QString clientc::Getemailc(){return emailc;}
QString clientc::Getadressec(){return adressec;}
QString clientc::Getsexec(){return sexec;}
int clientc::Getphonec(){return phonec;}
void clientc::Setcinc(int cinc){this->cinc=cinc;}
void clientc::Setnomc(QString nomc){this->nomc=nomc;}
void clientc::Setemailc(QString emailc){this->emailc=emailc;}
void clientc::Setadressec(QString adressec){this->adressec=adressec;}
void clientc::Setsexec(QString sexec){this->sexec=sexec;}
void clientc::Setphonec(int phonec){this->phonec=phonec;}
int clientc::found(int cinc, QString nomc, QString emailc, QString adressec, int phonec, QString sexec)
{
    QSqlQuery query;
    QString cinc_string=QString::number(cinc);
    QString phonec_string=QString::number(phonec);
    query.prepare("SELECT COUNT(*) FROM CLIENTS WHERE CINC=:cinc AND NOMC=:nomc AND EMAILC=:emailc AND ADRESSEC=:adressec AND PHONEC=:phonec AND SEXEC=:sexec ");
    query.bindValue(":cinc", cinc_string);
    query.bindValue(":nomc", nomc);
    query.bindValue(":emailc", emailc);
    query.bindValue(":adressec", adressec);
    query.bindValue(":phonec", phonec_string);
    query.bindValue(":sexec", sexec);
    query.exec();
    query.next();
    qDebug()<<query.value(0).toInt();
    return query.value(0).toInt();
}

//crud
bool clientc::ajouterC()
{

    QSqlQuery query;
    QString cinc_string=QString::number(cinc);
    QString phonec_string=QString::number(phonec);
    query.prepare("INSERT INTO Clients (cinc, nomc, emailc, adressec, phonec, sexec) "
                  "VALUES (:cinc, :nomc, :emailc, :adressec, :phonec, :sexec)");
          query.bindValue(":cinc", cinc_string);
          query.bindValue(":nomc", nomc);
          query.bindValue(":emailc", emailc);
          query.bindValue(":adressec", adressec);
          query.bindValue(":phonec", phonec_string);
          query.bindValue(":sexec", sexec);


    return query.exec();
}

bool clientc::supprimerC(int cinc)
{
    QSqlQuery query;
    query.prepare("delete from Clients where cinc=:cinc");

          query.bindValue(":cinc", cinc);

    return query.exec();
}
QSqlQueryModel* clientc::afficherC()
{
    QSqlQueryModel* model= new QSqlQueryModel();
          model->setQuery("SELECT* FROM Clients");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("Email"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("Phone"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("Sexe"));
    return model;
}
bool clientc::modifierC()
{

    QSqlQuery query;
    QString cinc_string=QString::number(cinc);
    QString phonec_string=QString::number(phonec);
    query.prepare("update Clients set nomc=:nomc, emailc=:emailc, adressec=:adressec, phonec=:phonec, sexec=:sexec where cinc=:cinc");
          query.bindValue(":cinc", cinc_string);
          query.bindValue(":nomc", nomc);
          query.bindValue(":emailc", emailc);
          query.bindValue(":adressec", adressec);
          query.bindValue(":phonec", phonec_string);
          query.bindValue(":sexec", sexec);


    return query.exec();
}
QSqlQueryModel * clientc ::afficheroncomboc()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from clients");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cinc"));

        return model; }

//les metiers
QSqlQueryModel *clientc::afficher_cinc()
{
  QSqlQueryModel *model=new QSqlQueryModel();
  model->setQuery("select * from clients order by cinc");
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("Email"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
  model->setHeaderData(4, Qt::Horizontal, QObject::tr("Phone"));
  model->setHeaderData(5, Qt::Horizontal, QObject::tr("Sexe"));
        return model;
}
QSqlQueryModel *clientc::afficher_nomc()
{
  QSqlQueryModel *model=new QSqlQueryModel();
  model->setQuery("select * from clients order by nomc");
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("Email"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
  model->setHeaderData(4, Qt::Horizontal, QObject::tr("Phone"));
  model->setHeaderData(5, Qt::Horizontal, QObject::tr("Sexe"));
        return model;
}
QSqlQueryModel *clientc::afficher_adressec()
{
  QSqlQueryModel *model=new QSqlQueryModel();
  model->setQuery("select * from clients order by adressec");
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
  model->setHeaderData(2, Qt::Horizontal, QObject::tr("Email"));
  model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
  model->setHeaderData(4, Qt::Horizontal, QObject::tr("Phone"));
  model->setHeaderData(5, Qt::Horizontal, QObject::tr("Sexe"));
        return model;
}
void clientc::writeLog(int id,QString message)
{
    // Ouverture du fichier en mode écriture à la fin du fichier
    QFile file("C:/Users/Rania/Desktop/2A3/qt/historiques.txt");
    if (!file.open(QIODevice::Append | QIODevice::Text))
        return;

    // Création d'un objet QTextStream pour écrire dans le fichier
    QTextStream out(&file);
    QDateTime currentDateTime = QDateTime::currentDateTime();
      QString dateTimeString = currentDateTime.toString("dd-MM-yyyy hh:mm:ss");

    // Écriture du message de log avec l'ID correspondant
    out << dateTimeString <<" " << " " << message << id << endl;

    // Fermeture du fichier
    file.close();
}
