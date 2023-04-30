/********************************************************************************
** Form generated from reading UI file 'employe2.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYE2_H
#define UI_EMPLOYE2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_employe2
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *widget_3;
    QLabel *label_47;
    QPushButton *pushButtontri;
    QComboBox *comboBoxtri;
    QWidget *widget_2;
    QLabel *label_48;
    QLabel *label_49;
    QLabel *label_50;
    QLabel *label_51;
    QLabel *label_52;
    QLabel *label_53;
    QLabel *label_54;
    QLabel *label_59;
    QPushButton *pushButton_14;
    QPushButton *recherch_button;
    QScrollBar *verticalScrollBar_3;
    QLabel *label_61;
    QPushButton *pdf_button;
    QTableView *tab_employe;
    QLineEdit *line;
    QWidget *widget;
    QLabel *label_62;
    QLabel *label_63;
    QLabel *label_64;
    QLabel *label_65;
    QLabel *label_67;
    QLabel *label_68;
    QLineEdit *le_nom;
    QLineEdit *le_prenom;
    QLineEdit *le_cin;
    QLineEdit *le_salaire;
    QPushButton *pb_ajouter;
    QPushButton *pb_supprimer;
    QLabel *label_69;
    QLineEdit *le_metier;
    QPushButton *button_modifier;
    QComboBox *comboBox_SUPP;
    QPushButton *login2;
    QPushButton *stat;
    QLabel *label;
    QLabel *label_2;
    QWidget *tab_2;

    void setupUi(QWidget *employe2)
    {
        if (employe2->objectName().isEmpty())
            employe2->setObjectName(QStringLiteral("employe2"));
        employe2->resize(1446, 716);
        tabWidget = new QTabWidget(employe2);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 0, 1431, 601));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        widget_3 = new QWidget(tab);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(550, 480, 431, 51));
        label_47 = new QLabel(widget_3);
        label_47->setObjectName(QStringLiteral("label_47"));
        label_47->setGeometry(QRect(20, 10, 121, 21));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        label_47->setFont(font);
        label_47->setStyleSheet(QLatin1String("QLabel{\n"
"	\n"
"	qproperty-icon: url(:/Downloads/trier.png);\n"
"	qproperty-iconSize: 30px 30 px;\n"
"text-align:center;\n"
"	color: rgb(27, 75, 101);\n"
"}"));
        pushButtontri = new QPushButton(widget_3);
        pushButtontri->setObjectName(QStringLiteral("pushButtontri"));
        pushButtontri->setGeometry(QRect(340, 10, 75, 23));
        pushButtontri->setStyleSheet(QLatin1String("QPushButton{\n"
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
        comboBoxtri = new QComboBox(widget_3);
        comboBoxtri->setObjectName(QStringLiteral("comboBoxtri"));
        comboBoxtri->setGeometry(QRect(130, 10, 191, 22));
        widget_2 = new QWidget(tab);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(330, 40, 1051, 271));
        label_48 = new QLabel(widget_2);
        label_48->setObjectName(QStringLiteral("label_48"));
        label_48->setGeometry(QRect(20, 50, 1011, 31));
        label_48->setStyleSheet(QLatin1String("border-radius:10px;\n"
"background-color: rgb(190, 233, 231);"));
        label_49 = new QLabel(widget_2);
        label_49->setObjectName(QStringLiteral("label_49"));
        label_49->setGeometry(QRect(20, 20, 261, 21));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setUnderline(false);
        font1.setWeight(75);
        label_49->setFont(font1);
        label_49->setStyleSheet(QStringLiteral("color: rgb(27, 75, 101);"));
        label_50 = new QLabel(widget_2);
        label_50->setObjectName(QStringLiteral("label_50"));
        label_50->setGeometry(QRect(40, 60, 47, 14));
        QFont font2;
        font2.setBold(true);
        font2.setUnderline(false);
        font2.setWeight(75);
        label_50->setFont(font2);
        label_50->setStyleSheet(QStringLiteral("color: rgb(27, 75, 101);"));
        label_51 = new QLabel(widget_2);
        label_51->setObjectName(QStringLiteral("label_51"));
        label_51->setGeometry(QRect(140, 60, 61, 16));
        label_51->setFont(font2);
        label_51->setStyleSheet(QStringLiteral("color: rgb(27, 75, 101);"));
        label_52 = new QLabel(widget_2);
        label_52->setObjectName(QStringLiteral("label_52"));
        label_52->setGeometry(QRect(240, 60, 71, 16));
        label_52->setFont(font2);
        label_52->setStyleSheet(QStringLiteral("color: rgb(27, 75, 101);"));
        label_53 = new QLabel(widget_2);
        label_53->setObjectName(QStringLiteral("label_53"));
        label_53->setGeometry(QRect(440, 60, 47, 14));
        label_53->setFont(font2);
        label_53->setStyleSheet(QStringLiteral("color: rgb(27, 75, 101);"));
        label_54 = new QLabel(widget_2);
        label_54->setObjectName(QStringLiteral("label_54"));
        label_54->setGeometry(QRect(590, 60, 47, 14));
        label_54->setFont(font2);
        label_54->setStyleSheet(QStringLiteral("color: rgb(27, 75, 101);"));
        label_59 = new QLabel(widget_2);
        label_59->setObjectName(QStringLiteral("label_59"));
        label_59->setGeometry(QRect(720, 60, 47, 14));
        QFont font3;
        font3.setBold(true);
        font3.setWeight(75);
        label_59->setFont(font3);
        label_59->setStyleSheet(QStringLiteral("color: rgb(27, 75, 101);"));
        pushButton_14 = new QPushButton(widget_2);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setGeometry(QRect(710, 20, 31, 21));
        pushButton_14->setStyleSheet(QLatin1String("QPushButton{\n"
"	\n"
"	border-image: url(:/Downloads/326396841_708570531015679_44119472664975908_n.png);\n"
"\n"
"}"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Downloads/326396841_708570531015679_44119472664975908_n.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_14->setIcon(icon);
        recherch_button = new QPushButton(widget_2);
        recherch_button->setObjectName(QStringLiteral("recherch_button"));
        recherch_button->setGeometry(QRect(760, 20, 21, 21));
        recherch_button->setStyleSheet(QLatin1String("QPushButton{\n"
"	\n"
"	border-image: url(:/Downloads/254293109_1118342951903609_3135421941897853154_n.png);\n"
"}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Downloads/254293109_1118342951903609_3135421941897853154_n.png"), QSize(), QIcon::Normal, QIcon::Off);
        recherch_button->setIcon(icon1);
        verticalScrollBar_3 = new QScrollBar(widget_2);
        verticalScrollBar_3->setObjectName(QStringLiteral("verticalScrollBar_3"));
        verticalScrollBar_3->setGeometry(QRect(1030, 80, 16, 160));
        verticalScrollBar_3->setOrientation(Qt::Vertical);
        label_61 = new QLabel(widget_2);
        label_61->setObjectName(QStringLiteral("label_61"));
        label_61->setGeometry(QRect(340, 60, 61, 16));
        label_61->setFont(font2);
        label_61->setStyleSheet(QStringLiteral("color: rgb(27, 75, 101);"));
        pdf_button = new QPushButton(widget_2);
        pdf_button->setObjectName(QStringLiteral("pdf_button"));
        pdf_button->setGeometry(QRect(280, 20, 41, 31));
        pdf_button->setStyleSheet(QLatin1String("QPushButton{\n"
"	\n"
"	border-image: url(:/Downloads/271308060_654389075566817_8511874093532438792_n.png);\n"
"}"));
        tab_employe = new QTableView(widget_2);
        tab_employe->setObjectName(QStringLiteral("tab_employe"));
        tab_employe->setGeometry(QRect(0, 80, 891, 171));
        line = new QLineEdit(widget_2);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(800, 20, 113, 20));
        line->setStyleSheet(QStringLiteral(""));
        widget = new QWidget(tab);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 40, 321, 391));
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
        label_62 = new QLabel(widget);
        label_62->setObjectName(QStringLiteral("label_62"));
        label_62->setGeometry(QRect(20, 20, 281, 351));
        label_62->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"border-radius:20px;\n"
"\n"
""));
        label_63 = new QLabel(widget);
        label_63->setObjectName(QStringLiteral("label_63"));
        label_63->setGeometry(QRect(110, 30, 171, 61));
        QFont font4;
        font4.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font4.setPointSize(16);
        font4.setBold(true);
        font4.setItalic(false);
        font4.setUnderline(false);
        font4.setWeight(75);
        font4.setStrikeOut(false);
        font4.setKerning(true);
        label_63->setFont(font4);
        label_63->setStyleSheet(QLatin1String("\n"
"color: rgb(27, 75, 101);\n"
""));
        label_64 = new QLabel(widget);
        label_64->setObjectName(QStringLiteral("label_64"));
        label_64->setGeometry(QRect(40, 110, 47, 14));
        label_64->setFont(font3);
        label_64->setStyleSheet(QStringLiteral("color: rgb(27, 75, 101);"));
        label_65 = new QLabel(widget);
        label_65->setObjectName(QStringLiteral("label_65"));
        label_65->setGeometry(QRect(170, 110, 51, 16));
        label_65->setFont(font3);
        label_65->setStyleSheet(QStringLiteral("color: rgb(27, 75, 101);"));
        label_67 = new QLabel(widget);
        label_67->setObjectName(QStringLiteral("label_67"));
        label_67->setGeometry(QRect(140, 180, 51, 16));
        label_67->setFont(font3);
        label_67->setStyleSheet(QStringLiteral("color: rgb(27, 75, 101);"));
        label_68 = new QLabel(widget);
        label_68->setObjectName(QStringLiteral("label_68"));
        label_68->setGeometry(QRect(40, 250, 47, 14));
        label_68->setFont(font3);
        label_68->setStyleSheet(QStringLiteral("color: rgb(27, 75, 101);"));
        le_nom = new QLineEdit(widget);
        le_nom->setObjectName(QStringLiteral("le_nom"));
        le_nom->setGeometry(QRect(40, 130, 113, 20));
        le_nom->setStyleSheet(QStringLiteral(""));
        le_prenom = new QLineEdit(widget);
        le_prenom->setObjectName(QStringLiteral("le_prenom"));
        le_prenom->setGeometry(QRect(170, 130, 113, 20));
        le_cin = new QLineEdit(widget);
        le_cin->setObjectName(QStringLiteral("le_cin"));
        le_cin->setGeometry(QRect(100, 210, 113, 20));
        le_salaire = new QLineEdit(widget);
        le_salaire->setObjectName(QStringLiteral("le_salaire"));
        le_salaire->setGeometry(QRect(40, 270, 113, 20));
        pb_ajouter = new QPushButton(widget);
        pb_ajouter->setObjectName(QStringLiteral("pb_ajouter"));
        pb_ajouter->setGeometry(QRect(210, 290, 75, 23));
        pb_ajouter->setStyleSheet(QLatin1String("QPushButton{\n"
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
        pb_supprimer = new QPushButton(widget);
        pb_supprimer->setObjectName(QStringLiteral("pb_supprimer"));
        pb_supprimer->setGeometry(QRect(60, 330, 75, 23));
        pb_supprimer->setStyleSheet(QLatin1String("QPushButton{\n"
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
        label_69 = new QLabel(widget);
        label_69->setObjectName(QStringLiteral("label_69"));
        label_69->setGeometry(QRect(210, 240, 47, 14));
        label_69->setFont(font3);
        label_69->setStyleSheet(QStringLiteral("color: rgb(27, 75, 101);"));
        le_metier = new QLineEdit(widget);
        le_metier->setObjectName(QStringLiteral("le_metier"));
        le_metier->setGeometry(QRect(170, 270, 113, 20));
        button_modifier = new QPushButton(widget);
        button_modifier->setObjectName(QStringLiteral("button_modifier"));
        button_modifier->setGeometry(QRect(30, 290, 75, 23));
        button_modifier->setStyleSheet(QLatin1String("QPushButton{\n"
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
        comboBox_SUPP = new QComboBox(widget);
        comboBox_SUPP->setObjectName(QStringLiteral("comboBox_SUPP"));
        comboBox_SUPP->setGeometry(QRect(170, 330, 73, 22));
        login2 = new QPushButton(tab);
        login2->setObjectName(QStringLiteral("login2"));
        login2->setGeometry(QRect(1200, 350, 75, 23));
        login2->setStyleSheet(QLatin1String("QPushButton{\n"
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
        stat = new QPushButton(tab);
        stat->setObjectName(QStringLiteral("stat"));
        stat->setGeometry(QRect(1080, 350, 75, 23));
        stat->setStyleSheet(QLatin1String("QPushButton{\n"
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
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(350, 330, 71, 16));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(430, 330, 56, 16));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());

        retranslateUi(employe2);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(employe2);
    } // setupUi

    void retranslateUi(QWidget *employe2)
    {
        employe2->setWindowTitle(QApplication::translate("employe2", "Form", Q_NULLPTR));
        label_47->setText(QApplication::translate("employe2", "Trier par", Q_NULLPTR));
        pushButtontri->setText(QApplication::translate("employe2", "Trier", Q_NULLPTR));
        label_48->setText(QString());
        label_49->setText(QApplication::translate("employe2", "Liste des employees", Q_NULLPTR));
        label_50->setText(QApplication::translate("employe2", "Nom", Q_NULLPTR));
        label_51->setText(QApplication::translate("employe2", "prenom", Q_NULLPTR));
        label_52->setText(QApplication::translate("employe2", "cin", Q_NULLPTR));
        label_53->setText(QApplication::translate("employe2", "salairel", Q_NULLPTR));
        label_54->setText(QApplication::translate("employe2", "metier", Q_NULLPTR));
        label_59->setText(QApplication::translate("employe2", "#", Q_NULLPTR));
        pushButton_14->setText(QString());
        recherch_button->setText(QString());
        label_61->setText(QApplication::translate("employe2", "Adresse", Q_NULLPTR));
        pdf_button->setText(QString());
        label_62->setText(QString());
        label_63->setText(QApplication::translate("employe2", "Formulaire", Q_NULLPTR));
        label_64->setText(QApplication::translate("employe2", "Nom", Q_NULLPTR));
        label_65->setText(QApplication::translate("employe2", "Prenom", Q_NULLPTR));
        label_67->setText(QApplication::translate("employe2", "CIN", Q_NULLPTR));
        label_68->setText(QApplication::translate("employe2", "Salaire", Q_NULLPTR));
        pb_ajouter->setText(QApplication::translate("employe2", "Ajouter", Q_NULLPTR));
        pb_supprimer->setText(QApplication::translate("employe2", "supprimer", Q_NULLPTR));
        label_69->setText(QApplication::translate("employe2", "Metier", Q_NULLPTR));
        button_modifier->setText(QApplication::translate("employe2", "modifier", Q_NULLPTR));
        login2->setText(QApplication::translate("employe2", "login", Q_NULLPTR));
        stat->setText(QApplication::translate("employe2", "stat", Q_NULLPTR));
        label->setText(QApplication::translate("employe2", "Detection:", Q_NULLPTR));
        label_2->setText(QApplication::translate("employe2", "off", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("employe2", "Tab 1", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("employe2", "Tab 2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class employe2: public Ui_employe2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYE2_H
