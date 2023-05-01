#ifndef EMPLOYE2_H
#define EMPLOYE2_H
#include <QMainWindow>
#include "login2.h"
#include "employe2c.h"
#include "mainwindow.h"
#include <QSqlQueryModel>
#include "arduinoe.h"
#include <QDialog>
#include <QApplication>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class employe2; }
QT_END_NAMESPACE

class employe2 : public QWidget
{
    Q_OBJECT

public:
    employe2(QWidget *parent = nullptr);
    ~employe2();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_button_modifier_clicked();

    void on_pdf_button_clicked();

    void on_login2_clicked();

    void on_line_textChanged(const QString &arg1);

    void on_stat_clicked();

    void on_comboBox_SUPP_currentIndexChanged(int index);

    void on_comboBoxtri_currentIndexChanged(const QString &arg1);

    void on_pushButtontri_clicked();

    void checkSeriel();

    void on_pb_menuE_clicked();

    void showMainMenu();

private:
    Ui::employe2 *ui;
    Employe E;
    arduinoe A;
};

#endif // EMPLOYE2_H
