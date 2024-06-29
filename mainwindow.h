#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<issues_of_day.h>
#include<settings.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(IssueList* il=nullptr,QWidget *parent = nullptr);
    ~MainWindow();
    IssueList* ilist;

private slots:

    void Open_Issue_of_Day();
    void SettingsButton_clicked();
    void Add_Issue();
    void Show_List();
    void Open_Calendar();

private:
    Ui::MainWindow *ui;
    Settings* setting;
    int colormode;
    int languagemode;
};
#endif // MAINWINDOW_H
