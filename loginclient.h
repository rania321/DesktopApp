#ifndef LOGINCLIENT_H
#define LOGINCLIENT_H

#include <QDialog>

namespace Ui {
class LoginClient;
}

class LoginClient : public QDialog
{
    Q_OBJECT

public:
    explicit LoginClient(QWidget *parent = nullptr);
    ~LoginClient();
    QString hostname() const;
    quint16 port() const;

private slots:
    void on_okC_clicked();

    void on_cancelC_clicked();

private:
    Ui::LoginClient *ui;
    QString mHostname;
    quint16 mPort;
};
inline QString LoginClient::hostname() const {
    return mHostname;
}

inline quint16 LoginClient::port() const {
    return mPort;
}


#endif // LOGINCLIENT_H
