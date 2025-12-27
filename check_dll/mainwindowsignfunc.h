#ifndef MAINWINDOWSIGNFUNC_H
#define MAINWINDOWSIGNFUNC_H

#include <QMainWindow>

#include <QString>

#include "importedMath.h"

namespace Ui {
class MainWindowSignFunc;
}

class MainWindowSignFunc : public QMainWindow
{
    Q_OBJECT

    importedMath::FuncSign funcSign;

public:
    explicit MainWindowSignFunc(QWidget *parent = nullptr);
    ~MainWindowSignFunc();

    void setSignFunc( importedMath::FuncSign value );

private:
    Ui::MainWindowSignFunc *ui;

public slots:
        void calculate( QString value );
};

#endif // MAINWINDOWSIGNFUNC_H
