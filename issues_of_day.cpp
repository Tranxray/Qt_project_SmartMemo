#include "issues_of_day.h"
#include "ui_issues_of_day.h"

Issues_of_Day::Issues_of_Day(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Issues_of_Day)
{
    ui->setupUi(this);
    this->setWindowTitle("一日事件");
    connect(ui->AddButton,SIGNAL(clicked()),this,SLOT(Add_Issue()));
    connect(ui->CloseButton,SIGNAL(clicked(bool)),this,SLOT(close()));
}



Issues_of_Day::~Issues_of_Day()
{
    delete ui;
}

void Issues_of_Day::Add_Issue(){

}

void Issues_of_Day::Close_window(){
    this->close();
}
