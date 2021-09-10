#ifndef TABINSERTMOTO_H
#define TABINSERTMOTO_H

#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QGridLayout>
#include <QString>

#include <string>

#include "../../hierarchy/Moto.h"

using std::string;

class TabInsertMoto: public QWidget {
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

    QCheckBox* sidecar;
    QCheckBox* engineProtection;


    bool checkTabMotoFieldsFilling() const;

    string getMake() const;
    string getModel() const;
    unsigned int getRegistrationYear() const;
    unsigned int getMileage() const;
    double getBasePrice() const;
    unsigned short int getFuelType() const;
    unsigned short int getTansmissionType() const;
    unsigned int getPower() const;
    unsigned int getDisplacement() const;

    bool getSidecar() const;
    bool getEngineProtection() const;


public:
    explicit TabInsertMoto(QWidget* =nullptr);

    Moto* returnVehicleForInsert() const;
    void clearAllFields() const;
};

#endif // TABINSERTMOTO_H
