#ifndef MAINWINDOWFUNCCOORDX_H
#define MAINWINDOWFUNCCOORDX_H

#include <QMainWindow>

#include "importedMath.h"

namespace Ui {
class MainWindowFuncCoordX;
}

class MainWindowFuncCoordX : public QMainWindow
{
    Q_OBJECT

    importedMath::FuncCoordX func;
    double dist = 0;
    double angleRad = 0;

public:
    explicit MainWindowFuncCoordX(QWidget *parent = nullptr);
    ~MainWindowFuncCoordX();

    void setFunc( importedMath::FuncCoordX value );

private:
    Ui::MainWindowFuncCoordX *ui;

public slots:
        void calculate( QString value );

        void setDist( QString value );
        void setAngleRad( QString value );
};

#endif // MAINWINDOWFUNCCOORDX_H
