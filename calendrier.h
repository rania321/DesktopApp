#ifndef CALENDRIER_H
#define CALENDRIER_H

#include <QDialog>

namespace Ui {
class calendrier;
}

class calendrier : public QDialog
{
    Q_OBJECT

public:
    explicit calendrier(QWidget *parent = nullptr);
    ~calendrier();

private slots:
    void on_pb_ajoutdate_clicked();

    void on_pb_affdate_clicked();

    void on_pb_suppD_clicked();

private:
    Ui::calendrier *ui;
};

#endif // CALENDRIER_H
