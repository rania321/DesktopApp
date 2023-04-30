#include "mainwindow.h"
#include <QMessageBox>
#include "connection.h"
#include <QApplication>
#include"login2.h"
/*int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");

    Connection c;
    bool test=c.createconnect();
    MainWindow w;
    login2 login;
    if(test)
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    return a.exec();
}*/
/*int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");

    Connection c;
    bool test=c.createconnect();

    login2 login;
    if (login.exec() == QDialog::Accepted) {
        // If the user successfully logs in, create and show the main window
        MainWindow w;
        if (test) {
            w.show();
            QMessageBox::information(nullptr, QObject::tr("Database is open"),
                                     QObject::tr("Connection successful.\nClick Cancel to exit."),
                                     QMessageBox::Cancel);
        } else {
            QMessageBox::critical(nullptr, QObject::tr("Database is not open"),
                                   QObject::tr("Connection failed.\nClick Cancel to exit."),
                                   QMessageBox::Cancel);
        }
        return a.exec();
    } else {
        // If the user cancels the login, exit the program
        return 0;
    }
}*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");

    Connection c;
    bool test = c.createconnect();
    if (!test)
    {
        QMessageBox::critical(nullptr, QObject::tr("Database is not open"),
                    QObject::tr("Connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        return 1;
    }

    MainWindow w;
    login2 login(&w); // pass a pointer to the MainWindow instance to the login2 constructor
    login.show();

    return a.exec();
}


