#ifndef MAINWINDOWFUNCRAD_H
#define MAINWINDOWFUNCRAD_H

#include <QMainWindow>

#include "importedMath.h"

namespace Ui {
class MainWindowFuncRad;
}

class MainWindowFuncRad : public QMainWindow
{
    Q_OBJECT

    importedMath::FuncRad funcRad;

public:
    explicit MainWindowFuncRad(QWidget *parent = nullptr);
    ~MainWindowFuncRad();

    void setFunc( importedMath::FuncRad value );

private:
    Ui::MainWindowFuncRad *ui;

public slots:
        void calculate( QString value );
};

#endif // MAINWINDOWFUNCRAD_H
