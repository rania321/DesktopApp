#ifndef CLIENTC_H
#define CLIENTC_H
#include<QString>
#include<QSqlQueryModel>

class clientc
{
public:
    clientc();
    clientc(int,QString,QString,QString,int,QString);
    int Getcinc();
    QString Getnomc();
    QString Getemailc();
    QString Getadressec();
    QString Getsexec();
    int Getphonec();
    void Setcinc(int);
    void Setnomc(QString);
    void Setemailc(QString);
    void Setadressec(QString);
    void Setsexec(QString);
    void Setphonec(int);
    int found(int cinc, QString nomc, QString emailc, QString adressec, int phonec, QString sexec);
    bool ajouterC();
    bool supprimerC(int);
    QSqlQueryModel* afficherC();
    bool modifierC();
    bool selectedrowC();
    QSqlQueryModel * afficheroncomboc();
    QSqlQueryModel *afficher_cinc();
    QSqlQueryModel *afficher_nomc();
    QSqlQueryModel *afficher_adressec();
    void writeLog(int,QString);


private:
    int cinc, phonec;
    QString nomc, emailc, adressec, sexec;
};

#endif // CLIENTC_H
