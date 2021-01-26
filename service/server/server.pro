TARGET   = AmneziaVPN-service
TEMPLATE = app
CONFIG   += console qt no_batch
QT += core network

HEADERS = \
        ../../client/message.h \
        ../../client/utils.h \
        localserver.h \
        log.h \
        router.h \
        systemservice.h

SOURCES = \
        ../../client/message.cpp \
        ../../client/utils.cpp \
        localserver.cpp \
        log.cpp \
        main.cpp \
        router.cpp \
        systemservice.cpp

win32 {
HEADERS += \
        tapcontroller_win.h

SOURCES += \
        tapcontroller_win.cpp

LIBS += \
        -luser32 \
        -lrasapi32 \
        -lshlwapi \
        -liphlpapi \
        -lws2_32 \
        -liphlpapi \
        -lgdi32
}

include(../src/qtservice.pri)

#CONFIG(release, debug|release) {
#    DESTDIR = $$PWD/../../../AmneziaVPN-build/server/release
#    MOC_DIR = $$DESTDIR
#    OBJECTS_DIR = $$DESTDIR
#    RCC_DIR = $$DESTDIR
#}

INCLUDEPATH += "$$PWD/../../client"
