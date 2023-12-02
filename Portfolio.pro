TEMPLATE = app
CONFIG += console c++11 thread
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    library/functions.cpp \
    library/nonbinarypolishrecord.cpp \
    library/xmlparserexample.cpp \
    library/xmlparsetests.cpp

HEADERS += \
    library/list.h \
    library/vector.h \
    library/uniqueptr.h \
    library/array.h \
    library/functions.h \
    library/nonbinarypolishrecord.h \
    library/xmlparserexample.h \
    library/xmlparsetests.h

INCLUDEPATH = /home/user/boost/include
