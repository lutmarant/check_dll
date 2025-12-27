#ifndef WSPF_VIEW_H
#define WSPF_VIEW_H

#include <QGraphicsView>

#include "ui_scene.h"

class View : public QGraphicsView
{
    Q_OBJECT

    Scene * scene;

    int x_init;
    int y_init;
    double delta1;

    //---------------------------------------

    QColor colorFullOk = QColor( 0, 200, 0 );
    QColor colorSemiOk = QColor( 250, 190, 0 );
    QColor colorNotOk = QColor( 250, 100, 0 );


public:

    explicit View(QWidget *parent = nullptr);
    ~View();

    void setXY( std::vector < std::pair < double, double > > traj );

    // QWidget interface
protected:
//    void mouseDoubleClickEvent(QMouseEvent * event);
    void mousePressEvent (QMouseEvent *event);
    void mouseMoveEvent (QMouseEvent *event);
    void mouseReleaseEvent (QMouseEvent *event);
    void wheelEvent(QWheelEvent * event);

signals:
    void sendScaleValue( double value );

public slots:


};

#endif // WSPF_VIEW_H
