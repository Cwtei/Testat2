#ifndef CITY_H
#define CITY_H

#include <QString>
#include <QGraphicsScene>

/**
 * @class City
 * @brief Represents a city with a name and coordinates.
 *
 * This class stores the name and position (x, y) of a city and can render itself in a QGraphicsScene.
 */
class City
{
public:
    /**
     * @brief Constructor to initialize a city.
     * @param name The name of the city.
     * @param x X-coordinate of the city.
     * @param y Y-coordinate of the city.
     */
    City(QString name, int x, int y);

    /**
     * @brief Draws the city in the given graphics scene.
     * @param scene Reference to a QGraphicsScene where the city is drawn.
     */
    void draw(QGraphicsScene& scene);

    /**
     * @brief Returns the name of the city.
     * @return Name of the city.
     */
    QString getName();

    /**
     * @brief Returns the X coordinate of the city.
     * @return X coordinate.
     */
    int getX();

    /**
     * @brief Returns the Y coordinate of the city.
     * @return Y coordinate.
     */
    int getY();

private:
    int x, y;           ///< X and Y coordinates of the city.
    QString name;       ///< Name of the city.
};


#endif // CITY_H
