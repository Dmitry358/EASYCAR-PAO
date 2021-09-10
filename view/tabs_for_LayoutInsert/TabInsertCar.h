#ifndef TABINSERTCAR_H
#define TABINSERTCAR_H

#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QGridLayout>

#include "../../hierarchy/Car.h"


class TabInsertCar: public QWidget {
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

    QCheckBox* conditioner;
    QComboBox* passengerNum;
    QCheckBox* pintleHook;
    QCheckBox* sensors;

    QCheckBox* stWagon;
    QCheckBox* sunroof;
    QCheckBox* luggagerack;

    bool checkTabCarFieldsFilling() const;


public:
    explicit TabInsertCar(QWidget* =nullptr);

    Car* returnVehicleForInsert() const;
    void clearAllFields() const;

    string getMake() const;
    string getModel() const;
    unsigned int getRegistrationYear() const;
    unsigned int getMileage() const;
    double getBasePrice() const;
    unsigned short int getFuelType() const;
    unsigned short int getTansmissionType() const;
    unsigned int getPower() const;
    unsigned int getDisplacement() const;

    bool getConditioner() const;
    unsigned int getPassengerNum() const;
    bool getPintleHook() const;
    bool getSensors() const;

    bool getStWagon() const;
    bool getSunroof() const;
    bool getLuggagerack() const;
};


#endif // TABINSERTCAR_H
