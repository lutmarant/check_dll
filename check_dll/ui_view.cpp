#include "ui_view.h"

#include "myMath.h"
#include "importedMath.h"

#include <QMouseEvent> // QMouseEvent * event

View::View(QWidget *parent)
    : QGraphicsView(parent)
{
    scene = new Scene();
    this->setScene( scene );

    QPointF p1 = mapToScene( 0, 0 );
    QPointF p2 = mapToScene( 5, 0 );
    delta1 = p2.x() - p1.x();

    connect( this, &View::sendScaleValue, scene, &Scene::recieveScaleValue );
}

View::~View()
{

}

void View::setXY(std::vector<std::pair<double, double> > traj)
{
    scene->setXY( traj );
    scene->update();
}

//void View::mouseDoubleClickEvent(QMouseEvent * event)
//{
//    if ( event->button() == Qt::LeftButton )
//    {
//        PointWSPF * point = new PointWSPF();
//        point->setPos( mapToScene( event->x(), event->y() ) ); // QGraphicsItem for setPos

//        addPointToScene( point );
//    }
//}

void View::mousePressEvent(QMouseEvent * event)
{
    QGraphicsView::mousePressEvent (event);
    if ( event->button() == Qt::LeftButton ) // Qt::MiddleButton // && event->modifiers ().testFlag (Qt::ControlModifier)
    {
        setDragMode (QGraphicsView::ScrollHandDrag);
        setInteractive (false);

        setTransformationAnchor( QGraphicsView::NoAnchor );

        x_init = event->x ();
        y_init = event->y ();
    }
}

void View::mouseMoveEvent(QMouseEvent * event)
{
    if ( event->buttons () & Qt::LeftButton ) // Qt::MiddleButton // && event->modifiers ().testFlag (Qt::ControlModifier)
    {
        QPointF oldp = mapToScene ( x_init, y_init);
        QPointF newp = mapToScene ( event->pos() );
        QPointF translation = newp - oldp;

        translate(translation.x (), translation.y ());

        x_init = event->x ();
        y_init = event->y ();
    }

    QGraphicsView::mouseMoveEvent (event);
}

void View::mouseReleaseEvent(QMouseEvent * event)
{
    if ( event->button () == Qt::LeftButton ) // Qt::MiddleButton // && event->modifiers ().testFlag (Qt::ControlModifier)
    {
        setDragMode (QGraphicsView::NoDrag);
        setInteractive (true);
    }
}

void View::wheelEvent( QWheelEvent * event )
{
    setTransformationAnchor( QGraphicsView::AnchorUnderMouse );
    double scaleFactor = 1.15;
    if( event->delta() > 0 ) {
        // Zoom in
        scale( scaleFactor, scaleFactor );

    } else {
        // Zoom out
        scale( 1.0 / scaleFactor, 1.0 / scaleFactor );
    }

    QPointF p1 = mapToScene( 0, 0 );
    QPointF p2 = mapToScene( 5, 0 );
    double delta2 = p2.x() - p1.x();

    double scaleValue = delta2 / delta1 ;

    emit sendScaleValue( scaleValue );
}
