#ifndef VIEW_H
#define VIEW_H


#include <vector>
#include <string>
using std::string;
using std::vector;

#include <QObject>
#include <QMetaObject>
#include <QWidget>
#include <QMenu>
#include <QMenuBar>
#include <QTabWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDialog>
#include <QLabel>
#include <QListWidget>
#include <QListWidgetItem>
#include <QString>
#include <utility>
#include <QMessageBox>

#include "view/tabs_for_LayoutSearch/TabSearchMoto.h"
#include "view/tabs_for_LayoutSearch/TabSearchCar.h"
#include "view/tabs_for_LayoutSearch/TabSearchCamper.h"
#include "view/tabs_for_LayoutSearch/TabSearchTruck.h"

#include "view/tabs_for_LayoutInsert/TabInsertMoto.h"
#include "view/tabs_for_LayoutInsert/TabInsertCar.h"
#include "view/tabs_for_LayoutInsert/TabInsertCamper.h"
#include "view/tabs_for_LayoutInsert/TabInsertTruck.h"

#include "view/widget_items/ItemMoto.h"
#include "view/widget_items/ItemCar.h"
#include "view/widget_items/ItemCamper.h"
#include "view/widget_items/ItemTruck.h"

#include "hierarchy/Vehicle.h"
#include "hierarchy/Moto.h"
#include "hierarchy/Auto.h"
#include "hierarchy/Car.h"
#include "hierarchy/Camper.h"
#include "hierarchy/Truck.h"

#include "VehicleSearchResult/VehicleSearchResult.h"

class VehicleSearchResultDialog;
class MotoSearchResultDialog;
class CarSearchResultDialog;
class CamperSearchResultDialog;
class TruckSearchResultDialog;

using std::pair;

class Controller;

class View: public QWidget{

    Q_OBJECT

private:
    Controller* controller;

    QMenu* menuFile;
    QAction* menuInsert;
    QAction* menuSearch;
    QMenu* menuView;
    QAction* menuClear;

    QLabel* labelInsert;
    QTabWidget* tabInsert;
    QPushButton* buttonInsert;

    QLabel* labelSearch;
    QTabWidget* tabSearch;
    QPushButton* buttonSearch;

    VehicleSearchResultDialog* searchResultDialog;

    void addMenuBar(QVBoxLayout* mainLayout);
    void addLayoutInsert(QVBoxLayout* mainLayout) const;
    void addLayoutSearch(QVBoxLayout* mainLayout) const;


public:
    explicit View(QWidget *parent = nullptr);
    void setController(Controller*);
    int tabCurrentIndex() const;

    Vehicle* returnVechicleForInsert() const;
    void showInsertConfirm();

    MotoSearchResult* returnMotoForSearch() const;
    CarSearchResult* returnCarForSearch() const;
    CamperSearchResult* returnCamperForSearch() const;
    TruckSearchResult* returnTruckForSearch() const;


    void showSearchedMotoResultDialog(vector<pair<Moto, unsigned int>>* result);
    void showSearchedCarResultDialog(vector<pair<Car, unsigned int>>* result);
    void showSearchedCamperResultDialog(vector<pair<Camper, unsigned int>>* result);
    void showSearchedTruckResultDialog(vector<pair<Truck, unsigned int>>* result);
    void updateSearchResultDialog() const;

    unsigned int returnVehicleForRemoveIndex() const;
    void removeVehicle() const;
    void showRemoveVehicleConfirm();

    void showWarning(string str);


private slots:
    void showSearchLayout();
    void showInsertLayout();

    void insertNewVehicle() const;

    void searchVehicles() const;
    void showAllMoto() const;
    void showAllCar() const;
    void showAllCamper() const;
    void showAllTruck() const;

    void clearAllFields() const;


public slots:
    void closeSearchResultDialog();

};

#endif // VIEW_H