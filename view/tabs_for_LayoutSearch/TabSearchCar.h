#ifndef SEARCHCARTAB_H
#define SEARCHCARTAB_H

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

#include "../../hierarchy/Car.h"
#include "../../VehicleSearchResult/CarSearchResult.h"

using std::string;


class TabSearchCar: public QWidget{
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

    QCheckBox* conditioner;
    QComboBox* passengerNum;
    QCheckBox* pintleHook;
    QCheckBox* sensors;

    QCheckBox* stWagon;
    QCheckBox* sunroof;
    QCheckBox* luggagerack;

    QCheckBox* isNoviceDriver;
    QComboBox* emissionClass;
    QLineEdit* vehicleTaxFrom;
    QLineEdit* vehicleTaxTo;


    bool checkTabCarFieldsFilling() const;

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

    bool getConditioner() const;
    unsigned short int getPassengerNum() const;
    bool getPintleHook() const;
    bool getSensors() const;

    bool getStWagon() const;
    bool getSunroof() const;
    bool getLuggagerack() const;

    bool getIsNoviceDriver() const;
    unsigned short int getEmissionClass() const;
    unsigned int getVehicleTaxFrom() const;
    unsigned int getVehicleTaxTo() const;


public:
    explicit TabSearchCar(QWidget* =nullptr);

    CarSearchResult* getCarSearchValues() const;

    void clearAllFields() const;
};


#endif // SEARCHCARTAB_H
