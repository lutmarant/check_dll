#include "mainwindowfuncfindtime.h"
#include "ui_mainwindowfuncfindtime.h"

#include <iostream>

MainWindowFuncFindTime::MainWindowFuncFindTime(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowFuncFindTime)
{
    ui->setupUi(this);

    this->setWindowTitle( "findTimeToAlterate" );

    connect( ui->doubleSpinBox_inFundFindTime_speed, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFuncFindTime::setSpeed );
    connect( ui->doubleSpinBox_inFundFindTime_speed, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFuncFindTime::calculate );
    ui->doubleSpinBox_inFundFindTime_speed->setRange( -1000000, 10000000 );
    ui->doubleSpinBox_inFundFindTime_speed->setLocale( QLocale::English );
    ui->doubleSpinBox_inFundFindTime_speed->setDecimals( 3 );
    ui->doubleSpinBox_inFundFindTime_speed->setSingleStep( 1 );
    ui->doubleSpinBox_inFundFindTime_speed->setValue( 0 );

    connect( ui->doubleSpinBox_inFundFindTime_speedNew, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFuncFindTime::setSpeedNew );
    connect( ui->doubleSpinBox_inFundFindTime_speedNew, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFuncFindTime::calculate );
    ui->doubleSpinBox_inFundFindTime_speedNew->setRange( -1000000, 10000000 );
    ui->doubleSpinBox_inFundFindTime_speedNew->setLocale( QLocale::English );
    ui->doubleSpinBox_inFundFindTime_speedNew->setDecimals( 3 );
    ui->doubleSpinBox_inFundFindTime_speedNew->setSingleStep( 1 );
    ui->doubleSpinBox_inFundFindTime_speedNew->setValue( 0 );

    connect( ui->doubleSpinBox_inFundFindTime_acceleration, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFuncFindTime::setAcceleration );
    connect( ui->doubleSpinBox_inFundFindTime_acceleration, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFuncFindTime::calculate );
    ui->doubleSpinBox_inFundFindTime_acceleration->setRange( -1000000, 10000000 );
    ui->doubleSpinBox_inFundFindTime_acceleration->setLocale( QLocale::English );
    ui->doubleSpinBox_inFundFindTime_acceleration->setDecimals( 3 );
    ui->doubleSpinBox_inFundFindTime_acceleration->setSingleStep( 1 );
    ui->doubleSpinBox_inFundFindTime_acceleration->setValue( 0 );

    connect( ui->doubleSpinBox_inFundFindTime_heading, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFuncFindTime::setHeading );
    connect( ui->doubleSpinBox_inFundFindTime_heading, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFuncFindTime::calculate );
    ui->doubleSpinBox_inFundFindTime_heading->setRange( -1000000, 10000000 );
    ui->doubleSpinBox_inFundFindTime_heading->setLocale( QLocale::English );
    ui->doubleSpinBox_inFundFindTime_heading->setDecimals( 3 );
    ui->doubleSpinBox_inFundFindTime_heading->setSingleStep( 1 );
    ui->doubleSpinBox_inFundFindTime_heading->setValue( 0 );

    connect( ui->doubleSpinBox_inFundFindTime_headingNew, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFuncFindTime::setHeadingNew );
    connect( ui->doubleSpinBox_inFundFindTime_headingNew, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFuncFindTime::calculate );
    ui->doubleSpinBox_inFundFindTime_headingNew->setRange( -1000000, 10000000 );
    ui->doubleSpinBox_inFundFindTime_headingNew->setLocale( QLocale::English );
    ui->doubleSpinBox_inFundFindTime_headingNew->setDecimals( 3 );
    ui->doubleSpinBox_inFundFindTime_headingNew->setSingleStep( 1 );
    ui->doubleSpinBox_inFundFindTime_headingNew->setValue( 0 );

    connect( ui->doubleSpinBox_inFundFindTime_radiusCirc, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFuncFindTime::setRadiusCirc );
    connect( ui->doubleSpinBox_inFundFindTime_radiusCirc, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFuncFindTime::calculate );
    ui->doubleSpinBox_inFundFindTime_radiusCirc->setRange( -1000000, 10000000 );
    ui->doubleSpinBox_inFundFindTime_radiusCirc->setLocale( QLocale::English );
    ui->doubleSpinBox_inFundFindTime_radiusCirc->setDecimals( 3 );
    ui->doubleSpinBox_inFundFindTime_radiusCirc->setSingleStep( 1 );
    ui->doubleSpinBox_inFundFindTime_radiusCirc->setValue( 0 );

    ui->lineEdit_outFuncFindTime_res->setReadOnly( true );
    ui->lineEdit_outFuncFindTime_timeSpeedMan->setReadOnly( true );
    ui->lineEdit_outFuncFindTime_timeHeadingMan->setReadOnly( true );
}

MainWindowFuncFindTime::~MainWindowFuncFindTime()
{
    delete ui;
}

void MainWindowFuncFindTime::setFunc(importedMath::FuncFindTimeToAlterate value)
{
    func = value;
}

void MainWindowFuncFindTime::calculate(QString value)
{
    if ( func )
    {
        std::cout << "CALCULATE FINDTIMETOALTERATE" << std::endl;

        struct TInFindPrj in;
        in.speed = speed;
        in.speed_new = speed_new;
        in.acceleration = acceleration;

        in.heading = heading;
        in.heading_new = heading_new;
        in.radiusCirc = radiusCirc;

        ui->lineEdit_outFuncFindTime_res->setText( QString::number( func( in, &timeSpeedMan, &timeHeadingMan ) ) );
        ui->lineEdit_outFuncFindTime_timeSpeedMan->setText( QString::number( timeSpeedMan ) );
        ui->lineEdit_outFuncFindTime_timeHeadingMan->setText( QString::number( timeHeadingMan ) );
    }
}

void MainWindowFuncFindTime::setSpeed(QString value)
{
    speed = value.toDouble();
}

void MainWindowFuncFindTime::setSpeedNew(QString value)
{
    speed_new = value.toDouble();
}

void MainWindowFuncFindTime::setAcceleration(QString value)
{
    acceleration = value.toDouble();
}

void MainWindowFuncFindTime::setHeading(QString value)
{
    heading = value.toDouble();
}

void MainWindowFuncFindTime::setHeadingNew(QString value)
{
    heading_new = value.toDouble();
}

void MainWindowFuncFindTime::setRadiusCirc(QString value)
{
    radiusCirc = value.toDouble();
}
