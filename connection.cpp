#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("SmartAMB");
db.setUserName("Rania");//inserer nom de l'utilisateur
db.setPassword("Rania");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;


    return  test;
}
