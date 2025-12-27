#ifndef MAINWINDOWFINDPOSCOMPLEX_H
#define MAINWINDOWFINDPOSCOMPLEX_H

#include <QMainWindow>

#include "importedMath.h"

namespace Ui {
class MainWindowFindPosComplex;
}

class MainWindowFindPosComplex : public QMainWindow
{
    Q_OBJECT

    importedMath::FuncFindPos_complex func;

    double time = 0;
    double posStart_x = 0;
    double posStart_y = 0;
    double speed = 0;
    double heading = 0;
    double timeBeforeMan = 0;
    double acceleration = 0;
    double speed_new = 0;
    double radiusCirc = 0;
    double heading_new = 0;

    TOutFindPrj out;

public:
    explicit MainWindowFindPosComplex(QWidget *parent = nullptr);
    ~MainWindowFindPosComplex();

    void setFunc( importedMath::FuncFindPos_complex value );

private:
    Ui::MainWindowFindPosComplex *ui;

public slots:
    void calculate( QString value );

    void setTime( QString value );
    void setPosStart_x( QString value );
    void setPosStart_y( QString value );
    void setSpeed( QString value );
    void setHeading( QString value );
    void setTimeBeforeMan( QString value );
    void setAcceleration( QString value );
    void setSpeed_new( QString value );
    void setRadiusCirc( QString value );
    void setHeading_new( QString value );

};

#endif // MAINWINDOWFINDPOSCOMPLEX_H
