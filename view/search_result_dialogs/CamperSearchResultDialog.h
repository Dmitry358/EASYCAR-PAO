#ifndef CAMPERSEARCHRESULTDIALOG_H
#define CAMPERSEARCHRESULTDIALOG_H

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




class CamperSearchResultDialog : public VehicleSearchResultDialog {

    Q_OBJECT

private:
    View* view;
    QListWidget* searchList;
    vector<pair<Camper, unsigned int>>* result;
    QPushButton* buttonClose;
    QPushButton* buttonDelete;


public:
    CamperSearchResultDialog(vector<pair<Camper, unsigned int>>* _result, View* _view, QWidget* _parent=nullptr);

    unsigned int returnVehicleForRemoveIndex() const;

    void updateSearchResultDialog() const;


public slots:
    void removeVehicle() const;

    void removeDialog() const;
};

#endif // CAMPERSEARCHRESULTDIALOG_H