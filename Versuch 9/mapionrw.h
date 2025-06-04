///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 9
//////////////////////////////////////////////////////////////////////////////

#ifndef MAPIONRW_H
#define MAPIONRW_H

#include "mapio.h"

/// This class provides a simple hardcoded Map.
class MapIoNrw : public MapIo
{
public:
    MapIoNrw();
    virtual ~MapIoNrw();

    /**
     * @brief Populates the map with predefined cities and streets representing a simplified NRW region.
     * @param map Reference to the AbstractMap to be filled.
     */
    virtual void fillMap(AbstractMap &map);
};

#endif // MAPIONRW_H
