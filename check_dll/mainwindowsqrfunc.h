#ifndef MAINWINDOWSQRFUNC_H
#define MAINWINDOWSQRFUNC_H

#include <QMainWindow>

#include "importedMath.h"

namespace Ui {
class MainWindowSqrFunc;
}

class MainWindowSqrFunc : public QMainWindow
{
    Q_OBJECT

    importedMath::FuncSqr funcSqr;

public:
    explicit MainWindowSqrFunc(QWidget *parent = nullptr);
    ~MainWindowSqrFunc();

    void setFunc( importedMath::FuncSqr value );

private:
    Ui::MainWindowSqrFunc *ui;

public slots:
        void calculate( QString value );
};

#endif // MAINWINDOWSQRFUNC_H
