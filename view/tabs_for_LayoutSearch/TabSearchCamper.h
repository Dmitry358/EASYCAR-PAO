#ifndef TABSEARCHCAMPER_H
#define TABSEARCHCAMPER_H

#include <QLineEdit>
#include <QTextEdit>
#include <QComboBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QGridLayout>
#include <QLabel>

#include "../../hierarchy/Camper.h"
#include "../../VehicleSearchResult/CamperSearchResult.h"

class TabSearchCamper: public QWidget{
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

    QComboBox* sleepingPlaces;
    QCheckBox* toilet;
    QCheckBox* kitchen;

    QCheckBox* isNoviceDriver;
    QComboBox* emissionClass;
    QLineEdit* vehicleTaxFrom;
    QLineEdit* vehicleTaxTo;


    bool checkTabCamperFieldsFilling() const;

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

    unsigned short int getSleepingPlaces() const;
    bool getToilet() const;
    bool getKitchen() const;

    bool getIsNoviceDriver() const;
    unsigned short int getEmissionClass() const;
    unsigned int getVehicleTaxFrom() const;
    unsigned int getVehicleTaxTo() const;


public:
    explicit TabSearchCamper(QWidget* =nullptr);

    CamperSearchResult* getCamperSearchValues() const;

    void clearAllFields() const;
};

#endif // TABSEARCHCAMPER_H
