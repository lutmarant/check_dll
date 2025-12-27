#include "mainwindowfunccoordy.h"
#include "ui_mainwindowfunccoordy.h"

#include <iostream>

MainWindowFuncCoordY::MainWindowFuncCoordY(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowFuncCoordY)
{
    ui->setupUi(this);

    this->setWindowTitle( "coordY" );

    connect( ui->doubleSpinBox_inFuncCoordY_dist, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFuncCoordY::setDist );
    connect( ui->doubleSpinBox_inFuncCoordY_dist, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFuncCoordY::calculate );
    ui->doubleSpinBox_inFuncCoordY_dist->setRange( -1000000, 10000000 );
    ui->doubleSpinBox_inFuncCoordY_dist->setLocale( QLocale::English );
    ui->doubleSpinBox_inFuncCoordY_dist->setDecimals( 3 );
    ui->doubleSpinBox_inFuncCoordY_dist->setSingleStep( 1 );
    ui->doubleSpinBox_inFuncCoordY_dist->setValue( 0 );

    connect( ui->doubleSpinBox_inFuncCoordY_angleRad, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFuncCoordY::setAngleRad );
    connect( ui->doubleSpinBox_inFuncCoordY_angleRad, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFuncCoordY::calculate );
    ui->doubleSpinBox_inFuncCoordY_angleRad->setRange( -1000000, 10000000 );
    ui->doubleSpinBox_inFuncCoordY_angleRad->setLocale( QLocale::English );
    ui->doubleSpinBox_inFuncCoordY_angleRad->setDecimals( 3 );
    ui->doubleSpinBox_inFuncCoordY_angleRad->setSingleStep( 0.1 );
    ui->doubleSpinBox_inFuncCoordY_angleRad->setValue( 0 );

    ui->lineEdit_outFuncCoordY_res->setReadOnly( true );
}

MainWindowFuncCoordY::~MainWindowFuncCoordY()
{
    delete ui;
}

void MainWindowFuncCoordY::setFunc(importedMath::FuncCoordY value)
{
    func = value;
}

void MainWindowFuncCoordY::calculate(QString value)
{
    if ( func )
    {
        std::cout << "CALCULATE COORDY" << std::endl;

        ui->lineEdit_outFuncCoordY_res->setText( QString::number( func( dist, angleRad ) ) );
    }
}

void MainWindowFuncCoordY::setDist(QString value)
{
    dist = value.toDouble();
}

void MainWindowFuncCoordY::setAngleRad(QString value)
{
    angleRad = value.toDouble();
}
