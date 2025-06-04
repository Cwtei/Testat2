#include "city.h"
#include <QDebug>
#include <QGraphicsTextItem>

City::City(QString name, int x, int y)
    :x(x), y(y), name(name){}

void City::draw (QGraphicsScene& scene)
{
    scene.addEllipse(x, y, 4, 4, QPen(Qt::red), QBrush(Qt::red, Qt::SolidPattern));
    qDebug() << "City drawn:" << name << "at" << x << "," << y;

    QGraphicsTextItem* text = new QGraphicsTextItem;
    text -> setPos(x+4,y+4);
    text -> setPlainText(name);
    scene.addItem(text);
}

QString City::getName()
{
    return name;
}

int City::getX()
{
    return x;
}

int City::getY()
{
    return y;
}
