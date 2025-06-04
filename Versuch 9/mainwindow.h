#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "map.h"
#include "mapio.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

/**
 * @class MainWindow
 * @brief The main application window for interacting with and visualizing the city and street map.
 *
 * The MainWindow class serves as the central GUI interface for the application. It provides
 * tools to create and draw cities and streets, interact with map data, run Dijkstra's algorithm,
 * and test functionality. It displays a QGraphicsScene within a QGraphicsView for visual output.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructs the main application window.
     * @param parent Optional parent widget.
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destructor. Cleans up UI resources.
     */

    ~MainWindow();

private slots:
    /// Simple UI Test
    void on_testSimpleUI_clicked();

     /// A test to draw a simple rectangle on the graphics scene.
    void on_testSimpleDrawing_clicked();

     /// Closes the application.
    void on_actionExit_triggered();

    /// Clears all items from the graphics scene.
    void on_actionClear_Scene_triggered();

     /// Shows an About dialog with program information.
    void on_actionAbout_triggered();

    /// A test to draw two hardcoded cities on the graphics scene.
    void on_testDrawCities_clicked();

    /// A test to draw cities and streets
    void on_testDrawMapWithCities_clicked();

    /// A test to draw a single hardcoded street between two cities.
    void on_testDrawStreets_clicked();

    /// A test to add multiple cities and streets to the map and draws the full map.
    void on_testDrawMapwithStreets_clicked();

    /// Toggles the visibility of UI test buttons.
    void on_hideTestButton_clicked();

    /// Opens a dialog to enter a new city and adds it to the map.
    void on_addCity_clicked();

    /// Fills the map using MapIo and updates the graphics scene and combo boxes.
    void on_fillMap_clicked();

    /// Runs internal tests on the Map class to validate AbstractMap behavior.
    void on_testAbstractMap_clicked();

    /// Runs Dijkstra's algorithm using selected cities and highlights the path.
    void on_testDijkstra_clicked();

    /// Opens a dialog to enter a new street and adds it to the map if valid.
    void on_addStreet_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene scene;
    Map map;
    MapIo* mapIo = nullptr;
    City aachen = City ("Aachen",0,0);
    City koeln = City ("Koeln", 200, 200);
    City duesseldorf = City ("Duesseldorf", 200, -200);
    Street aachenkoeln = Street (&aachen, &koeln);
    Street koelnduesseldorf = Street (&koeln, &duesseldorf);
};
#endif // MAINWINDOW_H
