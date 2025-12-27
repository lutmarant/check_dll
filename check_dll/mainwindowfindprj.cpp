#include "mainwindowfindprj.h"
#include "ui_mainwindowfindprj.h"

#include <iostream>
#include <cmath>

#include <QLineSeries>

MainWindowFindPrj::MainWindowFindPrj(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowFindPrj)
{
    ui->setupUi(this);

    this->setWindowTitle( "findTimeToAlterate" );

    connect( ui->doubleSpinBox_inFuncFindPrj_time, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFindPrj::setTime );
    connect( ui->doubleSpinBox_inFuncFindPrj_time, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFindPrj::calculate );
    ui->doubleSpinBox_inFuncFindPrj_time->setRange( -1000000, 10000000 );
    ui->doubleSpinBox_inFuncFindPrj_time->setLocale( QLocale::English );
    ui->doubleSpinBox_inFuncFindPrj_time->setDecimals( 3 );
    ui->doubleSpinBox_inFuncFindPrj_time->setSingleStep( 1 );
    ui->doubleSpinBox_inFuncFindPrj_time->setValue( 0 );

    connect( ui->doubleSpinBox_inFuncFindPrj_speed, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFindPrj::setSpeed );
    connect( ui->doubleSpinBox_inFuncFindPrj_speed, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFindPrj::calculate );
    ui->doubleSpinBox_inFuncFindPrj_speed->setRange( -1000000, 10000000 );
    ui->doubleSpinBox_inFuncFindPrj_speed->setLocale( QLocale::English );
    ui->doubleSpinBox_inFuncFindPrj_speed->setDecimals( 3 );
    ui->doubleSpinBox_inFuncFindPrj_speed->setSingleStep( 1 );
    ui->doubleSpinBox_inFuncFindPrj_speed->setValue( 0 );

    connect( ui->doubleSpinBox_inFuncFindPrj_speedNew, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFindPrj::setSpeedNew );
    connect( ui->doubleSpinBox_inFuncFindPrj_speedNew, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFindPrj::calculate );
    ui->doubleSpinBox_inFuncFindPrj_speedNew->setRange( -1000000, 10000000 );
    ui->doubleSpinBox_inFuncFindPrj_speedNew->setLocale( QLocale::English );
    ui->doubleSpinBox_inFuncFindPrj_speedNew->setDecimals( 3 );
    ui->doubleSpinBox_inFuncFindPrj_speedNew->setSingleStep( 1 );
    ui->doubleSpinBox_inFuncFindPrj_speedNew->setValue( 0 );

    connect( ui->doubleSpinBox_inFuncFindPrj_acceleration, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFindPrj::setAcceleration );
    connect( ui->doubleSpinBox_inFuncFindPrj_acceleration, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFindPrj::calculate );
    ui->doubleSpinBox_inFuncFindPrj_acceleration->setRange( -1000000, 10000000 );
    ui->doubleSpinBox_inFuncFindPrj_acceleration->setLocale( QLocale::English );
    ui->doubleSpinBox_inFuncFindPrj_acceleration->setDecimals( 3 );
    ui->doubleSpinBox_inFuncFindPrj_acceleration->setSingleStep( 1 );
    ui->doubleSpinBox_inFuncFindPrj_acceleration->setValue( 0 );

    connect( ui->doubleSpinBox_inFuncFindPrj_heading, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFindPrj::setHeading );
    connect( ui->doubleSpinBox_inFuncFindPrj_heading, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFindPrj::calculate );
    ui->doubleSpinBox_inFuncFindPrj_heading->setRange( -1000000, 10000000 );
    ui->doubleSpinBox_inFuncFindPrj_heading->setLocale( QLocale::English );
    ui->doubleSpinBox_inFuncFindPrj_heading->setDecimals( 3 );
    ui->doubleSpinBox_inFuncFindPrj_heading->setSingleStep( 1 );
    ui->doubleSpinBox_inFuncFindPrj_heading->setValue( 0 );

    connect( ui->doubleSpinBox_inFuncFindPrj_headingNew, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFindPrj::setHeadingNew );
    connect( ui->doubleSpinBox_inFuncFindPrj_headingNew, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFindPrj::calculate );
    ui->doubleSpinBox_inFuncFindPrj_headingNew->setRange( -1000000, 10000000 );
    ui->doubleSpinBox_inFuncFindPrj_headingNew->setLocale( QLocale::English );
    ui->doubleSpinBox_inFuncFindPrj_headingNew->setDecimals( 3 );
    ui->doubleSpinBox_inFuncFindPrj_headingNew->setSingleStep( 1 );
    ui->doubleSpinBox_inFuncFindPrj_headingNew->setValue( 0 );

    connect( ui->doubleSpinBox_inFuncFindPrj_radiusCirc, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFindPrj::setRadiusCirc );
    connect( ui->doubleSpinBox_inFuncFindPrj_radiusCirc, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFindPrj::calculate );
    ui->doubleSpinBox_inFuncFindPrj_radiusCirc->setRange( -1000000, 10000000 );
    ui->doubleSpinBox_inFuncFindPrj_radiusCirc->setLocale( QLocale::English );
    ui->doubleSpinBox_inFuncFindPrj_radiusCirc->setDecimals( 3 );
    ui->doubleSpinBox_inFuncFindPrj_radiusCirc->setSingleStep( 1 );
    ui->doubleSpinBox_inFuncFindPrj_radiusCirc->setValue( 0 );

    ui->lineEdit_outFuncFindPrj_res->setReadOnly( true );
    ui->lineEdit_outFuncFindPrj_x->setReadOnly( true );
    ui->lineEdit_outFuncFindPrj_y->setReadOnly( true );
    ui->lineEdit_outFuncFindPrj_path->setReadOnly( true );
    ui->lineEdit_outFuncFindPrj_speed->setReadOnly( true );
    ui->lineEdit_outFuncFindPrj_heading->setReadOnly( true );
}

MainWindowFindPrj::~MainWindowFindPrj()
{
    delete ui;
}

void MainWindowFindPrj::setFunc(importedMath::FuncFindPrj value)
{
    func = value;
}

void MainWindowFindPrj::calculate(QString value)
{
    if ( func )
    {
        std::cout << "CALCULATE FINDPRJ" << std::endl;

        struct TInFindPrj in;
        in.speed = speed;
        in.speed_new = speed_new;
        in.acceleration = acceleration;

        in.heading = heading;
        in.heading_new = heading_new;
        in.radiusCirc = radiusCirc;

        ui->lineEdit_outFuncFindPrj_res->setText( QString::number( func( time, in, &out ) ) );
        ui->lineEdit_outFuncFindPrj_x->setText( QString::number( out.x ) );
        ui->lineEdit_outFuncFindPrj_y->setText( QString::number( out.y ) );
        ui->lineEdit_outFuncFindPrj_path->setText( QString::number( out.path ) );
        ui->lineEdit_outFuncFindPrj_speed->setText( QString::number( out.speed ) );
        ui->lineEdit_outFuncFindPrj_heading->setText( QString::number( out.heading ) );

        std::vector < TDataPrj > data;

        for ( double t = 0; t < time + 10e-5; t += 0.1 )
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

        ui->widget_xy->setXY( traj );

        ui->chart_speed->setRangeAxisY( 0, 40 );
        ui->chart_heading->setRangeAxisY( 0, 360 );

        if ( data.size() > 0 )
        {
            ui->chart_path->setRangeAxisY( 0, data[ data.size() - 1 ].path );
        }

        double timeMax = time;
        if ( data.size() > 0 )
        {
            //timeMax = data[ data.size() - 1 ].time;
            timeMax = time;

            ui->chart_speed->getChart()->axisX()->setMax( timeMax );
            ui->chart_speed->getChart()->removeAllSeries();
            ui->chart_speed->getChart()->addSeries( series_speed );
            series_speed->attachAxis( ui->chart_speed->getChart()->axisY() );
            series_speed->attachAxis( ui->chart_speed->getChart()->axisX() );

            ui->chart_heading->getChart()->axisX()->setMax( timeMax );
            ui->chart_heading->getChart()->removeAllSeries();
            ui->chart_heading->getChart()->addSeries( series_heading );
            series_heading->attachAxis( ui->chart_heading->getChart()->axisY() );
            series_heading->attachAxis( ui->chart_heading->getChart()->axisX() );

            ui->chart_path->getChart()->axisX()->setMax( timeMax );
            ui->chart_path->getChart()->removeAllSeries();
            ui->chart_path->getChart()->addSeries( series_path );
            series_path->attachAxis( ui->chart_path->getChart()->axisY() );
            series_path->attachAxis( ui->chart_path->getChart()->axisX() );
        }
        else
        {
            ui->chart_speed->getChart()->removeAllSeries();
            ui->chart_heading->getChart()->removeAllSeries();
            ui->chart_path->getChart()->removeAllSeries();
        }
    }
}

void MainWindowFindPrj::setTime(QString value)
{
    time = value.toDouble();
}

void MainWindowFindPrj::setSpeed(QString value)
{
    speed = value.toDouble();
}

void MainWindowFindPrj::setSpeedNew(QString value)
{
    speed_new = value.toDouble();
}

void MainWindowFindPrj::setAcceleration(QString value)
{
    acceleration = value.toDouble();
}

void MainWindowFindPrj::setHeading(QString value)
{
    heading = value.toDouble();
}

void MainWindowFindPrj::setHeadingNew(QString value)
{
    heading_new = value.toDouble();
}

void MainWindowFindPrj::setRadiusCirc(QString value)
{
    radiusCirc = value.toDouble();
}
