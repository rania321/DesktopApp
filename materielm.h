#ifndef MATERIELM_H
#define MATERIELM_H
#include "materiel.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>
#include <QDialog>
#include "arduino.h"

namespace Ui {
class materielm;
}

class materielm : public QDialog
{
    Q_OBJECT

public:
    explicit materielm(QWidget *parent = nullptr);
    ~materielm();

private slots:
    void on_pb_ajouterm_clicked();

    void on_pb_suppm_clicked();

    void on_pushButton_2_clicked();

    //void on_comboBox_trimat_activated(const QString &arg1);

    void on_comboBox_trimat_currentTextChanged(const QString &arg1);

    void on_pushButton_trimat_clicked();

    void on_rechercherm_textChanged(const QString &arg1);

    void on_tab_mat_activated(const QModelIndex &index);

    void on_pb_statm_clicked();

    void on_pb_pdfm_clicked();

    void on_codeqr_clicked();

    void on_comboBox_supp_currentIndexChanged(int index);

private:
    Ui::materielm *ui;
    Materiel m;
    //arduino A;

};

#endif // MATERIELM_H
