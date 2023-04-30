/********************************************************************************
** Form generated from reading UI file 'login2.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN2_H
#define UI_LOGIN2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login2
{
public:
    QWidget *widget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *use2_edit;
    QLineEdit *pas_edit;
    QPushButton *pushButtonlogin2;
    QLabel *label_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;

    void setupUi(QWidget *login2)
    {
        if (login2->objectName().isEmpty())
            login2->setObjectName(QStringLiteral("login2"));
        login2->resize(1160, 682);
        widget = new QWidget(login2);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 30, 370, 480));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 40, 300, 420));
        label->setStyleSheet(QLatin1String("border-image: url(:/Pictures/Saved Pictures/photo-1554734867-bf3c00a49371.jfif);\n"
"border-radius:20px;"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 50, 280, 390));
        label_2->setStyleSheet(QLatin1String("background-color:rgba(0,0,0,100);\n"
"border-radius:15px;"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(135, 95, 111, 40));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label_3->setFont(font);
        label_3->setStyleSheet(QStringLiteral("color:rgba(255,255,255,210);"));
        use2_edit = new QLineEdit(widget);
        use2_edit->setObjectName(QStringLiteral("use2_edit"));
        use2_edit->setGeometry(QRect(80, 165, 200, 40));
        QFont font1;
        font1.setPointSize(10);
        use2_edit->setFont(font1);
        use2_edit->setStyleSheet(QLatin1String("background-color:rgba(0,0,0,0);\n"
"border:none;\n"
"border-bottom:2px solid rgba(105,118,132,255);\n"
"padding-bottom:7px;"));
        pas_edit = new QLineEdit(widget);
        pas_edit->setObjectName(QStringLiteral("pas_edit"));
        pas_edit->setGeometry(QRect(80, 230, 200, 40));
        pas_edit->setFont(font1);
        pas_edit->setStyleSheet(QLatin1String("background-color:rgba(0,0,0,0);\n"
"border:none;\n"
"border-bottom:2px solid rgba(105,118,132,255);\n"
"padding-bottom:7px;"));
        pas_edit->setEchoMode(QLineEdit::Password);
        pushButtonlogin2 = new QPushButton(widget);
        pushButtonlogin2->setObjectName(QStringLiteral("pushButtonlogin2"));
        pushButtonlogin2->setGeometry(QRect(80, 310, 200, 40));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        pushButtonlogin2->setFont(font2);
        pushButtonlogin2->setStyleSheet(QLatin1String("QpushButton#pushButton{\n"
"background-color:qlineargradient(spread:pad, x1:0, y1:0.505682 x2:1, y2:0.477, stop:0 rgba(20, 47, 78, 219), stop:1 rgba(85, 98, 112, 226));\n"
"color:rgba(255,255,255,210);\n"
"border-radius:10px;\n"
"}\n"
"QpushButton#pushButton:hover{\n"
"background-color:qlineargradient(spread:pad, x1:0, y1:0.505682 , x2:1, y2:0.477, stop:0 rgba(40, 67, 98, 219), stop:1 rgba(105, 118, 132, 226));\n"
"}\n"
"QpushButton#pushButton:pressed{\n"
"padding-left:5px;\n"
"padding-top:5px;\n"
"background-color:rgba(105,118,132,200);\n"
"\n"
"}"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(70, 360, 231, 20));
        label_4->setStyleSheet(QStringLiteral("color:rgba(255,255,255,140);"));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(70, 390, 30, 30));
        QFont font3;
        font3.setFamily(QStringLiteral("Source Code Pro"));
        font3.setPointSize(15);
        pushButton_2->setFont(font3);
        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(120, 390, 30, 30));
        pushButton_3->setFont(font3);
        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(160, 390, 30, 30));
        pushButton_4->setFont(font3);
        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(210, 390, 30, 30));
        pushButton_5->setFont(font3);

        retranslateUi(login2);

        QMetaObject::connectSlotsByName(login2);
    } // setupUi

    void retranslateUi(QWidget *login2)
    {
        login2->setWindowTitle(QApplication::translate("login2", "Form", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QApplication::translate("login2", "Log In", Q_NULLPTR));
        use2_edit->setPlaceholderText(QApplication::translate("login2", "User Name", Q_NULLPTR));
        pas_edit->setPlaceholderText(QApplication::translate("login2", "Password", Q_NULLPTR));
        pushButtonlogin2->setText(QApplication::translate("login2", "log In", Q_NULLPTR));
        label_4->setText(QApplication::translate("login2", "Forgot your user Name or Password ?", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("login2", "E", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("login2", "E", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("login2", "E", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("login2", "E", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class login2: public Ui_login2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN2_H
