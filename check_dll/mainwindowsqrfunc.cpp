#include "mainwindowsqrfunc.h"
#include "ui_mainwindowsqrfunc.h"

#include <QDoubleSpinBox>
#include <QLineEdit>

#include <iostream>

MainWindowSqrFunc::MainWindowSqrFunc(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowSqrFunc)
{
    ui->setupUi(this);

    this->setWindowTitle( "sqr" );

    connect( ui->doubleSpinBox_inFuncSqr_x, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowSqrFunc::calculate );
    ui->doubleSpinBox_inFuncSqr_x->setRange( -1000000, 10000000 );
    ui->doubleSpinBox_inFuncSqr_x->setLocale( QLocale::English );
    ui->doubleSpinBox_inFuncSqr_x->setDecimals( 3 );
    ui->doubleSpinBox_inFuncSqr_x->setSingleStep( 1 );
    ui->doubleSpinBox_inFuncSqr_x->setValue( 0 );

    ui->lineEdit_outFuncSqr_res->setReadOnly( true );
}

MainWindowSqrFunc::~MainWindowSqrFunc()
{
    delete ui;
}

void MainWindowSqrFunc::setFunc(importedMath::FuncSqr value)
{
    funcSqr = value;
}

void MainWindowSqrFunc::calculate(QString value)
{
    if ( funcSqr )
    {
        std::cout << "CALCULATE SQR " << std::endl;

        ui->lineEdit_outFuncSqr_res->setText( QString::number( funcSqr( value.toDouble() ) ) );
    }
}
