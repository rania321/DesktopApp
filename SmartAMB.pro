    QT       += core gui sql multimedia printsupport charts network serialport
QT       +=svg


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

LIBS += "C:\Users\DELL\OneDrive\Bureau\2a3-smart-ambulance-agency-2a3-integration3\libs\ssleay32.dll"
LIBS += "C:\Users\DELL\OneDrive\Bureau\2a3-smart-ambulance-agency-2a3-integration3\libs\libeay32.dll"
LIBS += "C:\Users\DELL\OneDrive\Bureau\2a3-smart-ambulance-agency-2a3-integration3\libs\libssl32.dll"

SOURCES += \
    ambulancec.cpp \
    ambulancei.cpp \
    arduino.cpp \
    arduinoe.cpp \
    calendrier.cpp \
    chatbox.cpp \
    client.cpp \
    clientc.cpp \
    connection.cpp \
    employe2.cpp \
    employe2c.cpp \
    exportexcelobject.cpp \
    login2.cpp \
    loginclient.cpp \
    main.cpp \
    mainwindow.cpp \
    materiel.cpp \
    materielm.cpp \
    notification.cpp \
    qrcode.cpp \
    reclam.cpp \
    reclamation.cpp \
    smtp.cpp

HEADERS += \
    ambulancec.h \
    ambulancei.h \
    arduino.h \
    arduinoe.h \
    calendrier.h \
    chatbox.h \
    client.h \
    clientc.h \
    connection.h \
    employe2.h \
    employe2c.h \
    exportexcelobject.h \
    login2.h \
    loginclient.h \
    mainwindow.h \
    materiel.h \
    materielm.h \
    notification.h \
    qrcode.h \
    reclam.h \
    reclamation.h \
    smtp.h

FORMS += \
    ambulancei.ui \
    calendrier.ui \
    chatbox.ui \
    client.ui \
    employe2.ui \
    login2.ui \
    loginclient.ui \
    mainwindow.ui \
    materielm.ui \
    reclamation.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

DISTFILES += \
    ../../../../Downloads/cocher.png \
    ../../../../Downloads/connexion.png \
    ../../../../Downloads/cross.png
