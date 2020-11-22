QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    algorithm.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    algorithm.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



DISTFILES +=

#unix: LIBS += -lAVL


unix: LIBS += -L$$PWD/../../../../opt/AdaptiveVision/AVL-x86_64-4.12.13/lib/ -lAVL

INCLUDEPATH += $$PWD/../../../../opt/AdaptiveVision/AVL-x86_64-4.12.13/include
DEPENDPATH += $$PWD/../../../../opt/AdaptiveVision/AVL-x86_64-4.12.13/include

#unix: LIBS += -L$$PWD/../../../../opt/AdaptiveVision/AVL-5.0.13/lib/x86_64-linux-gnu/ -lAVL
#unix: LIBS += -L$$PWD/../../../../opt/AdaptiveVision/AVL-5.0.13/lib/x86_64-linux-gnu/ -lc++10.0
#unix: LIBS += -L$$PWD/../../../../opt/AdaptiveVision/AVL-5.0.13/lib/x86_64-linux-gnu/ -lc++abi10.0
#unix: LIBS += -L$$PWD/../../../../opt/AdaptiveVision/AVL-5.0.13/lib/x86_64-linux-gnu/ -lexif
#unix: LIBS += -L$$PWD/../../../../opt/AdaptiveVision/AVL-5.0.13/lib/x86_64-linux-gnu/ -liconv
#unix: LIBS += -L$$PWD/../../../../opt/AdaptiveVision/AVL-5.0.13/lib/x86_64-linux-gnu/ -llogge
#unix: LIBS += -L$$PWD/../../../../opt/AdaptiveVision/AVL-5.0.13/lib/x86_64-linux-gnu/ -lomp

#INCLUDEPATH += $$PWD/../../../../opt/AdaptiveVision/AVL-5.0.13/lib/x86_64-linux-gnu
#DEPENDPATH += $$PWD/../../../../opt/AdaptiveVision/AVL-5.0.13/lib/x86_64-linux-gnu


unix: LIBS += -L$$PWD/../../../../opt/AdaptiveVision/AVL-x86_64-4.12.13/lib/ -lc++8.0
unix: LIBS += -L$$PWD/../../../../opt/AdaptiveVision/AVL-x86_64-4.12.13/lib/ -lAVL
unix: LIBS += -L$$PWD/../../../../opt/AdaptiveVision/AVL-x86_64-4.12.13/lib/ -lexif
unix: LIBS += -L$$PWD/../../../../opt/AdaptiveVision/AVL-x86_64-4.12.13/lib/ -liconv
unix: LIBS += -L$$PWD/../../../../opt/AdaptiveVision/AVL-x86_64-4.12.13/lib/ -lomp
unix: LIBS += -L$$PWD/../../../../opt/AdaptiveVision/AVL-x86_64-4.12.13/lib/ -lxiApi_Kit
unix: LIBS += -L$$PWD/../../../../opt/AdaptiveVision/AVL-x86_64-4.12.13/lib/ -lc++8.0
unix: LIBS += -L$$PWD/../../../../opt/AdaptiveVision/AVL-x86_64-4.12.13/lib/ -lGocator_Kit
unix: LIBS += -L$$PWD/../../../../opt/AdaptiveVision/AVL-x86_64-4.12.13/lib/ -lkApi
unix: LIBS += -L$$PWD/../../../../opt/AdaptiveVision/AVL-x86_64-4.12.13/lib/ -lPylon_Kit
unix: LIBS += -L$$PWD/../../../../opt/AdaptiveVision/AVL-x86_64-4.12.13/lib/ -lc++abi8.0
unix: LIBS += -L$$PWD/../../../../opt/AdaptiveVision/AVL-x86_64-4.12.13/lib/ -lGoSdk
unix: LIBS += -L$$PWD/../../../../opt/AdaptiveVision/AVL-x86_64-4.12.13/lib/ -llogger
unix: LIBS += -L$$PWD/../../../../opt/AdaptiveVision/AVL-x86_64-4.12.13/lib/ -lVimba_Kit
