#ifndef AMBULANCEC_H
#define AMBULANCEC_H
#include<QString>
#include<QDate>
#include<QSqlQueryModel>
#include<QCalendarWidget>
#include<QLineEdit>
class AmbulanceC
{
public:
    AmbulanceC();
    AmbulanceC(QString,double,QString,QString);
    QString getmat();
    double getprix();
    QString getetat();
    QString getdate();
    void setmat(QString);
    void setprix(double);
    void setetat(QString);
    void setdate(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(QString);
    bool modifier();

    QSqlQueryModel * afficheroncombomat();
     QSqlQueryModel * affichermat();
     QSqlQueryModel * afficheretat();
     QSqlQueryModel * afficherprix();
     void CREATION_PDF() ;
     bool ajouterD(QCalendarWidget* ,QString );
     bool supprimerD(QCalendarWidget* );
     bool afficherD(QCalendarWidget* ,QLineEdit* );
     //QDate recupererdate(QString );
     QDate recupererdate(QCalendarWidget* );
     QSqlQueryModel *afficherGazA();





private:
    QString mat;
    double prix;
    QString etat;
    QString date;

};

#endif // AMBULANCEC_H
