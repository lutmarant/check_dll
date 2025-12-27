#ifndef MAINWINDOWFUNCDIST1TO2_H
#define MAINWINDOWFUNCDIST1TO2_H

#include <QMainWindow>

#include "importedMath.h"

namespace Ui {
class MainWindowFuncDist1to2;
}

class MainWindowFuncDist1to2 : public QMainWindow
{
    Q_OBJECT

    importedMath::FuncDist_1to2 func;
    double x1 = 0;
    double y1 = 0;
    double x2 = 0;
    double y2 = 0;

public:
    explicit MainWindowFuncDist1to2(QWidget *parent = nullptr);
    ~MainWindowFuncDist1to2();

    void setFunc( importedMath::FuncDist_1to2 value );

private:
    Ui::MainWindowFuncDist1to2 *ui;

public slots:
        void calculate( QString value );

        void setX1( QString value );
        void setY1( QString value );
        void setX2( QString value );
        void setY2( QString value );
};

#endif // MAINWINDOWFUNCDIST1TO2_H
