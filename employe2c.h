#ifndef EMPLOYE2C_H
#define EMPLOYE2C_H
#include <QDialog>
#include <QString>
#include <QSqlQuery>
#include<QSqlQueryModel>


class Employe {
public:
    Employe();
    Employe(int ,QString ,int ,QString ,QString );
    int getCINE();
    QString getNOME();
    QString getPRENOME();
    int getSALAIRE();
    QString getMETIER();
    void setCINE(int);
    void setNOME(QString);
    void setPRENOME(QString);
    void setSALAIRE(int);
    void setMETIER(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
      QSqlQueryModel* afficherparsaliare();
        QSqlQueryModel* afficherparcin();
          QSqlQueryModel* afficherparnom();
    bool supprimer(int);
     bool modifier();
     void CREATION_PDF() ;
      //bool rechercheremploye(int CINE) ;
       QSqlQueryModel* rechercheC(int CINE) ;
       QSqlQueryModel* afficherencomboemploye();
       bool modifierEtapDuMoteur(int);

private:
    int CINE;
     QString NOME;
     int SALAIRE;
     QString METIER;
      QString PRENOME;
};

#endif // EMPLOYE2C_H
