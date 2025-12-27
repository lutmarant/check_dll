#ifndef MAINWINDOWFUNCGRAD_H
#define MAINWINDOWFUNCGRAD_H

#include <QMainWindow>

#include "importedMath.h"

namespace Ui {
class MainWindowFuncGrad;
}

class MainWindowFuncGrad : public QMainWindow
{
    Q_OBJECT

    importedMath::FuncGrad funcGrad;

public:
    explicit MainWindowFuncGrad(QWidget *parent = nullptr);
    ~MainWindowFuncGrad();

    void setFunc( importedMath::FuncGrad value );

private:
    Ui::MainWindowFuncGrad *ui;

public slots:
        void calculate( QString value );
};

#endif // MAINWINDOWFUNCGRAD_H
