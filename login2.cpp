#include "login2.h"
#include "ui_login2.h"
#include <QMessageBox>
#include"mainwindow.h"
login2::login2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login2)
{
    ui->setupUi(this);
}

login2::~login2()
{
    delete ui;
}


void login2::on_pushButtonlogin2_clicked()
{

    QString username = ui->use2_edit->text();
        QString password = ui->pas_edit->text();
        MainWindow *w = new MainWindow();
        if (username == "test" && password == "test")
        {
            QMessageBox::information(this, tr("Welcome ya degla ❤"),
            tr("Connection successful.\n"
            "Click OK to proceed."), QMessageBox::Ok);
            hide();
            connected = true;
            w->show();
        }
        else
        {
            QMessageBox::critical(this, tr("Database is not open"),
            tr("Connection failed.\n"
            "Click Cancel to exit."), QMessageBox::Cancel);
            delete w;
        }
}
