#ifndef MAINWINDOWFUNCFINDTIME_H
#define MAINWINDOWFUNCFINDTIME_H

#include <QMainWindow>

#include "importedMath.h"

namespace Ui {
class MainWindowFuncFindTime;
}

class MainWindowFuncFindTime : public QMainWindow
{
    Q_OBJECT

    importedMath::FuncFindTimeToAlterate func;
    double speed = 0;
    double speed_new = 0;
    double acceleration = 0;
    double heading = 0;
    double heading_new = 0;
    double radiusCirc = 0;

    double timeSpeedMan = 0;
    double timeHeadingMan = 0;

public:
    explicit MainWindowFuncFindTime(QWidget *parent = nullptr);
    ~MainWindowFuncFindTime();

    void setFunc( importedMath::FuncFindTimeToAlterate value );

private:
    Ui::MainWindowFuncFindTime *ui;

public slots:
        void calculate( QString value );

        void setSpeed( QString value );
        void setSpeedNew( QString value );
        void setAcceleration( QString value );
        void setHeading( QString value );
        void setHeadingNew( QString value );
        void setRadiusCirc( QString value );
};

#endif // MAINWINDOWFUNCFINDTIME_H
