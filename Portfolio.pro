TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

HEADERS += \
    library/list.h \
    library/vector.h \
    library/uniqueptr.h

INCLUDEPATH = /home/user/boost/include
