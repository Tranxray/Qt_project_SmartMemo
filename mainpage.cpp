#include "mainpage.h"
#include "ui_mainpage.h"
#include"issues_of_day.h"

MainPage::MainPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainPage)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(Button_clicked()));
}

MainPage::~MainPage()
{
    delete ui;
}

void MainPage::Button_clicked()
{
    Issues_of_Day* newwindow=new Issues_of_Day(this);
    newwindow->show();
}

