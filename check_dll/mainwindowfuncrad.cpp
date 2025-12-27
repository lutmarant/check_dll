#include "mainwindowfuncrad.h"
#include "ui_mainwindowfuncrad.h"

#include <iostream>

MainWindowFuncRad::MainWindowFuncRad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowFuncRad)
{
    ui->setupUi(this);

    this->setWindowTitle( "rad" );

    connect( ui->doubleSpinBox_inFuncRad_grad, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFuncRad::calculate );
    ui->doubleSpinBox_inFuncRad_grad->setRange( -1000000, 10000000 );
    ui->doubleSpinBox_inFuncRad_grad->setLocale( QLocale::English );
    ui->doubleSpinBox_inFuncRad_grad->setDecimals( 3 );
    ui->doubleSpinBox_inFuncRad_grad->setSingleStep( 1 );
    ui->doubleSpinBox_inFuncRad_grad->setValue( 0 );

    ui->lineEdit_outFuncRad_res->setReadOnly( true );
}

MainWindowFuncRad::~MainWindowFuncRad()
{
    delete ui;
}

void MainWindowFuncRad::setFunc(importedMath::FuncRad value)
{
    funcRad = value;
}

void MainWindowFuncRad::calculate(QString value)
{
    if ( funcRad )
    {
        std::cout << "CALCULATE RAD " << std::endl;

        ui->lineEdit_outFuncRad_res->setText( QString::number( funcRad( value.toDouble() ) ) );
    }
}
