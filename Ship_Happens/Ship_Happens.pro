TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    square.cpp \
    board.cpp \
    player.cpp \
    Ships/destroyer.cpp \
    Ships/battleship.cpp \
    Ships/submarine.cpp \
    Ships/ship.cpp \
    Ships/air_carrier.cpp

HEADERS += \
    my_headers.h \
    square.h \
    board.h \
    player.h \
    Ships/destroyer.h \
    Ships/battleship.h \
    Ships/submarine.h \
    Ships/ship.h \
    Ships/air_carrier.h

