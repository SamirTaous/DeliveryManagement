QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adddelivery.cpp \
    addemployee.cpp \
    deleteemployee.cpp \
    deliveryorder.cpp \
    deliverywidget.cpp \
    employe.cpp \
    employewidget.cpp \
    inventorywidget.cpp \
    main.cpp \
    loginwindow.cpp \
    mainwindow.cpp \
    orderitem.cpp \
    updateemployee.cpp

HEADERS += \
    adddelivery.h \
    addemployee.h \
    deleteemployee.h \
    deliveryorder.h \
    deliverywidget.h \
    employe.h \
    employewidget.h \
    inventorywidget.h \
    loginwindow.h \
    mainwindow.h \
    orderitem.h \
    updateemployee.h

FORMS += \
    adddelivery.ui \
    addemployee.ui \
    deleteemployee.ui \
    deliverywidget.ui \
    employewidget.ui \
    inventorywidget.ui \
    loginwindow.ui \
    mainwindow.ui \
    updateemployee.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
