#ifndef VEHICLESEARCHRESULTDIALOG_H
#define VEHICLESEARCHRESULTDIALOG_H

#include <QWidget>
#include <QDialog>

class VehicleSearchResultDialog : public QDialog {

protected:
    VehicleSearchResultDialog(QWidget* _parent=nullptr);

public:
    virtual unsigned int returnVehicleForRemoveIndex() const=0;

    virtual void updateSearchResultDialog() const=0;

    virtual ~VehicleSearchResultDialog();
};

#endif // VEHICLESEARCHRESULTDIALOG_H