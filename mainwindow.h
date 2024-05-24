#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"NewNote.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_settingsButton_clicked();

    void on_Add_clicked();

private:
    Ui::MainWindow *ui;
    NewNote *newNote;
};
#endif // MAINWINDOW_H
