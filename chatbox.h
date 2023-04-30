#ifndef CHATBOX_H
#define CHATBOX_H

#include <QDialog>

namespace Ui {
class chatbox;
}


class QTcpSocket;

class chatbox : public QDialog
{
    Q_OBJECT

public:
    explicit chatbox(QWidget *parent = nullptr);
    ~chatbox();

private slots:
    void on_sendC_clicked();

    void on_bindC_clicked();

private:
    Ui::chatbox *ui;
    QTcpSocket *mSocket;
};


#endif // CHATBOX_H
