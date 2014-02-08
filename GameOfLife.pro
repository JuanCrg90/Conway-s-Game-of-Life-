TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += main.c \
    Conway.c \
    linkList.c

HEADERS += \
    Conway.h \
    linklist.h

OTHER_FILES += \
    README.md

LIBS +=  -lfreeglut -lopengl32 -lglu32
