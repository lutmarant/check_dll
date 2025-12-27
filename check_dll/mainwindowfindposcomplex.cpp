#include "mainwindowfindposcomplex.h"
#include "ui_mainwindowfindposcomplex.h"

#include <iostream>
#include <cmath>

#include <QLineSeries>

void MainWindowFindPosComplex::setTime( QString value )
{
    time = value.toDouble();
}

void MainWindowFindPosComplex::setPosStart_x( QString value )
{
    posStart_x = value.toDouble();
}

void MainWindowFindPosComplex::setPosStart_y( QString value )
{
    posStart_y = value.toDouble();
}

void MainWindowFindPosComplex::setSpeed( QString value )
{
    speed = value.toDouble();
}

void MainWindowFindPosComplex::setHeading( QString value )
{
    heading = value.toDouble();
}

void MainWindowFindPosComplex::setTimeBeforeMan( QString value )
{
    timeBeforeMan = value.toDouble();
}

void MainWindowFindPosComplex::setAcceleration( QString value )
{
    acceleration = value.toDouble();
}

void MainWindowFindPosComplex::setRadiusCirc( QString value )
{
    radiusCirc = value.toDouble();
}

void MainWindowFindPosComplex::setHeading_new( QString value )
{
    heading_new = value.toDouble();
}

void MainWindowFindPosComplex::setSpeed_new( QString value )
{
    speed_new = value.toDouble();
}

MainWindowFindPosComplex::MainWindowFindPosComplex(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowFindPosComplex)
{
    ui->setupUi(this);

    this->setWindowTitle( "findPos_manHS" );

    //===============================================================


    connect( ui->doubleSpinBox_inFuncFindPos_man_time, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFindPosComplex::setTime );
    connect( ui->doubleSpinBox_inFuncFindPos_man_time, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFindPosComplex::calculate );
    ui->doubleSpinBox_inFuncFindPos_man_time->setRange( -1000000, 10000000 );
    ui->doubleSpinBox_inFuncFindPos_man_time->setLocale( QLocale::English );
    ui->doubleSpinBox_inFuncFindPos_man_time->setDecimals( 3 );
    ui->doubleSpinBox_inFuncFindPos_man_time->setSingleStep( 1 );
    ui->doubleSpinBox_inFuncFindPos_man_time->setValue( 0 );

    connect( ui->doubleSpinBox_inFuncFindPosMan_posStartX, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFindPosComplex::setPosStart_x );
    connect( ui->doubleSpinBox_inFuncFindPosMan_posStartX, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFindPosComplex::calculate );
    ui->doubleSpinBox_inFuncFindPosMan_posStartX->setRange( -1000000, 10000000 );
    ui->doubleSpinBox_inFuncFindPosMan_posStartX->setLocale( QLocale::English );
    ui->doubleSpinBox_inFuncFindPosMan_posStartX->setDecimals( 3 );
    ui->doubleSpinBox_inFuncFindPosMan_posStartX->setSingleStep( 1 );
    ui->doubleSpinBox_inFuncFindPosMan_posStartX->setValue( 0 );

    connect( ui->doubleSpinBox_inFuncFindPosMan_posStartY, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFindPosComplex::setPosStart_y );
    connect( ui->doubleSpinBox_inFuncFindPosMan_posStartY, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFindPosComplex::calculate );
    ui->doubleSpinBox_inFuncFindPosMan_posStartY->setRange( -1000000, 10000000 );
    ui->doubleSpinBox_inFuncFindPosMan_posStartY->setLocale( QLocale::English );
    ui->doubleSpinBox_inFuncFindPosMan_posStartY->setDecimals( 3 );
    ui->doubleSpinBox_inFuncFindPosMan_posStartY->setSingleStep( 1 );
    ui->doubleSpinBox_inFuncFindPosMan_posStartY->setValue( 0 );

    connect( ui->doubleSpinBox_inFuncFindPosMan_speed, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFindPosComplex::setSpeed );
    connect( ui->doubleSpinBox_inFuncFindPosMan_speed, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFindPosComplex::calculate );
    ui->doubleSpinBox_inFuncFindPosMan_speed->setRange( -1000000, 10000000 );
    ui->doubleSpinBox_inFuncFindPosMan_speed->setLocale( QLocale::English );
    ui->doubleSpinBox_inFuncFindPosMan_speed->setDecimals( 3 );
    ui->doubleSpinBox_inFuncFindPosMan_speed->setSingleStep( 1 );
    ui->doubleSpinBox_inFuncFindPosMan_speed->setValue( 0 );

    connect( ui->doubleSpinBox_inFuncFindPosMan_heading, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFindPosComplex::setHeading );
    connect( ui->doubleSpinBox_inFuncFindPosMan_heading, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFindPosComplex::calculate );
    ui->doubleSpinBox_inFuncFindPosMan_heading->setRange( -1000000, 10000000 );
    ui->doubleSpinBox_inFuncFindPosMan_heading->setLocale( QLocale::English );
    ui->doubleSpinBox_inFuncFindPosMan_heading->setDecimals( 3 );
    ui->doubleSpinBox_inFuncFindPosMan_heading->setSingleStep( 1 );
    ui->doubleSpinBox_inFuncFindPosMan_heading->setValue( 0 );

    connect( ui->doubleSpinBox_inFuncFindPosMan_timeBeforeMan, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFindPosComplex::setTimeBeforeMan );
    connect( ui->doubleSpinBox_inFuncFindPosMan_timeBeforeMan, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFindPosComplex::calculate );
    ui->doubleSpinBox_inFuncFindPosMan_timeBeforeMan->setRange( -1000000, 10000000 );
    ui->doubleSpinBox_inFuncFindPosMan_timeBeforeMan->setLocale( QLocale::English );
    ui->doubleSpinBox_inFuncFindPosMan_timeBeforeMan->setDecimals( 3 );
    ui->doubleSpinBox_inFuncFindPosMan_timeBeforeMan->setSingleStep( 1 );
    ui->doubleSpinBox_inFuncFindPosMan_timeBeforeMan->setValue( 0 );

    connect( ui->doubleSpinBox_inFuncFindPosMan_acceleration, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFindPosComplex::setAcceleration );
    connect( ui->doubleSpinBox_inFuncFindPosMan_acceleration, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFindPosComplex::calculate );
    ui->doubleSpinBox_inFuncFindPosMan_acceleration->setRange( -1000000, 10000000 );
    ui->doubleSpinBox_inFuncFindPosMan_acceleration->setLocale( QLocale::English );
    ui->doubleSpinBox_inFuncFindPosMan_acceleration->setDecimals( 3 );
    ui->doubleSpinBox_inFuncFindPosMan_acceleration->setSingleStep( 1 );
    ui->doubleSpinBox_inFuncFindPosMan_acceleration->setValue( 0 );

    connect( ui->doubleSpinBox_inFuncFindPosMan_speedNew, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFindPosComplex::setSpeed_new );
    connect( ui->doubleSpinBox_inFuncFindPosMan_speedNew, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFindPosComplex::calculate );
    ui->doubleSpinBox_inFuncFindPosMan_speedNew->setRange( -1000000, 10000000 );
    ui->doubleSpinBox_inFuncFindPosMan_speedNew->setLocale( QLocale::English );
    ui->doubleSpinBox_inFuncFindPosMan_speedNew->setDecimals( 3 );
    ui->doubleSpinBox_inFuncFindPosMan_speedNew->setSingleStep( 1 );
    ui->doubleSpinBox_inFuncFindPosMan_speedNew->setValue( 0 );

    connect( ui->doubleSpinBox_inFuncFindPosMan_radiusCirc, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFindPosComplex::setRadiusCirc );
    connect( ui->doubleSpinBox_inFuncFindPosMan_radiusCirc, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFindPosComplex::calculate );
    ui->doubleSpinBox_inFuncFindPosMan_radiusCirc->setRange( -1000000, 10000000 );
    ui->doubleSpinBox_inFuncFindPosMan_radiusCirc->setLocale( QLocale::English );
    ui->doubleSpinBox_inFuncFindPosMan_radiusCirc->setDecimals( 3 );
    ui->doubleSpinBox_inFuncFindPosMan_radiusCirc->setSingleStep( 1 );
    ui->doubleSpinBox_inFuncFindPosMan_radiusCirc->setValue( 0 );

    connect( ui->doubleSpinBox_inFuncFindPosMan_headingNew, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFindPosComplex::setHeading_new );
    connect( ui->doubleSpinBox_inFuncFindPosMan_headingNew, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFindPosComplex::calculate );
    ui->doubleSpinBox_inFuncFindPosMan_headingNew->setRange( -1000000, 10000000 );
    ui->doubleSpinBox_inFuncFindPosMan_headingNew->setLocale( QLocale::English );
    ui->doubleSpinBox_inFuncFindPosMan_headingNew->setDecimals( 3 );
    ui->doubleSpinBox_inFuncFindPosMan_headingNew->setSingleStep( 1 );
    ui->doubleSpinBox_inFuncFindPosMan_headingNew->setValue( 0 );

    //===============================================================

    ui->lineEdit_findPosMan_res->setReadOnly( true );
    ui->lineEdit_findPosMan_x->setReadOnly( true );
    ui->lineEdit_findPosMan_y->setReadOnly( true );
    ui->lineEdit_findPosMan_speed->setReadOnly( true );
    ui->lineEdit_findPosMan_heading->setReadOnly( true );
    ui->lineEdit_findPosMan_path->setReadOnly( true );
}

MainWindowFindPosComplex::~MainWindowFindPosComplex()
{
    delete ui;
}

void MainWindowFindPosComplex::setFunc(importedMath::FuncFindPos_complex value)
{
    func = value;
}

void MainWindowFindPosComplex::calculate(QString value)
{
    if ( func )
    {
        std::cout << "CALCULATE FINDPOS_COMPLEX" << std::endl;

        struct TInFPMHS in;

        in.posStart.x = posStart_x;
        in.posStart.y = posStart_y;
        in.speed = speed;
        in.heading = heading;
        in.timeBeforeMan = timeBeforeMan;
        in.acceleration = acceleration;
        in.speed_new = speed_new;
        in.radiusCirc = radiusCirc;
        in.heading_new = heading_new;

        ui->lineEdit_findPosMan_res->setText( QString::number( func( time, in, &out ) ) );
        ui->lineEdit_findPosMan_x->setText( QString::number( out.x ) );
        ui->lineEdit_findPosMan_y->setText( QString::number( out.y ) );
        ui->lineEdit_findPosMan_path->setText( QString::number( out.path ) );
        ui->lineEdit_findPosMan_speed->setText( QString::number( out.speed ) );
        ui->lineEdit_findPosMan_heading->setText( QString::number( out.heading ) );

        std::vector < TDataPrj > data;

        for ( double t = 0; t < time + 10e-5; t += 1 )
        {
            TDataPrj d;

            int res = func( t, in, &out );

            if ( res != 0 )
                break;

            d.speed = out.speed;
            d.headingGrad = out.heading * 180 / M_PI;
            d.path = out.path;
            d.x = out.x;
            d.y = out.y;
            d.time = t;

            data.push_back( d );
        }

        QLineSeries * series_speed = new QLineSeries();
        series_speed->setColor( QColor( 30, 30, 200 ) );
        series_speed->setName("speed");

        QLineSeries * series_heading = new QLineSeries();
        series_heading->setColor( QColor( 30, 30, 200 ) );
        series_heading->setName("heading");

        QLineSeries * series_path = new QLineSeries();
        series_path->setColor( QColor( 30, 30, 200 ) );
        series_path->setName("path");


        std::vector < std::pair < double, double > > traj;
        for ( unsigned int i = 0; i < data.size(); ++i)
        {
            TDataPrj d = data[ i ];

            * series_speed << QPointF( (qreal) d.time, (qreal) d.speed );

            * series_heading << QPointF( (qreal) d.time, (qreal) d.headingGrad );

            * series_path << QPointF( (qreal) d.time, (qreal) d.path );

            std::pair < double, double > p;

            p.first = d.x;
            p.second = d.y;

            traj.push_back( p );
        }

        ui->widgetFindPosMan_xy->setXY( traj );

        ui->chartFindPosMan_speed->setRangeAxisY( 0, 40 );
        ui->chartFindPosMan_heading->setRangeAxisY( 0, 360 );

        if ( data.size() > 0 )
        {
            ui->chartFindPosMan_path->setRangeAxisY( 0, data[ data.size() - 1 ].path );
        }

        double timeMax = time;
        if ( data.size() > 0 )
        {
            //timeMax = data[ data.size() - 1 ].time;
            timeMax = time;

            ui->chartFindPosMan_speed->getChart()->axisX()->setMax( timeMax );
            ui->chartFindPosMan_speed->getChart()->removeAllSeries();
            ui->chartFindPosMan_speed->getChart()->addSeries( series_speed );
            series_speed->attachAxis( ui->chartFindPosMan_speed->getChart()->axisY() );
            series_speed->attachAxis( ui->chartFindPosMan_speed->getChart()->axisX() );

            ui->chartFindPosMan_heading->getChart()->axisX()->setMax( timeMax );
            ui->chartFindPosMan_heading->getChart()->removeAllSeries();
            ui->chartFindPosMan_heading->getChart()->addSeries( series_heading );
            series_heading->attachAxis( ui->chartFindPosMan_heading->getChart()->axisY() );
            series_heading->attachAxis( ui->chartFindPosMan_heading->getChart()->axisX() );

            ui->chartFindPosMan_path->getChart()->axisX()->setMax( timeMax );
            ui->chartFindPosMan_path->getChart()->removeAllSeries();
            ui->chartFindPosMan_path->getChart()->addSeries( series_path );
            series_path->attachAxis( ui->chartFindPosMan_path->getChart()->axisY() );
            series_path->attachAxis( ui->chartFindPosMan_path->getChart()->axisX() );
        }
        else
        {
            ui->chartFindPosMan_speed->getChart()->removeAllSeries();
            ui->chartFindPosMan_heading->getChart()->removeAllSeries();
            ui->chartFindPosMan_path->getChart()->removeAllSeries();
        }
    }
}
