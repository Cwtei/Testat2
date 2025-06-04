#include "map.h"
#include <QDebug>
#include <cmath>

Map::Map() {}

void Map::addCity(City* city)
{
    cities.append(city);
    qDebug().noquote() << city->getName() << "added";
}

void Map::draw(QGraphicsScene& scene)
{
    for (auto it = cities.begin(); it != cities.end(); it++)
    {
        (*it)->draw(scene);
    }
    for (auto it = streets.begin(); it != streets.end(); it++)
    {
        (*it)->draw(scene);
    }
}

bool Map::addStreet(Street* street)
{
    bool city1Found = false;
    bool city2Found = false;

    for (auto it = cities.begin(); it != cities.end(); it++)
    {
        if (street->getcity1() == *it )
        {
            city1Found = true;
        }
        if (street->getcity2() == *it )
        {
            city2Found = true;
        }
    }

    if (city1Found && city2Found)
    {
        streets.append(street);
        return true;
    }
    else
    {
        return false;
    }
}

City* Map::findCity(const QString cityName)const
{
    for (auto it = cities.begin(); it != cities.end(); it++)
    {
        if (cityName == (*it)->getName())
        {
            return *it;
        }
    }

    return nullptr;
}

QVector<Street*> Map::getStreetList(const City* city) const
{
    QVector<Street*> relatedStreet;

    for (auto it = streets.begin(); it != streets.end(); it++)
    {
        if ((*it)-> getcity1() == city || (*it) ->getcity2() == city)
        {
            relatedStreet.append(*it);
        }
    }
    return relatedStreet; //if there nothing found .isEmpty will be true
}

City* Map::getOppositeCity(const Street* street, const City* city) const
{
    if (street -> getcity1() == city)
    {
        return street -> getcity2();
    }
    else if (street -> getcity2() == city)
    {
        return street -> getcity1();
    }
    else
    {
        return nullptr;
    }
}

double Map::getLength(const Street* street) const
{
    int x = street->getcity1()->getX()-street->getcity2()->getX();
    int y = street->getcity1()->getY()-street->getcity2()->getY();
    double result = sqrt(x*x + y*y);
    return result;
}

QVector <City*> Map::getCitiesList()
{
    return cities;
}
