#ifndef STREET_H
#define STREET_H

#include "city.h"

/**
 * @class Street
 * @brief Represents a street connecting two cities.
 *
 * The class provides methods to draw a street (line) between two City objects.
 */
class Street
{
public:
    /**
     * @brief Constructor that initializes the street with two cities.
     * @param city1 Pointer to the first city.
     * @param city2 Pointer to the second city.
     */
    Street(City* city1, City* city2);

    /**
     * @brief Draws the street as a red line in the given graphics scene.
     * @param scene Reference to a QGraphicsScene.
     */
    void draw(QGraphicsScene& scene);

    /**
     * @brief Returns the pointer to the first city.
     * @return Pointer to city1.
     */
    City* getcity1() const;

    /**
     * @brief Returns the pointer to the second city.
     * @return Pointer to city2.
     */
    City* getcity2() const;

    /**
     * @brief Draws the street in red with increased thickness.
     * @param scene Reference to a QGraphicsScene.
     */
    void drawRed(QGraphicsScene& scene);

    /**
     * @brief Swaps the two cities.
     */
    void swapCity();


private:
    City* city1; ///< Pointer to the first city.
    City* city2; ///< Pointer to the second city.
};

#endif // STREET_H
