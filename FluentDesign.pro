QT       += core gui widgets


CONFIG += c++11 file_copies

COPIES += myFiles


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ToggleSwitch.cpp \
    main.cpp \
    MainWidget.cpp

HEADERS += \
    MainWidget.h \
    ToggleSwitch.h

FORMS += \
    MainWidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

myFiles.files = $$files(*.css)
myFiles.path = $$OUT_PWD

DEFINES += CSS_FILE=$$PWD/fluent_design.css


RESOURCES += \
    style.qrc
