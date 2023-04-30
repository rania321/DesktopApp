/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_employe;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLabel *label_9;
    QTableView *tableView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 578);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(240, 140, 231, 51));
        pushButton->setStyleSheet(QLatin1String("QPushButton{\n"
"	border-radius:5px;\n"
"   border-right:1px solid #aaaaaa;\n"
"	border-bottom:1px solid #aaaaaa;\n"
"}\n"
"QPushButton:enabled{\n"
"background-color: rgb(98, 185, 203);\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: rgb(190, 233, 231);\n"
"	color: rgb(255, 255, 255);\n"
"	border-radius:5px;\n"
"}\n"
"QPushButton:disabled{\n"
"background-color: #aaaaaa;\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
""));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 200, 231, 51));
        pushButton_2->setStyleSheet(QLatin1String("QPushButton{\n"
"	border-radius:5px;\n"
"   border-right:1px solid #aaaaaa;\n"
"	border-bottom:1px solid #aaaaaa;\n"
"}\n"
"QPushButton:enabled{\n"
"background-color: rgb(98, 185, 203);\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: rgb(190, 233, 231);\n"
"	color: rgb(255, 255, 255);\n"
"	border-radius:5px;\n"
"}\n"
"QPushButton:disabled{\n"
"background-color: #aaaaaa;\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
""));
        pushButton_employe = new QPushButton(centralwidget);
        pushButton_employe->setObjectName(QStringLiteral("pushButton_employe"));
        pushButton_employe->setGeometry(QRect(240, 260, 231, 51));
        pushButton_employe->setStyleSheet(QLatin1String("QPushButton{\n"
"	border-radius:5px;\n"
"   border-right:1px solid #aaaaaa;\n"
"	border-bottom:1px solid #aaaaaa;\n"
"}\n"
"QPushButton:enabled{\n"
"background-color: rgb(98, 185, 203);\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: rgb(190, 233, 231);\n"
"	color: rgb(255, 255, 255);\n"
"	border-radius:5px;\n"
"}\n"
"QPushButton:disabled{\n"
"background-color: #aaaaaa;\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
""));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(240, 320, 231, 51));
        pushButton_4->setStyleSheet(QLatin1String("QPushButton{\n"
"	border-radius:5px;\n"
"   border-right:1px solid #aaaaaa;\n"
"	border-bottom:1px solid #aaaaaa;\n"
"}\n"
"QPushButton:enabled{\n"
"background-color: rgb(98, 185, 203);\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: rgb(190, 233, 231);\n"
"	color: rgb(255, 255, 255);\n"
"	border-radius:5px;\n"
"}\n"
"QPushButton:disabled{\n"
"background-color: #aaaaaa;\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
""));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(240, 380, 231, 51));
        pushButton_5->setStyleSheet(QLatin1String("QPushButton{\n"
"	border-radius:5px;\n"
"   border-right:1px solid #aaaaaa;\n"
"	border-bottom:1px solid #aaaaaa;\n"
"}\n"
"QPushButton:enabled{\n"
"background-color: rgb(98, 185, 203);\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: rgb(190, 233, 231);\n"
"	color: rgb(255, 255, 255);\n"
"	border-radius:5px;\n"
"}\n"
"QPushButton:disabled{\n"
"background-color: #aaaaaa;\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
""));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(240, 90, 221, 21));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setUnderline(false);
        font.setWeight(75);
        label_9->setFont(font);
        label_9->setStyleSheet(QStringLiteral("color: rgb(27, 75, 101);"));
        label_9->setAlignment(Qt::AlignCenter);
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(220, 110, 271, 341));
        tableView->setStyleSheet(QLatin1String("border-color: rgb(27, 75, 101);\n"
"background-color: rgb(243, 243, 243);"));
        MainWindow->setCentralWidget(centralwidget);
        tableView->raise();
        pushButton->raise();
        pushButton_2->raise();
        pushButton_employe->raise();
        pushButton_4->raise();
        pushButton_5->raise();
        label_9->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Gestion des ambulances", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Gestion des clients", Q_NULLPTR));
        pushButton_employe->setText(QApplication::translate("MainWindow", "Gestion des employ\303\251s", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "Gestion des mat\303\251riels", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "Gestion des r\303\251clamations", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "MENU", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
