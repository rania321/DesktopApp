#ifndef AMBULANCEI_H
#define AMBULANCEI_H
#include"ambulancec.h"
#include"arduino.h"

#include <QDialog>

namespace Ui {
class AmbulanceI;
}

class AmbulanceI : public QDialog
{
    Q_OBJECT

public:
    explicit AmbulanceI(QWidget *parent = nullptr);
    ~AmbulanceI();

private slots:
    void on_pushButton_7_clicked();

    void on_pb_ajout_clicked();

    void on_pb_supp_clicked();

    void on_pb_modif_clicked();

    void on_comboBox_suppamb_currentIndexChanged(int index);

    void on_tabamb_activated(const QModelIndex &index);

    void on_pb_excel_clicked();

    void on_recherche_textChanged(const QString &arg1);

    void on_pushButton_8_clicked();

    void on_stat_clicked();

    void on_comboBox_tri_ambu_currentIndexChanged(const QString &arg1);

    void on_pb_trierA_clicked();

    void on_pb_pfdA_clicked();

    void on_pb_ONA_clicked();

    void on_pb_OFFA_clicked();
    void update_labelA();

    void on_pb_gazA_clicked();

private:
    Ui::AmbulanceI *ui;
    AmbulanceC A;
    QByteArray data;//var conteneant les donnée reçues
    Arduino Ar;//obj temp
};

#endif // AMBULANCEI_H
