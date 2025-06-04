#ifndef MAP_H
#define MAP_H

#include "abstractmap.h"
#include "city.h"
#include "street.h"
#include <QVector>
#include <QGraphicsScene>

/**
 * @class Map
 * @brief A concrete implementation of AbstractMap for managing and visualizing a set of cities and streets.
 *
 * The Map class maintains a collection of City and Street objects. It provides functionality
 * for adding cities and streets, drawing the map, and querying for connectivity and geometry.
 */
class Map : public AbstractMap
{
public:
    /**
     * @brief Constructor for Map.
     */
    Map();

    void addCity(City* city) override;

    /**
     * @brief Draws all cities and streets in the given graphics scene.
     * @param scene Reference to the QGraphicsScene for rendering.
     */
    void draw(QGraphicsScene& scene);

    bool addStreet(Street* street) override;

    City* findCity(const QString cityName)const override;

    QVector<Street*> getStreetList(const City* city) const override;

    City* getOppositeCity(const Street* street, const City* city) const override;

    double getLength(const Street* street) const override;

    /**
     * @brief Returns the list of all cities currently stored in the map.
     * @return A QVector of pointers to City objects.
     */
    QVector <City*> getCitiesList();


private:
    QVector <City*> cities; ///< List of all cities in the map.
    QVector <Street*> streets; ///< List of all streets in the map.
};

#endif // MAP_H
