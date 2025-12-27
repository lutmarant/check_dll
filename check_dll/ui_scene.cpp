#include "ui_scene.h"

#include <QPainter>

#include <iostream>

using namespace std;

Scene::Scene( QObject * parent ) : QGraphicsScene( parent )
{
    scene_width = 2000;
    scene_height = 2000;
    xStep = 10;
    yStep = 10;

    this->setSceneRect( - scene_width / 2, - scene_height / 2, scene_width, scene_height );
}

Scene::~Scene()
{

}

void Scene::setXY(std::vector<std::pair<double, double> > traj)
{
    this->traj = traj;
}

void Scene::drawBackground(QPainter *painter, const QRectF &rect)
{
    painter->setPen( Qt::lightGray);

    QPoint p1;
    p1.setX( this->sceneRect().left() );
    p1.setY( this->sceneRect().bottom() );

    QPoint p2;
    p2.setX( this->sceneRect().left() );
    p2.setY( this->sceneRect().top() );

    QPoint p3;
    p3.setX( this->sceneRect().right() );
    p3.setY( this->sceneRect().top() );

    QPoint p4;
    p4.setX( this->sceneRect().right() );
    p4.setY( this->sceneRect().bottom() );

    QPoint p5;
    p5.setX( 0 );
    p5.setY( this->sceneRect().bottom() );

    QPoint p6;
    p6.setX( 0 );
    p6.setY( this->sceneRect().top() );

    QPoint p7;
    p7.setX( this->sceneRect().left() );
    p7.setY( 0 );

    QPoint p8;
    p8.setX( this->sceneRect().right() );
    p8.setY( 0 );

    QPen pen;
    pen.setColor( Qt::lightGray );
    pen.setWidth( baseWidth * scaleValue );
    painter->setPen( pen );

    for ( double x = this->sceneRect().left(); x <= this->sceneRect().right(); x += xStep )
    {
        QPoint start;
        start.setX( x );
        start.setY( this->sceneRect().bottom() );

        QPoint end;
        end.setX( x );
        end.setY( this->sceneRect().top() );

        painter->drawLine(start,end);
    }

    for (double y = this->sceneRect().top(); y <= this->sceneRect().bottom(); y += yStep )
    {
        QPoint start;
        start.setX( this->sceneRect().left() );
        start.setY( y );

        QPoint end;
        end.setX( this->sceneRect().right() );
        end.setY( y );

        painter->drawLine(start,end);
    }

    //    scene->setDistDet( checkerTrajClassifier.getDistDet() );

    {
        QPen penOsi;
        penOsi.setColor( Qt::black );
        penOsi.setWidth( ( baseWidth ) * scaleValue );
        painter->setPen( penOsi );

        QPoint start;
        start.setX( 0 );
        start.setY( this->sceneRect().bottom() );

        QPoint end;
        end.setX( 0 );
        end.setY( this->sceneRect().top() );

        painter->drawLine(start,end);

        start.setX( this->sceneRect().left() );
        start.setY( 0 );

        end.setX( this->sceneRect().right() );
        end.setY( 0 );

        painter->drawLine(start,end);
    }

    QPen penBlue;
    penBlue.setColor( Qt::blue );
    penBlue.setWidth( ( baseWidth + 1 ) * scaleValue );
    painter->setPen( penBlue );
    for ( unsigned int i = 1; i < traj.size(); ++i )
    {
        std::pair < double, double > p1 = traj[ i - 1 ];
        std::pair < double, double > p2 = traj[ i ];

        QPoint start;
        start.setX(   p1.first );
        start.setY( - p1.second );

        QPoint end;
        end.setX(   p2.first );
        end.setY( - p2.second );

        painter->drawLine( start,end );
    }



    Q_UNUSED(rect);
}

void Scene::recieveScaleValue(double value)
{
    scaleValue = value;
    this->update();
}
