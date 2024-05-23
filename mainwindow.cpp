#include "mainwindow.h"
#include"settings.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: rgb(255, 255, 255);");
    connect(ui->ViewmoreButton,SIGNAL(clicked()),this,SLOT(Open_Issue_of_Day()));
    connect(ui->settingsButton, &QPushButton::clicked, this, &MainWindow::SettingsButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Open_Issue_of_Day(){
    qDebug()<<1;
    Issues_of_Day* day_issues=new Issues_of_Day(this,this->ilist);
    qDebug()<<1.25;
    qDebug()<<1.5<<this->ilist;
    day_issues->ilist=this->ilist;
    qDebug()<<2<<this->ilist;
    qDebug()<<3;
    day_issues->exec();
    delete day_issues;
    ilist->writeData("IssueData.json");
}

void MainWindow::SettingsButton_clicked()
{
    Settings dialog(this);
    dialog.exec();
}

