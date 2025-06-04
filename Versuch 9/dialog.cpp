#include "dialog.h"
#include "ui_dialog.h"

#include <QDebug>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


City* Dialog::getCity()
{
    int newxcoordinate = ui->newXCoordinate->text().toInt();
    int newycoordinate = ui->newYCoordinate->text().toInt();
    City* city = new City(ui->newCityName->text(), newxcoordinate, newycoordinate);

    qDebug() << "New City added: " << city->getName();
    qDebug() << "Coordinate: " << city->getX() << "," << city->getY();

    return city;
}
