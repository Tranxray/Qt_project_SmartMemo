#ifndef STYLESHEETMANAGER_H
#define STYLESHEETMANAGER_H

#include <QObject>
#include <QApplication>
#include <QFile>
#include <QDebug>

class StyleSheetManager : public QObject
{
    Q_OBJECT
public:
    explicit StyleSheetManager(QObject *parent = nullptr);
    static StyleSheetManager& instance();
    void SetStyle(int type=0);

signals:
};

#endif // STYLESHEETMANAGER_H
