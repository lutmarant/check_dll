#ifndef WSPF_SCENE_H
#define WSPF_SCENE_H

#include <QGraphicsScene>

#include <vector>

class Scene : public QGraphicsScene
{
    Q_OBJECT

public:

    explicit Scene( QObject * parent = nullptr );
    ~Scene();

    void setXY( std::vector < std::pair < double, double > > traj );

private:
    qreal scene_width = 30000;
    qreal scene_height = 30000;
    double xStep = 1000;
    double yStep = 1000;
    double baseWidth = 1;
    double scaleValue = 1;

    std::vector < std::pair < double, double > > traj;

    void drawBackground(QPainter *painter, const QRectF &rect);

public slots:
    void recieveScaleValue( double value );
};

#endif // WSPF_SCENE_H
