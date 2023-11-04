TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    library/functions.cpp

HEADERS += \
    library/list.h \
    library/vector.h \
    library/uniqueptr.h \
    library/array.h \
    library/functions.h

INCLUDEPATH = /home/user/boost/include
