#ifndef CARSEARCHRESULTDIALOG_H
#define CARSEARCHRESULTDIALOG_H


#include <QListWidget>
#include <QPushButton>
#include <vector>
#include <utility>

#include "../../hierarchy/Car.h"
#include "../widget_items/ItemCar.h"
#include "VehicleSearchResultDialog.h"

#include "../../View.h"


using std::pair;
using std::vector;


class CarSearchResultDialog : public VehicleSearchResultDialog {

    Q_OBJECT

private:
    View* view;
    QListWidget* searchList;
    vector<pair<Car, unsigned int>>* result;
    QPushButton* buttonClose;
    QPushButton* buttonDelete;


public:
    CarSearchResultDialog(vector<pair<Car, unsigned int>>* _result, View* _view, QWidget* _parent=nullptr);

    unsigned int returnVehicleForRemoveIndex() const;

    void updateSearchResultDialog() const;


public slots:
    void removeVehicle() const;

    void removeDialog() const;
};

#endif // CARSEARCHRESULTDIALOG_H