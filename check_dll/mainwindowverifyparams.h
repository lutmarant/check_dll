#ifndef MAINWINDOWVERIFYPARAMS_H
#define MAINWINDOWVERIFYPARAMS_H

#include <QMainWindow>

namespace Ui {
class MainWindowVerifyParams;
}

class MainWindowVerifyParams : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowVerifyParams(QWidget *parent = nullptr);
    ~MainWindowVerifyParams();

private:
    Ui::MainWindowVerifyParams *ui;
};

#endif // MAINWINDOWVERIFYPARAMS_H
