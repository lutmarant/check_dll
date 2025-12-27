#include "mainwindowfuncprivpi.h"
#include "ui_mainwindowfuncprivpi.h"

#include <iostream>

MainWindowFuncPrivPi::MainWindowFuncPrivPi(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowFuncPrivPi)
{
    ui->setupUi(this);

    this->setWindowTitle( "privPi" );

    connect( ui->doubleSpinBox_inFuncPrivPi_rad, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFuncPrivPi::calculate );
    ui->doubleSpinBox_inFuncPrivPi_rad->setRange( -1000000, 10000000 );
    ui->doubleSpinBox_inFuncPrivPi_rad->setLocale( QLocale::English );
    ui->doubleSpinBox_inFuncPrivPi_rad->setDecimals( 3 );
    ui->doubleSpinBox_inFuncPrivPi_rad->setSingleStep( 1 );
    ui->doubleSpinBox_inFuncPrivPi_rad->setValue( 0 );

    ui->lineEdit_outFuncPrivPi_res->setReadOnly( true );
}

MainWindowFuncPrivPi::~MainWindowFuncPrivPi()
{
    delete ui;
}

void MainWindowFuncPrivPi::setFunc(importedMath::FuncPriv2Pi value)
{
    func = value;
}

void MainWindowFuncPrivPi::calculate(QString value)
{
    if ( func )
    {
        std::cout << "CALCULATE PRIVPI " << std::endl;

        ui->lineEdit_outFuncPrivPi_res->setText( QString::number( func( value.toDouble() ) ) );
    }
}
