QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    car.cpp \
    cell.cpp \
    coords.cpp \
    main.cpp \
    mainwindow.cpp \
    pedestriancrossing.cpp \
    qroadsmap.cpp \
    roadsmap.cpp \
    settingswidget.cpp \
    simulation.cpp \
    simulationconfig.cpp \
    trafficlight.cpp \
    vehicle.cpp \
    vehicleswarm.cpp

HEADERS += \
    car.h \
    cell.h \
    coords.h \
    direction.h \
    mainwindow.h \
    pedestriancrossing.h \
    qroadsmap.h \
    roadsmap.h \
    settingswidget.h \
    simulation.h \
    simulationconfig.h \
    trafficlight.h \
    vehicle.h \
    vehicleswarm.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
