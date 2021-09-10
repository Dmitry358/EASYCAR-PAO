#ifndef TRUCKSEARCHRESULTDIALOG_H
#define TRUCKSEARCHRESULTDIALOG_H


#include <QListWidget>
#include <QPushButton>

#include <vector>
#include <utility>

#include "../../hierarchy/Truck.h"
#include "../widget_items/ItemTruck.h"
#include "VehicleSearchResultDialog.h"

#include "../../View.h"

using std::pair;
using std::vector;


class TruckSearchResultDialog : public VehicleSearchResultDialog {

    Q_OBJECT

private:
    View* view;
    QListWidget* searchList;
    vector<pair<Truck, unsigned int>>* result;
    QPushButton* buttonClose;
    QPushButton* buttonDelete;



public:
    TruckSearchResultDialog(vector<pair<Truck, unsigned int>>* _result, View* _view, QWidget* _parent=nullptr);

    unsigned int returnVehicleForRemoveIndex() const;

    void updateSearchResultDialog() const;


public slots:
    void removeVehicle() const;

    void removeDialog() const;
};

#endif // TRUCKSEARCHRESULTDIALOG_H