#ifndef MOTOSEARCHRESULTDIALOG_H
#define MOTOSEARCHRESULTDIALOG_H


#include <QListWidget>
#include <QPushButton>
#include <vector>
#include <utility>

#include "../../hierarchy/Moto.h"
#include "../widget_items/ItemMoto.h"
#include "VehicleSearchResultDialog.h"

#include "../../View.h"

using std::pair;
using std::vector;


class MotoSearchResultDialog : public VehicleSearchResultDialog {

    Q_OBJECT

private:
    View* view;
    QListWidget* searchList;
    vector<pair<Moto, unsigned int>>* result;
    QPushButton* buttonClose;
    QPushButton* buttonDelete;


public:
    MotoSearchResultDialog(vector<pair<Moto, unsigned int>>* _result, View* _view, QWidget* _parent=nullptr);

    unsigned int returnVehicleForRemoveIndex() const;

    void updateSearchResultDialog() const;


public slots:
    void removeVehicle() const;

    void removeDialog() const;
};

#endif // MOTOSEARCHRESULTDIALOG_H