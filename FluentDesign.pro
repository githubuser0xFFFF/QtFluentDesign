QT       += core gui widgets


CONFIG += c++11 file_copies

COPIES += myFiles


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    MainWindow.cpp \
    ToggleSwitch.cpp \
    main.cpp

HEADERS += \
    MainWindow.h \
    ToggleSwitch.h

FORMS += \
    MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

myFiles.files = $$files(*.css)
myFiles.path = $$OUT_PWD

DEFINES += CSS_FILE=$$PWD/fluent_design.css


RESOURCES += \
    style.qrc
