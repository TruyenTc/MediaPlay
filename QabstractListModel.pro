QT += quick core widgets multimedia

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        folder.cpp \
        main.cpp \
        objectmodel1.cpp \
        qplayer.cpp \
        translator.cpp

RESOURCES += qml.qrc

TRANSLATIONS +=language/VN.ts\
               language/EL.ts\



# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    SongModel.h \
    folder.h \
    objectmodel1.h \
    qplayer.h \
    translator.h

DISTFILES += \
    language/VN.qm\
    language/EL.qm\
