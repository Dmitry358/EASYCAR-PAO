#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <vector>
#include <QWidget>
#include <QMetaObject>
#include "Container.h"
#include "View.h"
#include "DeepPtr.h"
#include "hierarchy/Vehicle.h"
#include "hierarchy/Moto.h"
#include "hierarchy/Car.h"
#include "hierarchy/Camper.h"
#include "hierarchy/Truck.h"
#include <vector>
#include "hierarchy/Vehicle.h"

#include "view/widget_items/ItemMoto.h"

#include <typeinfo>
#include <utility>

#include "Model.h"

using std::pair;

class Controller: public QObject {

    Q_OBJECT

private:
    View* view;
    Model* model;


public:
    explicit Controller(QObject* parent=nullptr);
    void setView(View* _view);
    void setModel(Model* _model);


public slots:
    void insertNewVehicle() const;

    void searchMoto() const;
    void searchCar() const;
    void searchCamper() const;
    void searchTruck() const;

    void showAllMoto() const;
    void showAllCar() const;
    void showAllCamper() const;
    void showAllTruck() const;

    void removeVehicle() const;
};

#endif // CONTROLLER_H



