#ifndef LOGIN2_H
#define LOGIN2_H

#include <QDialog>

namespace Ui {
class login2;
}

class login2 : public QDialog
{
    Q_OBJECT

public:
    explicit login2(QWidget *parent = nullptr);
    ~login2();

private slots:

    void on_pushButtonlogin2_clicked();

private:
    Ui::login2 *ui;
    bool connected = false;
};

#endif // LOGIN2_H
