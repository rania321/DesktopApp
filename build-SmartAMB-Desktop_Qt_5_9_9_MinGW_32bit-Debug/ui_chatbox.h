/********************************************************************************
** Form generated from reading UI file 'chatbox.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATBOX_H
#define UI_CHATBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_chatbox
{
public:
    QLineEdit *nicknameC;
    QLineEdit *messageC;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *sendC;
    QTextEdit *textEditC;
    QPushButton *bindC;

    void setupUi(QDialog *chatbox)
    {
        if (chatbox->objectName().isEmpty())
            chatbox->setObjectName(QStringLiteral("chatbox"));
        chatbox->resize(629, 556);
        chatbox->setStyleSheet(QStringLiteral("background-color: rgb(243, 243, 243);"));
        nicknameC = new QLineEdit(chatbox);
        nicknameC->setObjectName(QStringLiteral("nicknameC"));
        nicknameC->setGeometry(QRect(100, 60, 311, 31));
        nicknameC->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border:none;\n"
"border-radius:15px;\n"
"color: rgb(27, 75, 101);\n"
""));
        messageC = new QLineEdit(chatbox);
        messageC->setObjectName(QStringLiteral("messageC"));
        messageC->setGeometry(QRect(100, 500, 441, 31));
        messageC->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border:none;\n"
"border-radius:15px;\n"
"color: rgb(27, 75, 101);\n"
""));
        label_2 = new QLabel(chatbox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(280, 0, 131, 51));
        QFont font;
        font.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font.setPointSize(16);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(75);
        font.setStrikeOut(false);
        font.setKerning(true);
        label_2->setFont(font);
        label_2->setStyleSheet(QLatin1String("background-color: rgb(243, 243, 243);\n"
"color: rgb(27, 75, 101);\n"
""));
        label_3 = new QLabel(chatbox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 70, 71, 20));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        label_3->setFont(font1);
        label_3->setStyleSheet(QLatin1String("color: rgb(27, 75, 101);\n"
"background-color: rgb(243, 243, 243);"));
        label_4 = new QLabel(chatbox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 500, 71, 20));
        label_4->setFont(font1);
        label_4->setStyleSheet(QLatin1String("color: rgb(27, 75, 101);\n"
"background-color: rgb(243, 243, 243);"));
        sendC = new QPushButton(chatbox);
        sendC->setObjectName(QStringLiteral("sendC"));
        sendC->setGeometry(QRect(560, 500, 31, 31));
        sendC->setStyleSheet(QLatin1String("QPushButton{\n"
"border-radius:10px;\n"
"	\n"
"	background-color: rgb(255, 255, 255);\n"
"	\n"
"	border-image: url(:/Downloads/paper-plane.png);\n"
"}"));
        textEditC = new QTextEdit(chatbox);
        textEditC->setObjectName(QStringLiteral("textEditC"));
        textEditC->setGeometry(QRect(100, 110, 491, 371));
        textEditC->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border:none;\n"
"border-radius:15px;\n"
"color :rgb(27, 75, 101);"));
        bindC = new QPushButton(chatbox);
        bindC->setObjectName(QStringLiteral("bindC"));
        bindC->setGeometry(QRect(530, 50, 51, 51));
        bindC->setStyleSheet(QLatin1String("QPushButton{\n"
"	\n"
"	\n"
"	border-image: url(:/Downloads/connexion.png);\n"
"}"));

        retranslateUi(chatbox);

        QMetaObject::connectSlotsByName(chatbox);
    } // setupUi

    void retranslateUi(QDialog *chatbox)
    {
        chatbox->setWindowTitle(QApplication::translate("chatbox", "Dialog", Q_NULLPTR));
        nicknameC->setPlaceholderText(QString());
        messageC->setPlaceholderText(QString());
        label_2->setText(QApplication::translate("chatbox", "CHAT", Q_NULLPTR));
        label_3->setText(QApplication::translate("chatbox", "Surnom", Q_NULLPTR));
        label_4->setText(QApplication::translate("chatbox", "Message", Q_NULLPTR));
        sendC->setText(QString());
        bindC->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class chatbox: public Ui_chatbox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATBOX_H
