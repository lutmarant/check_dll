#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDoubleSpinBox>
#include <QLineSeries>

#include "mainwindowsignfunc.h"
#include "mainwindowsqrfunc.h"
#include "mainwindowfuncrad.h"
#include "mainwindowfuncgrad.h"
#include "mainwindowfuncpriv2pi.h"
#include "mainwindowfuncprivpi.h"
#include "mainwindowfunccoordx.h"
#include "mainwindowfunccoordy.h"
#include "mainwindowfuncdist1to2.h"
#include "mainwindowfuncangle1to2.h"
#include "mainwindowfuncfindtime.h"
#include "mainwindowfindprj.h"
#include "mainwindowfindposcomplex.h"

void setDoubleSpinBoxParams( QDoubleSpinBox * spinBox, double min, double max, double step, int decimals, double valueInit )
{
    spinBox->setRange( min, max );
    spinBox->setLocale( QLocale::English );
    spinBox->setDecimals( decimals );
    spinBox->setSingleStep( step );
    spinBox->setValue( valueInit );
}

void setPushButtonColor( QPushButton * pushButton, QColor color )
{
    QPalette palette = pushButton->palette();
    palette.setColor( QPalette::Button, color );
    pushButton->setAutoFillBackground( true );
    pushButton->setPalette( palette );
    pushButton->update();
}

void setIndicatorParams( QPushButton * pushButton )
{
    //pushButton->setFlat( true );
    pushButton->setEnabled( true );

    setPushButtonColor( pushButton, QColor( 220, 220, 220 ) );
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle( "Проверка функций собственной библиотеки" );

    setIndicatorParams( ui->pushButton_connectionLib );
    setIndicatorParams( ui->pushButton_funcSignIsOk );
    setIndicatorParams( ui->pushButton_funcSqrIsOk );
    setIndicatorParams( ui->pushButton_funcRadIsOk );
    setIndicatorParams( ui->pushButton_funcGradIsOk );
    setIndicatorParams( ui->pushButton_funcPriv2PiIsOk );
    setIndicatorParams( ui->pushButton_funcPrivPiIsOk );
    setIndicatorParams( ui->pushButton_funcCoordXIsOk );
    setIndicatorParams( ui->pushButton_funcCoordYIsOk );
    setIndicatorParams( ui->pushButton_funcDist1to2IsOk );
    setIndicatorParams( ui->pushButton_funcAngle1to2IsOk );
    setIndicatorParams( ui->pushButton_funcValidateIsOk );
    setIndicatorParams( ui->pushButton_funcTimeIsOk );
    setIndicatorParams( ui->pushButton_funcTrajPartIsOk );
    setIndicatorParams( ui->pushButton_funcFindPos_sc );
    setIndicatorParams( ui->pushButton_func2Z );
    setIndicatorParams( ui->pushButton_funcUniformDistribution );
    setIndicatorParams( ui->pushButton_funcNormalDistribution );
    setIndicatorParams( ui->pushButton_mean );
    setIndicatorParams( ui->pushButton_variance );
    setIndicatorParams( ui->pushButton_funcFindPosComplex );

    connectDataInputElementsToView();

    //ui->pushButton_funcFindPos_sc->hide();
    ui->pushButton_func2Z->hide();
    ui->pushButton_funcFindPos_sc->hide();

    this->checkFuncs();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectDataInputElementsToView()
{
    //    connect( ui->doubleSpinBox_speed, &QDoubleSpinBox::textChanged, ui->graphicsView, &View::setSpeed );
    //connect( ui->doubleSpinBox_speed, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), ui->graphicsView, &View::setSpeed );
}

void MainWindow::disconnectDataInputElementsFromView()
{
    //    disconnect( ui->doubleSpinBox_speed, &QDoubleSpinBox::textChanged, ui->graphicsView, &View::setSpeed );
    //disconnect( ui->doubleSpinBox_speed, static_cast<void (QDoubleSpinBox::*)(const QString &)>(&QDoubleSpinBox::valueChanged), ui->graphicsView, &View::setSpeed );
}

void MainWindow::checkFuncs()
{
    if ( impMath.libIsLoaded() )
        setPushButtonColor( ui->pushButton_connectionLib, colorSemiOk );
    else
        setPushButtonColor( ui->pushButton_connectionLib, colorNotOk );

    if ( impMath.libIsLoaded() )
    {
        if ( impMath.checkAllFuncs() )
            setPushButtonColor( ui->pushButton_connectionLib, colorFullOk );

        if ( impMath.funcSignIsLoaded() )
            setPushButtonColor( ui->pushButton_funcSignIsOk, colorQuarterOk );
        else
            setPushButtonColor( ui->pushButton_funcSignIsOk, colorNotOk );

        if ( impMath.funcSqrIsLoaded() )
            setPushButtonColor( ui->pushButton_funcSqrIsOk, colorQuarterOk );
        else
            setPushButtonColor( ui->pushButton_funcSqrIsOk, colorNotOk );

        if ( impMath.funcRadIsLoaded() )
            setPushButtonColor( ui->pushButton_funcRadIsOk, colorQuarterOk );
        else
            setPushButtonColor( ui->pushButton_funcRadIsOk, colorNotOk );

        if ( impMath.funcGradIsLoaded() )
            setPushButtonColor( ui->pushButton_funcGradIsOk, colorQuarterOk );
        else
            setPushButtonColor( ui->pushButton_funcGradIsOk, colorNotOk );

        if ( impMath.funcPriv2PiIsLoaded() )
            setPushButtonColor( ui->pushButton_funcPriv2PiIsOk, colorQuarterOk );
        else
            setPushButtonColor( ui->pushButton_funcPriv2PiIsOk, colorNotOk );

        if ( impMath.funcPrivPiIsLoaded() )
            setPushButtonColor( ui->pushButton_funcPrivPiIsOk, colorQuarterOk );
        else
            setPushButtonColor( ui->pushButton_funcPrivPiIsOk, colorNotOk );

        if ( impMath.funcCoordXIsLoaded() )
            setPushButtonColor( ui->pushButton_funcCoordXIsOk, colorQuarterOk );
        else
            setPushButtonColor( ui->pushButton_funcCoordXIsOk, colorNotOk );

        if ( impMath.funcCoordYIsLoaded() )
            setPushButtonColor( ui->pushButton_funcCoordYIsOk, colorQuarterOk );
        else
            setPushButtonColor( ui->pushButton_funcCoordYIsOk, colorNotOk );


        if ( impMath.funcDist1to2IsLoaded() )
            setPushButtonColor( ui->pushButton_funcDist1to2IsOk, colorQuarterOk );
        else
            setPushButtonColor( ui->pushButton_funcDist1to2IsOk, colorNotOk );

        if ( impMath.funcAngle1to2IsLoaded() )
            setPushButtonColor( ui->pushButton_funcAngle1to2IsOk, colorQuarterOk );
        else
            setPushButtonColor( ui->pushButton_funcAngle1to2IsOk, colorNotOk );

        if ( impMath.funcVerifyParamsIsLoaded() )
            setPushButtonColor( ui->pushButton_funcValidateIsOk, colorQuarterOk );
        else
            setPushButtonColor( ui->pushButton_funcValidateIsOk, colorNotOk );

        if ( impMath.funcFindTimeToAlterateIsLoaded() )
            setPushButtonColor( ui->pushButton_funcTimeIsOk, colorQuarterOk );
        else
            setPushButtonColor( ui->pushButton_funcTimeIsOk, colorNotOk );

        if ( impMath.funcFindPrjIsLoaded() )
            setPushButtonColor( ui->pushButton_funcTrajPartIsOk, colorQuarterOk );
        else
            setPushButtonColor( ui->pushButton_funcTrajPartIsOk, colorNotOk );

        if ( impMath.funcFindPrjIsLoaded() )
            setPushButtonColor( ui->pushButton_funcTrajPartIsOk, colorQuarterOk );
        else
            setPushButtonColor( ui->pushButton_funcTrajPartIsOk, colorNotOk );

        if ( impMath.funcUniformDistributionIsLoaded() )
            setPushButtonColor( ui->pushButton_funcUniformDistribution, colorQuarterOk );
        else
            setPushButtonColor( ui->pushButton_funcUniformDistribution, colorNotOk );

        if ( impMath.funcNormalDistributionIsLoaded() )
            setPushButtonColor( ui->pushButton_funcNormalDistribution, colorQuarterOk );
        else
            setPushButtonColor( ui->pushButton_funcNormalDistribution, colorNotOk );

        if ( impMath.funcFindPosSCIsLoaded() )
            setPushButtonColor( ui->pushButton_funcFindPos_sc, colorQuarterOk );
        else
            setPushButtonColor( ui->pushButton_funcFindPos_sc, colorNotOk );

        if ( impMath.funcFuncEstimateMotionParams2ZIsLoaded() )
            setPushButtonColor( ui->pushButton_func2Z, colorQuarterOk );
        else
            setPushButtonColor( ui->pushButton_func2Z, colorNotOk );

        if ( impMath.funcGetMeanIsLoaded() )
            setPushButtonColor( ui->pushButton_mean, colorQuarterOk );
        else
            setPushButtonColor( ui->pushButton_mean, colorNotOk );

        if ( impMath.funcGetVarianceIsLoaded() )
            setPushButtonColor( ui->pushButton_variance, colorQuarterOk );
        else
            setPushButtonColor( ui->pushButton_variance, colorNotOk );

        if ( impMath.funcFindPosComplexIsLoaaded() )
            setPushButtonColor( ui->pushButton_funcFindPosComplex, colorQuarterOk );
        else
            setPushButtonColor( ui->pushButton_funcFindPosComplex, colorNotOk );

        //    //==================================================

        if ( impMath.getFuncSignIsOk() && impMath.funcSignIsLoaded() )
            setPushButtonColor( ui->pushButton_funcSignIsOk, colorFullOk );
        else if ( ( !impMath.getFuncSignIsOk() ) && impMath.funcSignIsLoaded() )
            setPushButtonColor( ui->pushButton_funcSignIsOk, colorSemiOk );

        if ( impMath.getFuncSqrIsOk() && impMath.funcSqrIsLoaded() )
            setPushButtonColor( ui->pushButton_funcSqrIsOk, colorFullOk );
        else if ( ( !impMath.getFuncSqrIsOk() ) && impMath.funcSqrIsLoaded() )
            setPushButtonColor( ui->pushButton_funcSqrIsOk, colorSemiOk );

        if ( impMath.getFuncRadIsOk() && impMath.funcRadIsLoaded() )
            setPushButtonColor( ui->pushButton_funcRadIsOk, colorFullOk );
        else if ( ( !impMath.getFuncRadIsOk() ) && impMath.funcRadIsLoaded() )
            setPushButtonColor( ui->pushButton_funcRadIsOk, colorSemiOk );

        if ( impMath.getFuncGradIsOk() && impMath.funcGradIsLoaded() )
            setPushButtonColor( ui->pushButton_funcGradIsOk, colorFullOk );
        else if ( ( !impMath.getFuncGradIsOk() ) && impMath.funcGradIsLoaded() )
            setPushButtonColor( ui->pushButton_funcGradIsOk, colorSemiOk );

        if ( impMath.getFuncPriv2PiIsOk() && impMath.funcPriv2PiIsLoaded() )
            setPushButtonColor( ui->pushButton_funcPriv2PiIsOk, colorFullOk );
        else if ( ( !impMath.getFuncPriv2PiIsOk() ) && impMath.funcPriv2PiIsLoaded() )
            setPushButtonColor( ui->pushButton_funcPriv2PiIsOk, colorSemiOk );

        if ( impMath.getFuncPrivPiIsOk() && impMath.funcPrivPiIsLoaded() )
            setPushButtonColor( ui->pushButton_funcPrivPiIsOk, colorFullOk );
        else if ( ( !impMath.getFuncPrivPiIsOk() ) && impMath.funcPrivPiIsLoaded() )
            setPushButtonColor( ui->pushButton_funcPrivPiIsOk, colorSemiOk );

        if ( impMath.getFuncCoordXIsOk() && impMath.funcCoordXIsLoaded() )
            setPushButtonColor( ui->pushButton_funcCoordXIsOk, colorFullOk );
        else if ( ( !impMath.getFuncCoordXIsOk() ) && impMath.funcCoordXIsLoaded() )
            setPushButtonColor( ui->pushButton_funcCoordXIsOk, colorSemiOk );

        if ( impMath.getFuncCoordYIsOk() && impMath.funcCoordYIsLoaded() )
            setPushButtonColor( ui->pushButton_funcCoordYIsOk, colorFullOk );
        else if ( ( !impMath.getFuncCoordYIsOk() ) && impMath.funcCoordYIsLoaded() )
            setPushButtonColor( ui->pushButton_funcCoordYIsOk, colorSemiOk );

        if ( impMath.getFuncDist1to2IsOk() && impMath.funcDist1to2IsLoaded() )
            setPushButtonColor( ui->pushButton_funcDist1to2IsOk, colorFullOk );
        else if ( ( !impMath.getFuncDist1to2IsOk() ) && impMath.funcDist1to2IsLoaded() )
            setPushButtonColor( ui->pushButton_funcDist1to2IsOk, colorSemiOk );

        if ( impMath.getFuncAngle1to2IsOk() && impMath.funcAngle1to2IsLoaded() )
            setPushButtonColor( ui->pushButton_funcAngle1to2IsOk, colorFullOk );
        else if ( ( !impMath.getFuncAngle1to2IsOk() ) && impMath.funcAngle1to2IsLoaded() )
            setPushButtonColor( ui->pushButton_funcAngle1to2IsOk, colorSemiOk );

        if ( impMath.getFuncVerifyParamsIsOk() && impMath.funcVerifyParamsIsLoaded() )
            setPushButtonColor( ui->pushButton_funcValidateIsOk, colorFullOk );
        else if ( ( !impMath.getFuncVerifyParamsIsOk() ) && impMath.funcVerifyParamsIsLoaded() )
            setPushButtonColor( ui->pushButton_funcValidateIsOk, colorSemiOk );

        if ( impMath.getFuncFindTimeToAlterateIsOk() && impMath.funcFindTimeToAlterateIsLoaded() )
            setPushButtonColor( ui->pushButton_funcTimeIsOk, colorFullOk );
        else if ( ( !impMath.getFuncFindTimeToAlterateIsOk() ) && impMath.funcFindTimeToAlterateIsLoaded() )
            setPushButtonColor( ui->pushButton_funcTimeIsOk, colorSemiOk );

        if ( impMath.getFuncFindPrjIsOk() && impMath.funcFindPrjIsLoaded() )
            setPushButtonColor( ui->pushButton_funcTrajPartIsOk, colorFullOk );
        else if ( ( !impMath.getFuncFindPrjIsOk() ) && impMath.funcFindPrjIsLoaded() )
            setPushButtonColor( ui->pushButton_funcTrajPartIsOk, colorSemiOk );

        if ( impMath.getFuncUniformDistributionIsOk() && impMath.funcUniformDistributionIsLoaded() )
            setPushButtonColor( ui->pushButton_funcUniformDistribution, colorFullOk );
        else if ( impMath.funcUniformDistributionIsLoaded() && ( !impMath.getFuncUniformDistributionIsOk() ) )
            setPushButtonColor( ui->pushButton_funcUniformDistribution, colorSemiOk );

        if ( impMath.getFuncNormalDistributionIsOk() && impMath.funcNormalDistributionIsLoaded() )
            setPushButtonColor( ui->pushButton_funcNormalDistribution, colorFullOk );
        else if ( ( !impMath.getFuncNormalDistributionIsOk() ) && impMath.funcNormalDistributionIsLoaded() )
            setPushButtonColor( ui->pushButton_funcNormalDistribution, colorSemiOk );

        if ( impMath.getFuncFindPosSCIsOk() && impMath.funcFindPosSCIsLoaded() )
            setPushButtonColor( ui->pushButton_funcFindPos_sc, colorFullOk );
        else if ( ( !impMath.getFuncFindPosSCIsOk() ) && impMath.funcFindPosSCIsLoaded() )
            setPushButtonColor( ui->pushButton_funcFindPos_sc, colorSemiOk );

        if ( impMath.getFuncEstimateMotionParams2ZIsOk() && impMath.funcFuncEstimateMotionParams2ZIsLoaded() )
            setPushButtonColor( ui->pushButton_func2Z, colorFullOk );
        else if ( ( !impMath.getFuncFindPosSCIsOk() ) && impMath.funcFindPosSCIsLoaded() )
            setPushButtonColor( ui->pushButton_func2Z, colorSemiOk );

        if ( impMath.getFuncGetMeanIsOk() && impMath.funcGetMeanIsLoaded() )
            setPushButtonColor( ui->pushButton_mean, colorFullOk );
        else if ( ( !impMath.getFuncGetMeanIsOk() ) && impMath.funcGetMeanIsLoaded() )
            setPushButtonColor( ui->pushButton_mean, colorSemiOk );

        if ( impMath.getFuncGetVarianceIsOk() && impMath.funcGetVarianceIsLoaded() )
            setPushButtonColor( ui->pushButton_variance, colorFullOk );
        else if ( ( !impMath.getFuncGetVarianceIsOk() ) && impMath.funcGetVarianceIsLoaded() )
            setPushButtonColor( ui->pushButton_variance, colorSemiOk );

        if ( impMath.getFuncFindPosComplexIsOk() && impMath.funcFindPosComplexIsLoaaded() )
            setPushButtonColor( ui->pushButton_funcFindPosComplex, colorFullOk );
        else if ( ( !impMath.getFuncFindPosComplexIsOk() ) && impMath.funcFindPosComplexIsLoaaded() )
            setPushButtonColor( ui->pushButton_funcFindPosComplex, colorSemiOk );
    }
}

void MainWindow::on_pushButton_funcSignIsOk_clicked()
{
    MainWindowSignFunc * mainWindowSignFunc = new MainWindowSignFunc( this ); //= new MainWindowSignFunc( this );
    mainWindowSignFunc->setSignFunc( impMath.getSign() );
    mainWindowSignFunc->show();
}

void MainWindow::on_pushButton_funcSqrIsOk_clicked()
{
    MainWindowSqrFunc * mainWindowSqrFunc = new MainWindowSqrFunc( this );
    mainWindowSqrFunc->setFunc( impMath.getSqr() );
    mainWindowSqrFunc->show();
}

void MainWindow::on_pushButton_funcRadIsOk_clicked()
{
    MainWindowFuncRad * mainWindowFuncRad = new MainWindowFuncRad( this );
    mainWindowFuncRad->setFunc( impMath.getRad() );
    mainWindowFuncRad->show();
}

void MainWindow::on_pushButton_funcGradIsOk_clicked()
{
    MainWindowFuncGrad * mainWindowFuncGrad = new MainWindowFuncGrad( this );
    mainWindowFuncGrad->setFunc( impMath.getGrad() );
    mainWindowFuncGrad->show();
}

void MainWindow::on_pushButton_funcPriv2PiIsOk_clicked()
{
    MainWindowFuncPriv2Pi * mainWindowFuncPriv2Pi = new MainWindowFuncPriv2Pi( this );
    mainWindowFuncPriv2Pi->setFunc( impMath.getPriv2Pi() );
    mainWindowFuncPriv2Pi->show();
}

void MainWindow::on_pushButton_funcPrivPiIsOk_clicked()
{
    MainWindowFuncPrivPi * mainWindowFuncPrivPi = new MainWindowFuncPrivPi( this );
    mainWindowFuncPrivPi->setFunc( impMath.getPrivPi() );
    mainWindowFuncPrivPi->show();
}

void MainWindow::on_pushButton_funcCoordXIsOk_clicked()
{
    MainWindowFuncCoordX * mainWindowFuncCoordX = new MainWindowFuncCoordX( this );
    mainWindowFuncCoordX->setFunc( impMath.getCoordX() );
    mainWindowFuncCoordX->show();
}

void MainWindow::on_pushButton_funcCoordYIsOk_clicked()
{
    MainWindowFuncCoordY * mainWindowFuncCoordY = new MainWindowFuncCoordY( this );
    mainWindowFuncCoordY->setFunc( impMath.getCoordY() );
    mainWindowFuncCoordY->show();
}

void MainWindow::on_pushButton_funcDist1to2IsOk_clicked()
{
    MainWindowFuncDist1to2 * mainWindowFuncDist1to2 = new MainWindowFuncDist1to2( this );
    mainWindowFuncDist1to2->setFunc( impMath.getDist_1to2() );
    mainWindowFuncDist1to2->show();
}

void MainWindow::on_pushButton_funcAngle1to2IsOk_clicked()
{
    MainWindowFuncAngle1to2 * mainWindowFuncAngle1to2 = new MainWindowFuncAngle1to2( this );
    mainWindowFuncAngle1to2->setFunc( impMath.getAngle_1to2() );
    mainWindowFuncAngle1to2->show();
}

void MainWindow::on_pushButton_funcTimeIsOk_clicked()
{
    MainWindowFuncFindTime * mainWindowFuncFindTime = new MainWindowFuncFindTime( this );
    mainWindowFuncFindTime->setFunc( impMath.getFuncFindTimeToAlterate() );
    mainWindowFuncFindTime->show();
}

void MainWindow::on_pushButton_funcTrajPartIsOk_clicked()
{
    MainWindowFindPrj * mainWindowFindPrj = new MainWindowFindPrj( this );
    mainWindowFindPrj->setFunc( impMath.getFuncFindPrj() );
    mainWindowFindPrj->show();

    //connect( mainWindowFindPrj, &MainWindowFindPrj::sendData, this, &MainWindow::recieveData );
}


void MainWindow::on_pushButton_funcFindPosComplex_clicked()
{
    MainWindowFindPosComplex * mainWindowFindPosComplex = new MainWindowFindPosComplex( this );
    mainWindowFindPosComplex->setFunc( impMath.getFuncFindPos_complex() );
    mainWindowFindPosComplex->show();
}
