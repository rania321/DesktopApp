#ifndef RECLAMATION_H
#define RECLAMATION_H
#include "reclam.h"
#include <QMainWindow>
#include "arduino.h"

namespace Ui {
class reclamation;
}

class reclamation : public QMainWindow
{
    Q_OBJECT

public:
    explicit reclamation(QWidget *parent = nullptr);
    ~reclamation();

private slots:
    void on_reclamation_ajouter_clicked();
    void onTableClicked(const QModelIndex &);

    void on_reclamation_delete_clicked();

    void on_reclamation_modifier_show_clicked();

    void on_reclamation_annuler_clicked();

    void on_reclamation_modifier_clicked();

    void on_reclamation_modifier_show_2_clicked();

    void on_reclamation_modifier_show_5_clicked();

    void on_pushButton_6_clicked();

    void on_reclamation_modifier_show_6_clicked();

    void refresh();

    void checkSerial();

private:
    Ui::reclamation *ui;
    reclam Rtmp;
    int select_reclamation=-1;
    Arduino A;
};

#endif // RECLAMATION_H
