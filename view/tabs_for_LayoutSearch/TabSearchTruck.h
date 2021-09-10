#ifndef TABSEARCHTRUCK_H
#define TABSEARCHTRUCK_H

#include <QLineEdit>
#include <QTextEdit>
#include <QComboBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QGridLayout>
#include <QLabel>
#include <string>

#include "../../hierarchy/Truck.h"
#include "../../VehicleSearchResult/TruckSearchResult.h"

using std::string;

class TabSearchTruck: public QWidget{
private:
    QLineEdit* make;
    QLineEdit* model;
    QComboBox* registrationYearFrom;
    QComboBox* registrationYearTo;
    QComboBox* mileage;
    QComboBox* priceType;
    QCheckBox* warranty;
    QLineEdit* fullPriceFrom;
    QLineEdit* fullPriceTo;
    QComboBox* fuelType;
    QComboBox* transmissionType;

    QLineEdit* maxLoadabilityFrom;
    QLineEdit* maxLoadabilityTo;
    QCheckBox* sleepingPlace;
    QCheckBox* dangerousGood;    

    QComboBox* emissionClass;
    QLineEdit* vehicleTaxFrom;
    QLineEdit* vehicleTaxTo;

    bool checkTabTruckFieldsFilling() const;
    bool getMaxLoadabilityFilling() const;

    string getMake() const;
    string getModel() const;
    unsigned int getRegistrationYearFrom() const;
    unsigned int getRegistrationYearTo() const;
    unsigned int getMileageFrom() const;
    unsigned int getMileageTo() const;
    bool getPriceType() const;
    bool getWarranty() const;
    double getFullPriceFrom() const;
    double getFullPriceTo() const;
    unsigned short int getFuelType() const;
    unsigned short int getTansmissionType() const;

    unsigned int getMaxLoadabilityFrom() const;
    unsigned int getMaxLoadabilityTo() const;
    bool getSleepingPlace() const;
    bool getDangerousGood() const;

    unsigned short int getEmissionClass() const;
    unsigned int getVehicleTaxFrom() const;
    unsigned int getVehicleTaxTo() const;


public:
    explicit TabSearchTruck(QWidget* =nullptr);

    TruckSearchResult* getTruckSearchValues() const;

    void clearAllFields() const;
};

#endif // TABSEARCHTRUCK_H
