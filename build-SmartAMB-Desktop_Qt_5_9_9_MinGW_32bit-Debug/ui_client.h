/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_client
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *widget_2;
    QLabel *label_9;
    QPushButton *pb_pdfC;
    QLineEdit *rechercherC;
    QPushButton *pushButton_16;
    QTableView *tab_clients;
    QWidget *widget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *nomc;
    QPushButton *pb_ajouterC;
    QPushButton *pb_modififerC;
    QLineEdit *cinc;
    QLineEdit *adressec;
    QLineEdit *emailc;
    QLineEdit *phonec;
    QLineEdit *cinc_2;
    QLineEdit *sexec;
    QLabel *label_10;
    QWidget *widget_3;
    QLabel *label_25;
    QPushButton *pb_trierC;
    QComboBox *comboBox_tri;
    QPushButton *pushButton_7;
    QLabel *label_8;
    QPushButton *pb_suppc;
    QLabel *label_17;
    QComboBox *comboBox_suppC;
    QWidget *widget_4;
    QPushButton *pb_ONC;
    QPushButton *pb_OFFC;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *etatardC;
    QWidget *chatbox;
    QPushButton *pb_hisC;
    QTextBrowser *history;
    QWidget *tab_2;
    QFrame *horizontalFrame;
    QHBoxLayout *horizontalLayout;
    QPushButton *pb_statC;

    void setupUi(QDialog *client)
    {
        if (client->objectName().isEmpty())
            client->setObjectName(QStringLiteral("client"));
        client->resize(1229, 609);
        client->setStyleSheet(QStringLiteral("background-color: rgb(243, 243, 243);"));
        tabWidget = new QTabWidget(client);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(50, 30, 1141, 551));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        widget_2 = new QWidget(tab);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(360, 20, 761, 391));
        label_9 = new QLabel(widget_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(40, 40, 191, 21));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setUnderline(false);
        font.setWeight(75);
        label_9->setFont(font);
        label_9->setStyleSheet(QStringLiteral("color: rgb(27, 75, 101);"));
        pb_pdfC = new QPushButton(widget_2);
        pb_pdfC->setObjectName(QStringLiteral("pb_pdfC"));
        pb_pdfC->setGeometry(QRect(240, 30, 31, 31));
        pb_pdfC->setStyleSheet(QLatin1String("QPushButton{\n"
"	\n"
"	\n"
"	border-image: url(:/Downloads/pdf (1).png);\n"
"}"));
        rechercherC = new QLineEdit(widget_2);
        rechercherC->setObjectName(QStringLiteral("rechercherC"));
        rechercherC->setGeometry(QRect(440, 30, 211, 31));
        rechercherC->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border:none;\n"
"border-radius:5px;\n"
"color: rgb(27, 75, 101);\n"
""));
        rechercherC->setClearButtonEnabled(false);
        pushButton_16 = new QPushButton(widget_2);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        pushButton_16->setGeometry(QRect(660, 40, 20, 20));
        pushButton_16->setStyleSheet(QLatin1String("QPushButton{\n"
"	\n"
"	border-image: url(:/Downloads/loupe.png);\n"
"}"));
        tab_clients = new QTableView(widget_2);
        tab_clients->setObjectName(QStringLiteral("tab_clients"));
        tab_clients->setGeometry(QRect(40, 70, 641, 291));
        widget = new QWidget(tab);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 20, 351, 391));
        widget->setStyleSheet(QLatin1String("QPushButton #pushButton{\n"
"	\n"
"	background-color: rgb(98, 185, 203);\n"
"	color: rgb(255, 255, 255);\n"
"	border-radius:5px;\n"
"}\n"
"QPushButton #pushButton:hover{\n"
"	\n"
"	background-color: rgb(98, 185, 203);\n"
"}\n"
"QPushButton #pushButtonp:pressed{\n"
"	padding-left:5px;\n"
"	padding-top:5px;\n"
"	background-color: rgb(98, 185, 203);\n"
"}"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 311, 351));
        label->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-radius:20px;\n"
"\n"
""));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(110, 30, 171, 61));
        QFont font1;
        font1.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setWeight(75);
        font1.setStrikeOut(false);
        font1.setKerning(true);
        label_2->setFont(font1);
        label_2->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(27, 75, 101);\n"
""));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 110, 47, 14));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        label_3->setFont(font2);
        label_3->setStyleSheet(QLatin1String("color: rgb(27, 75, 101);\n"
"background-color: rgb(255, 255, 255);"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(200, 110, 47, 14));
        label_4->setFont(font2);
        label_4->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(27, 75, 101);"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(40, 180, 61, 16));
        label_5->setFont(font2);
        label_5->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);color: rgb(27, 75, 101);"));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(200, 180, 47, 14));
        label_6->setFont(font2);
        label_6->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);color: rgb(27, 75, 101);"));
        label_7 = new QLabel(widget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(40, 250, 47, 14));
        label_7->setFont(font2);
        label_7->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);color: rgb(27, 75, 101);"));
        nomc = new QLineEdit(widget);
        nomc->setObjectName(QStringLiteral("nomc"));
        nomc->setGeometry(QRect(40, 130, 113, 20));
        nomc->setStyleSheet(QLatin1String("\n"
"border:none;\n"
"border-radius:5px;\n"
"color: black"));
        pb_ajouterC = new QPushButton(widget);
        pb_ajouterC->setObjectName(QStringLiteral("pb_ajouterC"));
        pb_ajouterC->setGeometry(QRect(100, 320, 75, 23));
        pb_ajouterC->setStyleSheet(QLatin1String("QPushButton{\n"
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
        pb_modififerC = new QPushButton(widget);
        pb_modififerC->setObjectName(QStringLiteral("pb_modififerC"));
        pb_modififerC->setGeometry(QRect(190, 320, 75, 23));
        pb_modififerC->setStyleSheet(QLatin1String("QPushButton{\n"
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
        cinc = new QLineEdit(widget);
        cinc->setObjectName(QStringLiteral("cinc"));
        cinc->setGeometry(QRect(200, 130, 113, 20));
        cinc->setStyleSheet(QLatin1String("\n"
"border:none;\n"
"border-radius:5px;\n"
"color: black"));
        adressec = new QLineEdit(widget);
        adressec->setObjectName(QStringLiteral("adressec"));
        adressec->setGeometry(QRect(40, 200, 113, 20));
        adressec->setStyleSheet(QLatin1String("\n"
"border:none;\n"
"border-radius:5px;\n"
"color: black"));
        emailc = new QLineEdit(widget);
        emailc->setObjectName(QStringLiteral("emailc"));
        emailc->setGeometry(QRect(200, 200, 113, 20));
        emailc->setStyleSheet(QLatin1String("\n"
"border:none;\n"
"border-radius:5px;\n"
"color: black"));
        phonec = new QLineEdit(widget);
        phonec->setObjectName(QStringLiteral("phonec"));
        phonec->setGeometry(QRect(40, 270, 113, 20));
        phonec->setStyleSheet(QLatin1String("\n"
"border:none;\n"
"border-radius:5px;\n"
"color: black"));
        cinc_2 = new QLineEdit(widget);
        cinc_2->setObjectName(QStringLiteral("cinc_2"));
        cinc_2->setGeometry(QRect(80, 450, 113, 20));
        cinc_2->setStyleSheet(QLatin1String("\n"
"border:none;\n"
"border-radius:5px;\n"
"color: black"));
        sexec = new QLineEdit(widget);
        sexec->setObjectName(QStringLiteral("sexec"));
        sexec->setGeometry(QRect(200, 270, 113, 20));
        sexec->setStyleSheet(QLatin1String("\n"
"border:none;\n"
"border-radius:5px;\n"
"color: black"));
        label_10 = new QLabel(widget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(200, 250, 47, 14));
        label_10->setFont(font2);
        label_10->setStyleSheet(QLatin1String("color: rgb(27, 75, 101);\n"
"background-color: rgb(255, 255, 255);"));
        widget_3 = new QWidget(tab);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(360, 420, 431, 51));
        label_25 = new QLabel(widget_3);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(20, 10, 121, 21));
        QFont font3;
        font3.setPointSize(15);
        font3.setBold(true);
        font3.setWeight(75);
        label_25->setFont(font3);
        label_25->setStyleSheet(QLatin1String("QLabel{\n"
"	\n"
"	qproperty-icon: url(:/Downloads/trier.png);\n"
"	qproperty-iconSize: 30px 30 px;\n"
"text-align:center;\n"
"	color: rgb(27, 75, 101);\n"
"}"));
        pb_trierC = new QPushButton(widget_3);
        pb_trierC->setObjectName(QStringLiteral("pb_trierC"));
        pb_trierC->setGeometry(QRect(340, 10, 75, 23));
        pb_trierC->setStyleSheet(QLatin1String("QPushButton{\n"
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
        comboBox_tri = new QComboBox(widget_3);
        comboBox_tri->setObjectName(QStringLiteral("comboBox_tri"));
        comboBox_tri->setGeometry(QRect(130, 10, 191, 22));
        comboBox_tri->setStyleSheet(QStringLiteral("color: rgb(27, 75, 101);"));
        pushButton_7 = new QPushButton(tab);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(800, 430, 75, 23));
        pushButton_7->setStyleSheet(QLatin1String("QPushButton{\n"
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
        label_8 = new QLabel(tab);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 420, 311, 71));
        label_8->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-radius:20px;\n"
"\n"
""));
        pb_suppc = new QPushButton(tab);
        pb_suppc->setObjectName(QStringLiteral("pb_suppc"));
        pb_suppc->setGeometry(QRect(270, 450, 21, 21));
        pb_suppc->setStyleSheet(QLatin1String("QPushButton{\n"
"	border-image: url(:/Downloads/bouton-supprimer.png);\n"
"color:white;\n"
"}"));
        label_17 = new QLabel(tab);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(70, 430, 47, 14));
        label_17->setFont(font2);
        label_17->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(27, 75, 101);"));
        comboBox_suppC = new QComboBox(tab);
        comboBox_suppC->setObjectName(QStringLiteral("comboBox_suppC"));
        comboBox_suppC->setGeometry(QRect(70, 450, 181, 22));
        widget_4 = new QWidget(tab);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setGeometry(QRect(890, 420, 231, 80));
        pb_ONC = new QPushButton(widget_4);
        pb_ONC->setObjectName(QStringLiteral("pb_ONC"));
        pb_ONC->setGeometry(QRect(90, 10, 41, 23));
        pb_ONC->setStyleSheet(QLatin1String("QPushButton{\n"
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
        pb_OFFC = new QPushButton(widget_4);
        pb_OFFC->setObjectName(QStringLiteral("pb_OFFC"));
        pb_OFFC->setGeometry(QRect(140, 10, 41, 23));
        pb_OFFC->setStyleSheet(QLatin1String("QPushButton{\n"
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
        label_11 = new QLabel(widget_4);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 10, 61, 16));
        QFont font4;
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setWeight(75);
        label_11->setFont(font4);
        label_11->setStyleSheet(QLatin1String("color: rgb(27, 75, 101);\n"
""));
        label_12 = new QLabel(widget_4);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 50, 61, 16));
        label_12->setFont(font4);
        label_12->setStyleSheet(QLatin1String("color: rgb(27, 75, 101);\n"
""));
        etatardC = new QLabel(widget_4);
        etatardC->setObjectName(QStringLiteral("etatardC"));
        etatardC->setGeometry(QRect(80, 50, 121, 16));
        QFont font5;
        font5.setPointSize(10);
        font5.setBold(true);
        font5.setWeight(75);
        etatardC->setFont(font5);
        etatardC->setStyleSheet(QLatin1String("color: rgb(27, 75, 101);\n"
""));
        tabWidget->addTab(tab, QString());
        chatbox = new QWidget();
        chatbox->setObjectName(QStringLiteral("chatbox"));
        pb_hisC = new QPushButton(chatbox);
        pb_hisC->setObjectName(QStringLiteral("pb_hisC"));
        pb_hisC->setGeometry(QRect(850, 100, 91, 31));
        pb_hisC->setStyleSheet(QLatin1String("QPushButton{\n"
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
        history = new QTextBrowser(chatbox);
        history->setObjectName(QStringLiteral("history"));
        history->setGeometry(QRect(240, 100, 571, 331));
        tabWidget->addTab(chatbox, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        horizontalFrame = new QFrame(tab_2);
        horizontalFrame->setObjectName(QStringLiteral("horizontalFrame"));
        horizontalFrame->setGeometry(QRect(50, 20, 771, 481));
        horizontalLayout = new QHBoxLayout(horizontalFrame);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pb_statC = new QPushButton(tab_2);
        pb_statC->setObjectName(QStringLiteral("pb_statC"));
        pb_statC->setGeometry(QRect(870, 50, 75, 23));
        pb_statC->setStyleSheet(QLatin1String("QPushButton{\n"
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
        tabWidget->addTab(tab_2, QString());

        retranslateUi(client);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(client);
    } // setupUi

    void retranslateUi(QDialog *client)
    {
        client->setWindowTitle(QApplication::translate("client", "Dialog", Q_NULLPTR));
        label_9->setText(QApplication::translate("client", "Liste des Clients", Q_NULLPTR));
        pb_pdfC->setText(QString());
        rechercherC->setPlaceholderText(QApplication::translate("client", "rechercher", Q_NULLPTR));
        pushButton_16->setText(QString());
        label->setText(QString());
        label_2->setText(QApplication::translate("client", "Formulaire", Q_NULLPTR));
        label_3->setText(QApplication::translate("client", "Nom", Q_NULLPTR));
        label_4->setText(QApplication::translate("client", "CIN", Q_NULLPTR));
        label_5->setText(QApplication::translate("client", "Adresse", Q_NULLPTR));
        label_6->setText(QApplication::translate("client", "Email", Q_NULLPTR));
        label_7->setText(QApplication::translate("client", "Phone", Q_NULLPTR));
        pb_ajouterC->setText(QApplication::translate("client", "Ajouter", Q_NULLPTR));
        pb_modififerC->setText(QApplication::translate("client", "Modifier", Q_NULLPTR));
        label_10->setText(QApplication::translate("client", "Sexe", Q_NULLPTR));
        label_25->setText(QApplication::translate("client", "Trier par", Q_NULLPTR));
        pb_trierC->setText(QApplication::translate("client", "Trier", Q_NULLPTR));
        comboBox_tri->clear();
        comboBox_tri->insertItems(0, QStringList()
         << QApplication::translate("client", "ALL", Q_NULLPTR)
         << QApplication::translate("client", "par CIN", Q_NULLPTR)
         << QApplication::translate("client", "par Nom", Q_NULLPTR)
         << QApplication::translate("client", "par Adresse", Q_NULLPTR)
        );
        pushButton_7->setText(QApplication::translate("client", "chatbox", Q_NULLPTR));
        label_8->setText(QString());
        pb_suppc->setText(QString());
        label_17->setText(QApplication::translate("client", "CIN", Q_NULLPTR));
        pb_ONC->setText(QApplication::translate("client", "ON", Q_NULLPTR));
        pb_OFFC->setText(QApplication::translate("client", "OFF", Q_NULLPTR));
        label_11->setText(QApplication::translate("client", "Buzzer", Q_NULLPTR));
        label_12->setText(QApplication::translate("client", "Etat :", Q_NULLPTR));
        etatardC->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("client", "Clients", Q_NULLPTR));
        pb_hisC->setText(QApplication::translate("client", "valider", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(chatbox), QApplication::translate("client", "Histrorique", Q_NULLPTR));
        pb_statC->setText(QApplication::translate("client", "stat", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("client", "Statistique", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class client: public Ui_client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
