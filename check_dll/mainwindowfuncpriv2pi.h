#ifndef MAINWINDOWFUNCPRIV2PI_H
#define MAINWINDOWFUNCPRIV2PI_H

#include <QMainWindow>

#include "importedMath.h"

namespace Ui {
class MainWindowFuncPriv2Pi;
}

class MainWindowFuncPriv2Pi : public QMainWindow
{
    Q_OBJECT

    importedMath::FuncPriv2Pi func;

public:
    explicit MainWindowFuncPriv2Pi(QWidget *parent = nullptr);
    ~MainWindowFuncPriv2Pi();

    void setFunc( importedMath::FuncPriv2Pi value );

private:
    Ui::MainWindowFuncPriv2Pi *ui;

public slots:
        void calculate( QString value );
};

#endif // MAINWINDOWFUNCPRIV2PI_H
