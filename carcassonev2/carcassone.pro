QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Game/figure.cpp \
    Game/tile.cpp \
    Game/tiledatabase.cpp \
    Game/tileeventhandler.cpp \
    Graphics/figuregraphicsitem.cpp \
    Graphics/gamescene.cpp \
    Graphics/gameview.cpp \
    Graphics/mapitem.cpp \
    Networking/dataencoder.cpp \
    Networking/datadecoder.cpp \
    Networking/client.cpp \
    Networking/server.cpp \
    Controller/datacontroller.cpp \
    Controller/networkcontroller.cpp \
    Misc/player.cpp \
    Networking/servereventhandler.cpp \
    View/gamewindow.cpp \
    View/mainmenu.cpp \
    View/serverwindow.cpp \
    main.cpp

HEADERS += \
    Game/figure.h \
    Game/tile.h \
    Game/tiledatabase.h \
    Game/tileeventhandler.h \
    Graphics/figuregraphicsitem.h \
    Graphics/gamescene.h \
    Graphics/gameview.h \
    Graphics/mapitem.h \
    Networking/dataencoder.h \
    Networking/datadecoder.h \
    Networking/client.h \
    Networking/server.h \
    Controller/datacontroller.h \
    Controller/networkcontroller.h \
    Misc/DataEnums.h \
    Misc/player.h \
    Networking/servereventhandler.h \
    View/gamewindow.h \
    View/mainmenu.h \
    View/serverwindow.h

FORMS += \
    View/gamewindow.ui \
    View/mainmenu.ui \
    View/serverwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
