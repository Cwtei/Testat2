#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "city.h"
#include "dialog.h"
#include "mapionrw.h"
#include "dijkstra.h"
#include "dialogstreet.h"
#include <street.h>
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include <QRandomGenerator>
#include <QGraphicsScene>
#include <QComboBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mapIo = new MapIoNrw();
    ui->graphicsView->setScene(&scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_testSimpleUI_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Taste gedrueckt!");
    qDebug() << "Taste gedrueckt!";

    QString str = ui->lineEdit_teste_was->text();

    bool ok;
    int number =  str.toInt(&ok);

    if (ok)
    {
        msgBox.setInformativeText("Nummer + 4 =" + QString::number(number + 4));
        qDebug() << "Number+4 = " << number + 4;
    }
    else
    {
        msgBox.setInformativeText(QString("Input: %1").arg(str));
        qDebug().noquote() << QString("Input: %1").arg(str);
    }
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.exec();
}

void MainWindow::on_testSimpleDrawing_clicked()
{
    scene.addRect(QRandomGenerator::global()->bounded(1000),
                  QRandomGenerator::global()->bounded(1000),
                  300, 300,
                  QPen(Qt::black),
                  QBrush(Qt::darkGreen, Qt::SolidPattern));
}


void MainWindow::on_actionExit_triggered()
{
    close();
}


void MainWindow::on_actionClear_Scene_triggered()
{
    scene.clear();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, "Über das Programm","Versuch 09");
}


void MainWindow::on_testDrawCities_clicked()
{
    aachen.draw(scene);
    koeln.draw(scene);
    duesseldorf.draw(scene);
}


void MainWindow::on_testDrawMapWithCities_clicked()
{
    map.addCity(&aachen);
    map.addCity(&koeln);
    map.addCity(&duesseldorf);

    map.draw(scene);

    map = Map();
}


void MainWindow::on_testDrawStreets_clicked()
{
    aachenkoeln.draw(scene);
    koelnduesseldorf.draw(scene);
}


void MainWindow::on_testDrawMapwithStreets_clicked()
{
    map.addCity(&aachen);
    map.addCity(&koeln);
    map.addCity(&duesseldorf);

    map.addStreet(&aachenkoeln);
    map.addStreet(&koelnduesseldorf);

    map.draw(scene);

    map = Map();
}


void MainWindow::on_hideTestButton_clicked()
{
    if (!ui->hideTestButton->isChecked())
    {
        ui->testDrawCities->show();
        ui->testDrawMapWithCities->show();
        ui->testDrawMapwithStreets->show();
        ui->testDrawStreets->show();
        ui->testSimpleDrawing->show();
        ui->testSimpleUI->show();
    }
    else
    {
        ui->testDrawCities->hide();
        ui->testDrawMapWithCities->hide();
        ui->testDrawMapwithStreets->hide();
        ui->testDrawStreets->hide();
        ui->testSimpleDrawing->hide();
        ui->testSimpleUI->hide();
    }
}


void MainWindow::on_addCity_clicked()
{
    Dialog dialog1 (this);
    int result = dialog1.exec();
    qDebug() << "Dialog result: " << result;

    if (result == 1)
    {
        City* city = dialog1.getCity();
        map.addCity(city);
        map.draw(scene);

        QString cityName = city->getName();
        if (ui->startCity->findText(cityName) == -1)
        {
            ui->startCity->addItem(cityName);
            ui->targetCity->addItem(cityName);
        }
    }
}


void MainWindow::on_fillMap_clicked()
{
    mapIo->fillMap(map);
    map.draw(scene);

    for (City* c : map.getCitiesList())
    {
        QString cityName = c->getName();
        if (ui->startCity->findText(cityName) == -1)
        {
            ui->startCity->addItem(cityName);
            ui->targetCity->addItem(cityName);
        }
    }
}


void MainWindow::on_testAbstractMap_clicked()
{
    Map testMap;
    City *a = new City("a", 0, 0);
    City *b = new City("b", 0, 100);
    City *c = new City("c", 100, 300);
    Street *s = new Street(a, b);
    Street *s2 = new Street(b, c);


    qDebug() << "MapTest: Start Test of the Map";
    {
        qDebug() << "MapTest: adding wrong street";
        bool t1 = testMap.addStreet(s);
        if (t1) {
            qDebug() << "-Error: Street should not bee added, if cities have not been added.";
        }
    }

    {
        qDebug() << "MapTest: adding correct street";
        testMap.addCity(a);
        testMap.addCity(b);
        bool t1 = testMap.addStreet(s);
        if (!t1) {
            qDebug() << "-Error: It should be possible to add this street.";
        }
    }

    {
        qDebug() << "MapTest: findCity";
        City* city = testMap.findCity("a");
        if (city != a)
            qDebug() << "-Error: City a could not be found.";

        city = testMap.findCity("b");
        if (city != b)
            qDebug() << "-Error: City b could not be found.";

        city = testMap.findCity("c");
        if (city != nullptr)
            qDebug() << "-Error: If city could not be found 0 should be returned.";
    }

    testMap.addCity(c);
    testMap.addStreet(s2);

    {
        qDebug() << "MapTest: getOppositeCity";
        const City *city = testMap.getOppositeCity(s, a);
        if (city != b)
            qDebug() << "-Error: Opposite city should be b.";

        city = map.getOppositeCity(s, c);
        if (city != nullptr)
            qDebug() << "-Error: Opposite city for a city which is not linked by given street should be 0.";
    }

    {
        qDebug() << "MapTest: streetLength";
        double l = testMap.getLength(s2);
        double expectedLength = 223.6;
        // compare doubles with 5% tolerance
        if (l < expectedLength * 0.95 || l > expectedLength *1.05)
            qDebug() << "-Error: Street Length is not equal to the expected.";

    }

    {
        qDebug() << "MapTest: getStreetList";
        QVector<Street*> streetList1 = testMap.getStreetList(a);
        QVector<Street*> streetList2 = testMap.getStreetList(b);
        if (streetList1.size() != 1) {
            qDebug() << "-Error: One street should be found for city a.";
        }
        else if (*streetList1.begin() != s) {
            qDebug() << "-Error: The wrong street has been found for city a.";
        }

        if (streetList2.size() != 2)
            qDebug() << "-Error: Two streets should be found for city b.";
    }

    qDebug() << "MapTest: End Test of the Map.";
}

void MainWindow::on_testDijkstra_clicked()
{
    /*
    // Create cities
    City* a = new City("A", 0, 0);
    City* b = new City("B", 100, 0);
    City* c = new City("C", 50, 50);
    City* d = new City("D", 150, 50);
    City* e = new City("E", 200, 0);

    // Add cities to the map
    map.addCity(a);
    map.addCity(b);
    map.addCity(c);
    map.addCity(d);
    map.addCity(e);

    // Create connecting streets
    Street* ab = new Street(a, b);
    Street* ac = new Street(a, c);
    Street* bc = new Street(b, c);
    Street* cd = new Street(c, d);
    Street* de = new Street(d, e);
    Street* be = new Street(b, e);  // Shorter alternative path

    // Add streets to the map
    map.addStreet(ab);
    map.addStreet(ac);
    map.addStreet(bc);
    map.addStreet(cd);
    map.addStreet(de);
    map.addStreet(be);


    // Draw the whole map
    map.draw(scene);
    */

    // Run Dijkstra from A to E

    QString start = ui->startCity->currentText();
    QString target = ui->targetCity->currentText();
    QVector<Street*> path = Dijkstra::search(map, start, target);

    if (path.isEmpty())
    {
        qDebug() << "No path found from" << start << "to" << target;
    }
    else
    {
        qDebug() << "Path from" << start << "to" << target << ":";
        City* previousEnd = nullptr;

        for (auto it = path.begin(); it != path.end(); it++)
        {
            Street* current = *it;

            if (it == path.begin())
            {
                if (current->getcity1()->getName() != start)
                {
                    current->swapCity();
                }
                previousEnd = current->getcity2();
            }
            else
            {
                if(current->getcity1() != previousEnd)
                {
                    current->swapCity();
                }
                previousEnd = current->getcity2();
            }
            qDebug() << current->getcity1()->getName() << "->" << current->getcity2()->getName();
            current->drawRed(scene);
        }
    }
}


void MainWindow::on_addStreet_clicked()
{
    DialogStreet dialog2 (this);
    int result = dialog2.exec();
    qDebug() << "Dialog result: " << result;

    if (result == 1)
    {
        Street* street = dialog2.getStreet(map);
        if (street != nullptr)
        {
            map.addStreet(street);
            map.draw(scene);
        }
    }
}

