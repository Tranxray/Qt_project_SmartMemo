QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Classes_of_Issue.cpp \
    IssueList.cpp \
    TimeofIssue.cpp \
    calendarwindow.cpp \
    dialog_add_issue.cpp \
    dialog_delete_issue.cpp \
    issues_of_day.cpp \
    main.cpp \
    mainwindow.cpp \
    settings.cpp \
    stylesheetmanager.cpp \
    widget_of_isuue.cpp

HEADERS += \
    Classes_of_Issue.h \
    IssueList.h \
    TimeofIssue.h \
    calendarwindow.h \
    dialog_add_issue.h \
    dialog_delete_issue.h \
    issues_of_day.h \
    mainwindow.h \
    settings.h \
    stylesheetmanager.h \
    widget_of_isuue.h

FORMS += \
    calendarwindow.ui \
    dialog_add_issue.ui \
    dialog_delete_issue.ui \
    issues_of_day.ui \
    mainwindow.ui \
    settings.ui \
    widget_of_isuue.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    build/Qt_6_7_0_for_macOS-Debug/images/MainMenu1.0.jpeg \
    build/Qt_6_7_0_for_macOS-Debug/images/add-.jpg \
    build/Qt_6_7_0_for_macOS-Debug/images/add.jpeg \
    build/Qt_6_7_0_for_macOS-Debug/images/calendar1.0.jpeg \
    build/Qt_6_7_0_for_macOS-Debug/images/down.jpeg \
    build/Qt_6_7_0_for_macOS-Debug/images/moon.jpg \
    build/Qt_6_7_0_for_macOS-Debug/images/settings1.0.jpeg \
    build/Qt_6_7_0_for_macOS-Debug/images/sun.jpeg \
    stylesheets/deepcolor.qss \
    stylesheets/lightcolor.qss

RESOURCES += \
    imagesource.qrc
