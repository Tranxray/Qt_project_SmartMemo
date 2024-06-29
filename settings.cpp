#include "settings.h"
#include "ui_settings.h"
#include"stylesheetmanager.h"

Settings::Settings(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Settings)
{
    ui->setupUi(this);
    connect(ui->close,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(ui->Day,SIGNAL(clicked(bool)),this,SLOT(SetDayStyle()));
    connect(ui->Night,SIGNAL(clicked(bool)),this,SLOT(SetNightStyle()));
    //this->setStyleSheet("background-color: rgb(145, 201, 25);");
}

Settings::~Settings()
{
    delete ui;
}


void Settings::SetDayStyle(){
    StyleSheetManager::instance().SetStyle(1);
}

void Settings::SetNightStyle(){
    StyleSheetManager::instance().SetStyle(0);
}
