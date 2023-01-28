QT -= gui

CONFIG += c++17 console
CONFIG -= app_bundle

SOURCES += \
        main.cpp \
        product.cpp \
        main.cpp

HEADERS += \
    product.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

