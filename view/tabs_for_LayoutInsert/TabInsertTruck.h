#ifndef TABINSERTTRUCK_H
#define TABINSERTTRUCK_H

#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QGridLayout>

#include <string>

#include "../../hierarchy/Truck.h"

using std::string;

class TabInsertTruck: public QWidget {

private:
    QLineEdit* make;
    QLineEdit* model;
    QComboBox* registrationYear;
    QLineEdit* mileage;
    QLineEdit* basePrice;
    QComboBox* fuelType;
    QComboBox* transmissionType;
    QLineEdit* power;
    QLineEdit* displacement;

    QLineEdit* maxLoadability;
    QCheckBox* sleepingPlace;
    QCheckBox* dangerousGood;

    bool checkTabTruckFieldsFilling() const;


public:
    explicit TabInsertTruck(QWidget* =nullptr);

    Truck* returnVehicleForInsert() const;


    string getMake() const;
    string getModel() const;
    unsigned int getRegistrationYear() const;
    unsigned int getMileage() const;
    double getBasePrice() const;
    unsigned short int getFuelType() const;
    unsigned short int getTansmissionType() const;
    unsigned int getPower() const;
    unsigned int getDisplacement() const;

    unsigned int getMaxLoadability() const;
    bool getSleepingPlace() const;
    bool getDangerousGood() const;
    void clearAllFields() const;
};

#endif // TABINSERTTRUCK_H
