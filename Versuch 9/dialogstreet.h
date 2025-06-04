#ifndef DIALOGSTREET_H
#define DIALOGSTREET_H

#include <QDialog>
#include "map.h"
#include "street.h"

namespace Ui {
class DialogStreet;
}

/**
 * @class DialogStreet
 * @brief A dialog window for creating a new Street between two cities.
 *
 * This dialog allows the user to input two city names. If both cities exist and are distinct,
 * a new Street object connecting them is created and returned.
 */
class DialogStreet : public QDialog
{
    Q_OBJECT

public:
    explicit DialogStreet(QWidget *parent = nullptr);
    ~DialogStreet();

    /**
     * @brief Creates a new Street object based on the city names entered in the dialog.
     * @param map Reference to the Map used to resolve city names.
     * @return Pointer to the new Street, or nullptr if the cities are not found or are the same.
     */
    Street* getStreet(Map& map);

private:
    Ui::DialogStreet *ui;
};

#endif // DIALOGSTREET_H
