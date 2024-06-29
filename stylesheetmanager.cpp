#include "stylesheetmanager.h"
#include<qapplication.h>
#include<qfile.h>

StyleSheetManager::StyleSheetManager(QObject *parent)
    : QObject{parent}
{}

void StyleSheetManager::SetStyle(int type){
    if(type==1){
        QFile file(":/style/stylesheets/lightcolor.qss");
        if (file.open(QFile::ReadOnly | QFile::Text)) {
            QString styleSheet = file.readAll();
            qApp->setStyleSheet(styleSheet);
            file.close();
        } else {
            qWarning() << "Failed to open stylesheet file";
        }
    }
    else{
        QFile file(":/style/stylesheets/deepcolor.qss");
        if (file.open(QFile::ReadOnly | QFile::Text)) {
            QString styleSheet = file.readAll();
            qApp->setStyleSheet(styleSheet);
            file.close();
        } else {
            qWarning() << "Failed to open stylesheet file";
        }
    }
}

StyleSheetManager& StyleSheetManager::instance() {
    static StyleSheetManager instance;
    return instance;
}
