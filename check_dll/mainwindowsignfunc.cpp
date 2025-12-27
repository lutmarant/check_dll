#include "mainwindowsignfunc.h"
#include "ui_mainwindowsignfunc.h"

#include <QDoubleSpinBox>
#include <QLineEdit>

#include <iostream>

MainWindowSignFunc::MainWindowSignFunc(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowSignFunc)
{
    ui->setupUi(this);

    this->setWindowTitle( "sign" );

    connect( ui->doubleSpinBox_inSignFunc_x, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), this, &MainWindowSignFunc::calculate );
    ui->doubleSpinBox_inSignFunc_x->setRange( -1000000, 10000000 );
    ui->doubleSpinBox_inSignFunc_x->setLocale( QLocale::English );
    ui->doubleSpinBox_inSignFunc_x->setDecimals( 3 );
    ui->doubleSpinBox_inSignFunc_x->setSingleStep( 1 );
    ui->doubleSpinBox_inSignFunc_x->setValue( 0 );

    ui->lineEdit_outSignFunc_res->setReadOnly( true );
}

MainWindowSignFunc::~MainWindowSignFunc()
{
    delete ui;
}

void MainWindowSignFunc::setSignFunc(importedMath::FuncSign value)
{
    funcSign = value;
}

void MainWindowSignFunc::calculate(  QString value  )
{
    if ( funcSign )
    {
        std::cout << "CALCULATE SIGN " << std::endl;

        ui->lineEdit_outSignFunc_res->setText( QString::number( funcSign( value.toDouble() ) ) );
    }
}
