#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QVBoxLayout>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    client client;
    client.setModal(true);
    client.exec();
}


void MainWindow::on_pushButton_employe_clicked()
{

    employe2 *employe = new employe2(); // création d'une instance de la classe employe2

       QVBoxLayout *layout = new QVBoxLayout;

       // Ajouter l'objet de la classe employe2 au layout
       layout->addWidget(employe);

       // Définir le layout pour la zone centrale de MainWindow
   //    QWidget *centralWidget = new QWidget(this);
     //  centralWidget->setLayout(layout);
     //  setCentralWidget(centralWidget);

       // Utiliser l'opérateur flèche pour appeler une méthode de l'objet pointé par le pointeur employe
       employe->show();




}



void MainWindow::on_pushButton_clicked()
{
    AmbulanceI a;
    a.setModal(true);
    a.exec();
}

void MainWindow::on_pushButton_4_clicked()
{
    materielm materiel;
        materiel.setModal(true);
        materiel.exec();
}

void MainWindow::on_pushButton_5_clicked()
{
    reclamation *rec = new reclamation;
   // this->close();
    rec->show();
}


