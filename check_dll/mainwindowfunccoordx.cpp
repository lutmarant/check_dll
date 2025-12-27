#include "mainwindowfunccoordx.h"
#include "ui_mainwindowfunccoordx.h"

#include <iostream>

MainWindowFuncCoordX::MainWindowFuncCoordX(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowFuncCoordX)
{
    ui->setupUi(this);

    this->setWindowTitle( "coordX" );

    connect( ui->doubleSpinBox_inFuncCoordX_dist, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFuncCoordX::setDist );
    connect( ui->doubleSpinBox_inFuncCoordX_dist, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFuncCoordX::calculate );
    ui->doubleSpinBox_inFuncCoordX_dist->setRange( -1000000, 10000000 );
    ui->doubleSpinBox_inFuncCoordX_dist->setLocale( QLocale::English );
    ui->doubleSpinBox_inFuncCoordX_dist->setDecimals( 3 );
    ui->doubleSpinBox_inFuncCoordX_dist->setSingleStep( 1 );
    ui->doubleSpinBox_inFuncCoordX_dist->setValue( 0 );

    connect( ui->doubleSpinBox_inFuncCoordX_angleRad, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFuncCoordX::setAngleRad );
    connect( ui->doubleSpinBox_inFuncCoordX_angleRad, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFuncCoordX::calculate );
    ui->doubleSpinBox_inFuncCoordX_angleRad->setRange( -1000000, 10000000 );
    ui->doubleSpinBox_inFuncCoordX_angleRad->setLocale( QLocale::English );
    ui->doubleSpinBox_inFuncCoordX_angleRad->setDecimals( 3 );
    ui->doubleSpinBox_inFuncCoordX_angleRad->setSingleStep( 0.1 );
    ui->doubleSpinBox_inFuncCoordX_angleRad->setValue( 0 );

    ui->lineEdit_outFuncCoordX_res->setReadOnly( true );
}

MainWindowFuncCoordX::~MainWindowFuncCoordX()
{
    delete ui;
}

void MainWindowFuncCoordX::setFunc(importedMath::FuncCoordX value)
{
    func = value;
}

void MainWindowFuncCoordX::calculate(QString value)
{
    if ( func )
    {
        std::cout << "CALCULATE COORDX" << std::endl;

        ui->lineEdit_outFuncCoordX_res->setText( QString::number( func( dist, angleRad ) ) );
    }
}

void MainWindowFuncCoordX::setDist(QString value)
{
    dist = value.toDouble();
}

void MainWindowFuncCoordX::setAngleRad(QString value)
{
    angleRad = value.toDouble();
}
