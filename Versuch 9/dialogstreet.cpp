#include "dialogstreet.h"
#include "ui_dialogstreet.h"

#include<QDebug>


DialogStreet::DialogStreet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogStreet)
{
    ui->setupUi(this);
}

DialogStreet::~DialogStreet()
{
    delete ui;
}

Street* DialogStreet::getStreet(Map& map)
{

    QString city1Name = ui->city1->text();
    QString city2Name = ui->city2->text();
    City* city1 = map.findCity(city1Name);
    City* city2 = map.findCity(city2Name);

    if (city1 == city2 || city1 == nullptr || city2 == nullptr)
    {
        qDebug() << "City not found / Same city is entered twice.";
        return nullptr;
    }

    Street* street = new Street(city1, city2);
    qDebug() << "New Street added between" << city1->getName() << "and" << city2->getName();

    return street;
}
