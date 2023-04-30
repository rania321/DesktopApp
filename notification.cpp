#include "notification.h"
#include <QSystemTrayIcon>
#include<QString>
notification::notification()
{

}

void notification::notification_ajouteremploye()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/USER/Desktop/notif.png"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des employées ","nouveau employé est ajouté ",QSystemTrayIcon::Information,15000);
}
void notification::notification_supprimeremploye(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

notifyIcon->setIcon(QIcon("C:/Users/USER/Desktop/notif.png"));
notifyIcon->show();
    notifyIcon->showMessage("Gestion des  employé ","Un  employe est supprimé",QSystemTrayIcon::Information,15000);
}
void notification::notification_modifieremploye(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

notifyIcon->setIcon(QIcon("C:/Users/USER/Desktop/notif.png"));

notifyIcon->show();
    notifyIcon->showMessage("Gestion des  employé ","nouveau  employé est modifié",QSystemTrayIcon::Information,15000);

}


