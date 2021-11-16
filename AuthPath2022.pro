QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Info.cpp \
    adduserdialog.cpp \
    delete_user_dialog.cpp \
    information_about_app.cpp \
    main.cpp \
    mainwindow.cpp \
    update_user_dialog.cpp

HEADERS += \
    adduserdialog.h \
    delete_user_dialog.h \
    information_about_app.h \
    mainwindow.h \
    update_user_dialog.h

FORMS += \
    adduserdialog.ui \
    delete_user_dialog.ui \
    mainwindow.ui \
    update_user_dialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
