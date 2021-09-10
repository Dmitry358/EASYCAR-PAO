#ifndef TABINSERTCAMPER_H
#define TABINSERTCAMPER_H

#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QGridLayout>

#include "../../hierarchy/Camper.h"


class TabInsertCamper: public QWidget {
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

    QComboBox* sleepingPlaces;
    QCheckBox* toilet;
    QCheckBox* kitchen;

    bool checkTabCamperFieldsFilling() const;


public:

    explicit TabInsertCamper(QWidget* =nullptr);

    Camper* returnVehicleForInsert() const;

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

    unsigned int getSleepingPlaces() const;
    bool getToilet() const;
    bool getKitchen() const;
    void clearAllFields() const;
};

#endif // TABINSERTCAMPER_H
