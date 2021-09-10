#ifndef TABSEARCHCMOTO_H
#define TABSEARCHCMOTO_H

#include <QLineEdit>
#include <QTextEdit>
#include <QComboBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QGridLayout>
#include <QLabel>
#include <QString>
#include <string>

#include "../../hierarchy/Moto.h"
#include "../../VehicleSearchResult/MotoSearchResult.h"

using std::string;


class TabSearchMoto: public QWidget{
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

    QCheckBox* sidecar;
    QCheckBox* engineProtection;

    QCheckBox* isNoviceDriver;
    QComboBox* emissionClass;
    QLineEdit* vehicleTaxFrom;
    QLineEdit* vehicleTaxTo;

    bool checkTabMotoFieldsFilling() const;

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

    bool getSidecar() const;
    bool getEngineProtection() const;

    bool getIsNoviceDriver() const;
    unsigned short int getEmissionClass() const;
    unsigned int getVehicleTaxFrom() const;
    unsigned int getVehicleTaxTo() const;


public:
    explicit TabSearchMoto(QWidget* =nullptr);

    MotoSearchResult* getMotoSearchValues() const;

    void clearAllFields() const;
};

#endif // TABSEARCHCMOTO_H
