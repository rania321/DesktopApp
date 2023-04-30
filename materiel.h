#ifndef MATERIEL_H
#define MATERIEL_H
#include<QString>
#include <QSqlQueryModel>
class Materiel
{
    int idmat,prixmat;
    QString nommat,dispomat;
public:
    Materiel();
    Materiel(int,QString,int,QString);
    int getidmat();
    QString getnommat();
    int getprixmat();
    QString getdispomat();
    void setidmat(int);
    void setnommat(QString);
     void setprixmat(int);
     void setdispomat(QString);
     bool ajouterm();
     bool supprimerm(int);
     bool modifierm(int idmat,int prixmat,QString nommat,QString dispomat);
     QSqlQueryModel* afficherm();
     QSqlQueryModel *afficher_idmat();
     QSqlQueryModel *afficher_prixmat();
     QSqlQueryModel *afficher_nommat();
     QSqlQueryModel *affichercheroncomboc();

     QSqlQueryModel * tri(QString,QString);





};

#endif // MATERIEL_H
