#ifndef MAINWINDOWFUNCPRIVPI_H
#define MAINWINDOWFUNCPRIVPI_H

#include <QMainWindow>

#include "importedMath.h"

namespace Ui {
class MainWindowFuncPrivPi;
}

class MainWindowFuncPrivPi : public QMainWindow
{
    Q_OBJECT

    importedMath::FuncPrivPi func;

public:
    explicit MainWindowFuncPrivPi(QWidget *parent = nullptr);
    ~MainWindowFuncPrivPi();

    void setFunc( importedMath::FuncPriv2Pi value );

private:
    Ui::MainWindowFuncPrivPi *ui;

public slots:
        void calculate( QString value );
};

#endif // MAINWINDOWFUNCPRIVPI_H
