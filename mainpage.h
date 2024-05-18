#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainPage;
}
QT_END_NAMESPACE

class MainPage : public QWidget
{
    Q_OBJECT

public:
    MainPage(QWidget *parent = nullptr);
    ~MainPage();

private slots:
    void Button_clicked();

private:
    Ui::MainPage *ui;
};
#endif // MAINPAGE_H
