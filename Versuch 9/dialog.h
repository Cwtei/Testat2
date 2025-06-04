#ifndef DIALOG_H
#define DIALOG_H

#include "city.h"

#include <QDialog>
#include <QString>

namespace Ui {
class Dialog;
}

/**
 * @class Dialog
 * @brief A dialog window for inputting a new city and its coordinates.
 *
 * This class provides a user interface to enter a city's name and coordinates,
 * and returns a new City object created from the input.
 */
class Dialog : public QDialog
{
    Q_OBJECT

public:

    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

    /**
     * @brief Creates a new City object based on user input.
     * @return Pointer to the newly created City object.
     */
    City* getCity();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
