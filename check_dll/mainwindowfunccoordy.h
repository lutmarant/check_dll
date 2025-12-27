#ifndef MAINWINDOWFUNCCOORDY_H
#define MAINWINDOWFUNCCOORDY_H

#include <QMainWindow>

#include "importedMath.h"

namespace Ui {
class MainWindowFuncCoordY;
}

class MainWindowFuncCoordY : public QMainWindow
{
    Q_OBJECT

    importedMath::FuncCoordX func;
    double dist = 0;
    double angleRad = 0;

public:
    explicit MainWindowFuncCoordY(QWidget *parent = nullptr);
    ~MainWindowFuncCoordY();

    void setFunc( importedMath::FuncCoordY value );

private:
    Ui::MainWindowFuncCoordY *ui;

public slots:
        void calculate( QString value );

        void setDist( QString value );
        void setAngleRad( QString value );
};

#endif // MAINWINDOWFUNCCOORDY_H
