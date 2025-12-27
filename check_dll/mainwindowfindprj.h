#ifndef MAINWINDOWFINDPRJ_H
#define MAINWINDOWFINDPRJ_H

#include <QMainWindow>

#include "importedMath.h"

namespace Ui {
class MainWindowFindPrj;
}

class MainWindowFindPrj : public QMainWindow
{
    Q_OBJECT

    importedMath::FuncFindPrj func;
    double time = 0;
    double speed = 0;
    double speed_new = 0;
    double acceleration = 0;
    double heading = 0;
    double heading_new = 0;
    double radiusCirc = 0;

    TOutFindPrj out;

public:
    explicit MainWindowFindPrj(QWidget *parent = nullptr);
    ~MainWindowFindPrj();

    void setFunc( importedMath::FuncFindPrj value );

private:
    Ui::MainWindowFindPrj *ui;

public slots:
        void calculate( QString value );

        void setTime( QString value );
        void setSpeed( QString value );
        void setSpeedNew( QString value );
        void setAcceleration( QString value );
        void setHeading( QString value );
        void setHeadingNew( QString value );
        void setRadiusCirc( QString value );

signals:
    void sendData( std::vector < TDataPrj > data );


};

#endif // MAINWINDOWFINDPRJ_H
