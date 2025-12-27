#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "importedMath.h"
#include "mainwindowfindprj.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void connectDataInputElementsToView();
    void disconnectDataInputElementsFromView();

private:
    Ui::MainWindow *ui;

    importedMath::ImportedMath impMath;

    QColor colorFullOk = QColor( 0, 200, 0 ); // green
    QColor colorSemiOk = QColor( 250, 210, 0 ); // yellow
    QColor colorQuarterOk = QColor( 250, 130, 0 ); // orange
    QColor colorNotOk = QColor( 250, 60, 0 );//= QColor( 250, 100, 0 ); // red

    void checkFuncs();

private slots:
    void on_pushButton_funcSignIsOk_clicked();
    void on_pushButton_funcSqrIsOk_clicked();
    void on_pushButton_funcRadIsOk_clicked();
    void on_pushButton_funcGradIsOk_clicked();
    void on_pushButton_funcPriv2PiIsOk_clicked();
    void on_pushButton_funcPrivPiIsOk_clicked();
    void on_pushButton_funcCoordXIsOk_clicked();
    void on_pushButton_funcCoordYIsOk_clicked();
    void on_pushButton_funcDist1to2IsOk_clicked();
    void on_pushButton_funcAngle1to2IsOk_clicked();
    void on_pushButton_funcTimeIsOk_clicked();
    void on_pushButton_funcTrajPartIsOk_clicked();
    void on_pushButton_funcFindPosComplex_clicked();
};
#endif // MAINWINDOW_H
