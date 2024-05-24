#include "mainwindow.h"
#include "SettingsDialog.h"
#include "ui_mainwindow.h"
#include "NewNote.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: rgb(255, 255, 255);");
    connect(ui->settingsButton, &QPushButton::clicked, this, &MainWindow::on_settingsButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_settingsButton_clicked()
{
    SettingsDialog dialog(this);
    dialog.exec();
}


void MainWindow::on_Add_clicked()
{
    if (!newNote) {
        newNote = new NewNote(this);
    }
    newNote->show();
}

