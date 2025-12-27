#include "mainwindowfuncgrad.h"
#include "ui_mainwindowfuncgrad.h"

#include <iostream>

MainWindowFuncGrad::MainWindowFuncGrad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowFuncGrad)
{
    ui->setupUi(this);

    this->setWindowTitle( "grad" );

    connect( ui->doubleSpinBox_inFuncGrad_rad, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFuncGrad::calculate );
    ui->doubleSpinBox_inFuncGrad_rad->setRange( -1000000, 10000000 );
    ui->doubleSpinBox_inFuncGrad_rad->setLocale( QLocale::English );
    ui->doubleSpinBox_inFuncGrad_rad->setDecimals( 3 );
    ui->doubleSpinBox_inFuncGrad_rad->setSingleStep( 1 );
    ui->doubleSpinBox_inFuncGrad_rad->setValue( 0 );

    ui->lineEdit_outFuncGrad_res->setReadOnly( true );
}

MainWindowFuncGrad::~MainWindowFuncGrad()
{
    delete ui;
}

void MainWindowFuncGrad::setFunc(importedMath::FuncGrad value)
{
    funcGrad = value;
}

void MainWindowFuncGrad::calculate(QString value)
{
    if ( funcGrad )
    {
        std::cout << "CALCULATE GRAD " << std::endl;

        ui->lineEdit_outFuncGrad_res->setText( QString::number( funcGrad( value.toDouble() ) ) );
    }
}
