/********************************************************************************
** Form generated from reading UI file 'loginclient.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINCLIENT_H
#define UI_LOGINCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginClient
{
public:
    QWidget *widget_2;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLineEdit *hostnameC;
    QLineEdit *portC;
    QPushButton *okC;
    QPushButton *cancelC;

    void setupUi(QDialog *LoginClient)
    {
        if (LoginClient->objectName().isEmpty())
            LoginClient->setObjectName(QStringLiteral("LoginClient"));
        LoginClient->resize(571, 526);
        widget_2 = new QWidget(LoginClient);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(10, 10, 550, 500));
        widget_2->setStyleSheet(QLatin1String("#widget_2{\n"
"	background-color: transparent;\n"
"}\n"
"QPushButton#pushButton{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0.505682, x2:1, y2:0.477, stop:0 rgba(11, 131, 120, 219), stop:1 rgba(85, 98, 112, 226));\n"
"	color:rgba(255, 255, 255, 210);\n"
"	border-radius:5px;\n"
"}\n"
"\n"
"QPushButton#pushButton:hover{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0.505682, x2:1, y2:0.477, stop:0 rgba(150, 123, 111, 219), stop:1 rgba(85, 81, 84, 226));\n"
"}\n"
"\n"
"QPushButton#pushButton:pressed{\n"
"	padding-left:5px;\n"
"	padding-top:5px;\n"
"	background-color:rgba(150, 123, 111, 255);\n"
"}\n"
"\n"
"QPushButton#pushButton_2, #pushButton_3, #pushButton_4, #pushButton_5{\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"	color:rgba(85, 98, 112, 255);\n"
"}\n"
"\n"
"QPushButton#pushButton_2:hover, #pushButton_3:hover, #pushButton_4:hover, #pushButton_5:hover{\n"
"	color: rgba(131, 96, 53, 255);\n"
"}\n"
"\n"
"QPushButton#pushButton_2:pressed, #pushButton_3:pressed, #pushButton_4:pres"
                        "sed, #pushButton_5:pressed{\n"
"	padding-left:5px;\n"
"	padding-top:5px;\n"
"	color:rgba(91, 88, 53, 255);\n"
"}\n"
"\n"
""));
        label_12 = new QLabel(widget_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(40, 30, 280, 430));
        label_12->setStyleSheet(QLatin1String("border-image: url(:/images/background.jpg);\n"
"border-top-left-radius: 50px;"));
        label_13 = new QLabel(widget_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(40, 30, 280, 430));
        label_13->setStyleSheet(QLatin1String("\n"
"background-image: url(:/Downloads/loginc.jpg);\n"
"background-color:rgba(0, 0, 0, 80);\n"
"border-top-left-radius: 50px;"));
        label_14 = new QLabel(widget_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(270, 30, 240, 430));
        label_14->setStyleSheet(QLatin1String("background-color:rgba(255, 255, 255, 255);\n"
"border-bottom-right-radius: 50px;"));
        label_15 = new QLabel(widget_2);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(340, 80, 121, 40));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label_15->setFont(font);
        label_15->setStyleSheet(QLatin1String("color: rgb(98, 185, 203);\n"
"background-color:rgba(255, 255, 255, 255);"));
        hostnameC = new QLineEdit(widget_2);
        hostnameC->setObjectName(QStringLiteral("hostnameC"));
        hostnameC->setGeometry(QRect(295, 150, 190, 40));
        QFont font1;
        font1.setPointSize(10);
        hostnameC->setFont(font1);
        hostnameC->setStyleSheet(QLatin1String("background-color:rgba(0, 0, 0, 0);\n"
"border:none;\n"
"border-bottom:2px solid rgba(46, 82, 101, 200);\n"
"color:rgba(0, 0, 0, 240);\n"
"padding-bottom:7px;"));
        portC = new QLineEdit(widget_2);
        portC->setObjectName(QStringLiteral("portC"));
        portC->setGeometry(QRect(295, 215, 190, 40));
        portC->setFont(font1);
        portC->setStyleSheet(QLatin1String("background-color:rgba(0, 0, 0, 0);\n"
"border:none;\n"
"border-bottom:2px solid rgba(46, 82, 101, 200);\n"
"color:rgba(0, 0, 0, 240);\n"
"padding-bottom:7px;"));
        portC->setEchoMode(QLineEdit::Password);
        okC = new QPushButton(widget_2);
        okC->setObjectName(QStringLiteral("okC"));
        okC->setGeometry(QRect(300, 290, 181, 41));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setWeight(75);
        okC->setFont(font2);
        okC->setStyleSheet(QLatin1String("QPushButton{\n"
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
"}"));
        cancelC = new QPushButton(widget_2);
        cancelC->setObjectName(QStringLiteral("cancelC"));
        cancelC->setGeometry(QRect(300, 340, 181, 41));
        cancelC->setFont(font2);
        cancelC->setStyleSheet(QLatin1String("QPushButton{\n"
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
"}"));

        retranslateUi(LoginClient);

        QMetaObject::connectSlotsByName(LoginClient);
    } // setupUi

    void retranslateUi(QDialog *LoginClient)
    {
        LoginClient->setWindowTitle(QApplication::translate("LoginClient", "Dialog", Q_NULLPTR));
        label_12->setText(QString());
        label_13->setText(QString());
        label_14->setText(QString());
        label_15->setText(QApplication::translate("LoginClient", "Log In", Q_NULLPTR));
        hostnameC->setPlaceholderText(QApplication::translate("LoginClient", "  User Name", Q_NULLPTR));
        portC->setPlaceholderText(QApplication::translate("LoginClient", "  Password", Q_NULLPTR));
        okC->setText(QApplication::translate("LoginClient", "Connect", Q_NULLPTR));
        cancelC->setText(QApplication::translate("LoginClient", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoginClient: public Ui_LoginClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINCLIENT_H
