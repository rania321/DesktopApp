#ifndef CLIENT_H
#define CLIENT_H
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QDialog>
#include"chatbox.h"
#include"clientc.h"
#include"arduino.h"

namespace Ui {
class client;
}

class client : public QDialog
{
    Q_OBJECT

public:
    explicit client(QWidget *parent = nullptr);

    ~client();

private slots:
    void on_pushButton_7_clicked();

    void on_pb_ajouterC_clicked();

    void on_pb_suppc_clicked();

    void on_pb_modififerC_clicked();

    void on_tab_clients_activated(const QModelIndex &index);

    void on_comboBox_suppC_currentIndexChanged(int index);

    void on_comboBox_tri_currentIndexChanged(const QString &arg1);

    void on_pb_trierC_clicked();

    void on_rechercherC_textChanged(const QString &arg1);

    void on_pb_pdfC_clicked();

    void on_pb_hisC_clicked();

    void on_pb_statC_clicked();

    void update_labelC();

    void on_pb_ONC_clicked();

    void on_pb_OFFC_clicked();

    void sendSMS(QString account_sid, QString auth_token, QString message, QString from_number, QString to_number, QString picture_url, bool verbose);

    //void on_nomc_cursorPositionChanged(int arg1, int arg2);

    void on_pb_gaz_clicked();

    void on_comboBox_clientC_currentIndexChanged(const QString &arg1);

    void on_comboBox_ambuC_currentIndexChanged(const QString &arg1);

    void on_pb_reserverC_clicked();

private:
    Ui::client *ui;
    clientc c;
    QPixmap PixFalseIcon,PixTrueIcon;
    QByteArray data; // variable contenant les données reçues
    Arduino A; // objet temporaire
};

#endif // CLIENT_H
