TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Player/Ships/ship.cpp \
    Player/Ships/submarine.cpp \
    Player/Ships/destroyer.cpp \
    Player/Ships/battleship.cpp \
    Player/Ships/air_carrier.cpp \
    Player/square.cpp \
    Player/board.cpp \
    Player/player.cpp \
    game.cpp

HEADERS += \
    my_headers.h \
    Player/Ships/ship.h \
    Player/Ships/submarine.h \
    Player/Ships/destroyer.h \
    Player/Ships/battleship.h \
    Player/Ships/air_carrier.h \
    Player/square.h \
    Player/board.h \
    Player/player.h \
    game.h

