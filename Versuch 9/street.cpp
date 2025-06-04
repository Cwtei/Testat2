#include "street.h"
#include <QGraphicsScene>
#include <utility>

Street::Street(City* city1, City* city2): city1(city1), city2(city2) {}

void Street::draw(QGraphicsScene& scene)
{
    int xcoordinateCity1 = city1->getX();
    int ycoordinateCity1 = city1->getY();
    int xcoordinateCity2 = city2->getX();
    int ycoordinateCity2 = city2->getY();

    scene.addLine (xcoordinateCity1,ycoordinateCity1,
                  xcoordinateCity2,ycoordinateCity2,
                  QPen(Qt::red));
}

City* Street::getcity1() const
{
    return city1;
}

City* Street::getcity2() const
{
    return city2;
}

void Street::drawRed(QGraphicsScene& scene)
{
    scene.addLine(
        city1->getX(), city1->getY(),
        city2->getX(), city2->getY(),
        QPen(Qt::red, 4) // red color, thickness 4
        );
}

void Street::swapCity()
{
    std::swap(city1, city2);
}
