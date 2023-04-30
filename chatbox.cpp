#include "chatbox.h"
#include "ui_chatbox.h"
#include <QTcpSocket>
#include <QTextStream>
#include "loginclient.h"


chatbox::chatbox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chatbox)
{
    ui->setupUi(this);
    mSocket = new QTcpSocket(this);
    connect(mSocket, &QTcpSocket::readyRead, [&]() {
            QTextStream T(mSocket);
            auto text = T.readAll();
            ui->textEditC->append(text);
        });
}

chatbox::~chatbox()
{
    delete ui;
}

void chatbox::on_sendC_clicked()
{
    QTextStream T(mSocket);
    T << ui ->nicknameC->text() << " : " << ui->messageC->text();
    mSocket->flush();
    ui->messageC->clear();
}

void chatbox::on_bindC_clicked()
{
    LoginClient D(this);
    if(D.exec() == QDialog::Rejected) {
            return;
        }
        mSocket->connectToHost(D.hostname(), D.port());
}
