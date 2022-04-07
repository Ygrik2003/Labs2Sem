QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    lab1/lab1disign.cpp \
    lab1/mychar.cpp \
    lab1/mystring.cpp \
    lab1/myvector.cpp \
    lab2/lab2disign.cpp \
    lab2/paintfield.cpp \
    lab3/lab3disign.cpp \
    lab3/linefield.cpp \
    lab3/parcecommand.cpp \
    lab4/lab4disign.cpp \
    lab5/lab5disign.cpp \
    lab6/lab6disign.cpp \
    main.cpp \
    mainwindow.cpp \
    myexception.cpp

HEADERS += \
    lab1/lab1disign.h \
    lab1/mychar.h \
    lab1/mystring.h \
    lab1/myvector.h \
    lab2/lab2disign.h \
    lab2/paintfield.h \
    lab3/lab3disign.h \
    lab3/linefield.h \
    lab3/parcecommand.h \
    lab4/lab4disign.h \
    lab5/lab5disign.h \
    lab6/lab6disign.h \
    mainwindow.h \
    myexception.h

FORMS += \
    lab1/lab1disign.ui \
    lab2/lab2disign.ui \
    lab3/lab3disign.ui \
    lab4/lab4disign.ui \
    lab5/lab5disign.ui \
    lab6/lab6disign.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
