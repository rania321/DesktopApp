#include "loginclient.h"
#include "ui_loginclient.h"

LoginClient::LoginClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginClient)
{
    ui->setupUi(this);
}

LoginClient::~LoginClient()
{
    delete ui;
}

void LoginClient::on_okC_clicked()
{
    mHostname = ui->hostnameC->text();
    mPort = ui->portC->text().toInt();
    accept();
}

void LoginClient::on_cancelC_clicked()
{
    reject();
}
