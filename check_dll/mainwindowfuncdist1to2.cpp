#include "mainwindowfuncdist1to2.h"
#include "ui_mainwindowfuncdist1to2.h"

#include <iostream>

MainWindowFuncDist1to2::MainWindowFuncDist1to2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowFuncDist1to2)
{
    ui->setupUi(this);

    this->setWindowTitle( "dist_1to2" );

    connect( ui->doubleSpinBox_inFuncDist1to2_x1, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFuncDist1to2::setX1 );
    connect( ui->doubleSpinBox_inFuncDist1to2_x1, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFuncDist1to2::calculate );
    ui->doubleSpinBox_inFuncDist1to2_x1->setRange( -1000000, 10000000 );
    ui->doubleSpinBox_inFuncDist1to2_x1->setLocale( QLocale::English );
    ui->doubleSpinBox_inFuncDist1to2_x1->setDecimals( 3 );
    ui->doubleSpinBox_inFuncDist1to2_x1->setSingleStep( 1 );
    ui->doubleSpinBox_inFuncDist1to2_x1->setValue( 0 );

    connect( ui->doubleSpinBox_inFuncDist1to2_y1, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFuncDist1to2::setY1 );
    connect( ui->doubleSpinBox_inFuncDist1to2_y1, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFuncDist1to2::calculate );
    ui->doubleSpinBox_inFuncDist1to2_y1->setRange( -1000000, 10000000 );
    ui->doubleSpinBox_inFuncDist1to2_y1->setLocale( QLocale::English );
    ui->doubleSpinBox_inFuncDist1to2_y1->setDecimals( 3 );
    ui->doubleSpinBox_inFuncDist1to2_y1->setSingleStep( 1 );
    ui->doubleSpinBox_inFuncDist1to2_y1->setValue( 0 );

    connect( ui->doubleSpinBox_inFuncDist1to2_x2, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFuncDist1to2::setX2 );
    connect( ui->doubleSpinBox_inFuncDist1to2_x2, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFuncDist1to2::calculate );
    ui->doubleSpinBox_inFuncDist1to2_x2->setRange( -1000000, 10000000 );
    ui->doubleSpinBox_inFuncDist1to2_x2->setLocale( QLocale::English );
    ui->doubleSpinBox_inFuncDist1to2_x2->setDecimals( 3 );
    ui->doubleSpinBox_inFuncDist1to2_x2->setSingleStep( 1 );
    ui->doubleSpinBox_inFuncDist1to2_x2->setValue( 0 );

    connect( ui->doubleSpinBox_inFuncDist1to2_y2, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFuncDist1to2::setY2 );
    connect( ui->doubleSpinBox_inFuncDist1to2_y2, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFuncDist1to2::calculate );
    ui->doubleSpinBox_inFuncDist1to2_y2->setRange( -1000000, 10000000 );
    ui->doubleSpinBox_inFuncDist1to2_y2->setLocale( QLocale::English );
    ui->doubleSpinBox_inFuncDist1to2_y2->setDecimals( 3 );
    ui->doubleSpinBox_inFuncDist1to2_y2->setSingleStep( 1 );
    ui->doubleSpinBox_inFuncDist1to2_y2->setValue( 0 );

    ui->lineEdit_outFuncDist1to2_res->setReadOnly( true );
}

MainWindowFuncDist1to2::~MainWindowFuncDist1to2()
{
    delete ui;
}

void MainWindowFuncDist1to2::setFunc(importedMath::FuncDist_1to2 value)
{
    func = value;
}

void MainWindowFuncDist1to2::calculate(QString value)
{
    if ( func )
    {
        std::cout << "CALCULATE DIST1TO2" << std::endl;

        ui->lineEdit_outFuncDist1to2_res->setText( QString::number( func( x1, y1, x2, y2 ) ) );
    }
}

void MainWindowFuncDist1to2::setX1(QString value)
{
    x1 = value.toDouble();
}

void MainWindowFuncDist1to2::setY1(QString value)
{
    y1 = value.toDouble();
}

void MainWindowFuncDist1to2::setX2(QString value)
{
    x2 = value.toDouble();
}

void MainWindowFuncDist1to2::setY2(QString value)
{
    y2 = value.toDouble();
}
