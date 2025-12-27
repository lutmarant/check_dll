#include "mainwindowfuncpriv2pi.h"
#include "ui_mainwindowfuncpriv2pi.h"

#include <iostream>

MainWindowFuncPriv2Pi::MainWindowFuncPriv2Pi(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowFuncPriv2Pi)
{
    ui->setupUi(this);

    this->setWindowTitle( "priv2Pi" );

    connect( ui->doubleSpinBox_inFuncPriv2Pi_rad, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowFuncPriv2Pi::calculate );
    ui->doubleSpinBox_inFuncPriv2Pi_rad->setRange( -1000000, 10000000 );
    ui->doubleSpinBox_inFuncPriv2Pi_rad->setLocale( QLocale::English );
    ui->doubleSpinBox_inFuncPriv2Pi_rad->setDecimals( 3 );
    ui->doubleSpinBox_inFuncPriv2Pi_rad->setSingleStep( 1 );
    ui->doubleSpinBox_inFuncPriv2Pi_rad->setValue( 0 );

    ui->lineEdit_outFuncPriv2Pi_res->setReadOnly( true );
}

MainWindowFuncPriv2Pi::~MainWindowFuncPriv2Pi()
{
    delete ui;
}

void MainWindowFuncPriv2Pi::setFunc(importedMath::FuncPriv2Pi value)
{
    func = value;
}

void MainWindowFuncPriv2Pi::calculate(QString value)
{
    if ( func )
    {
        std::cout << "CALCULATE PRIV2PI " << std::endl;

        ui->lineEdit_outFuncPriv2Pi_res->setText( QString::number( func( value.toDouble() ) ) );
    }
}
