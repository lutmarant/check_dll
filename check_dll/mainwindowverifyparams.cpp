#include "mainwindowverifyparams.h"
#include "ui_mainwindowverifyparams.h"

MainWindowVerifyParams::MainWindowVerifyParams(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowVerifyParams)
{
    ui->setupUi(this);
}

MainWindowVerifyParams::~MainWindowVerifyParams()
{
    delete ui;
}
