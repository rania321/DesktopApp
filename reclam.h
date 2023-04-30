#ifndef RECLAM_H
#define RECLAM_H
#include <QString>
#include <QDate>
#include <QSqlQueryModel>


class reclam
{
private:

    QString  nom,email,rec;
    int CIN,ID,typeRec;
    QDate date;
public:
    reclam();
    reclam(QString,QString,QString,int,int,QDate);

    bool ajouter();
    QSqlQueryModel * afficher() ;
    QSqlQueryModel * researcher(QString) ;
    QSqlQueryModel * researcherEtap(int );
    bool supprimer (int);
    bool modifier (int);
    bool researchCIN(int);
    bool researchCINID(int ,int );

    bool modifierLoggin (int);
    int  researchLogin();
};

#endif // RECLAMATION_H
