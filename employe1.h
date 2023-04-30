#ifndef EMPLOYE1_H
#define EMPLOYE1_H

#include <QDialog>

namespace Ui {
class employe1;
}

class employe1 : public QDialog
{
    Q_OBJECT

public:
    explicit employe1(QWidget *parent = nullptr);
    ~employe1();

private:
    Ui::employe1 *ui;
};

#endif // EMPLOYE1_H
