#ifndef VEHICLE_H
#define VEHICLE_H

#include "../VehicleSearchResult/VehicleSearchResult.h"
#include <string>

class VehicleSearchResult;
using std::string;

class Vehicle{
private:
    string make;
    string model;
    unsigned int registrationYear;
    unsigned int mileage;
    double basePrice;
    unsigned short int fuelType;
    unsigned short int transmissionType;
    unsigned int power;
    unsigned int displacement;



protected:
    Vehicle(string _make, string _model, unsigned int _registrationYear, unsigned int _mileage, double _basePrice,
            unsigned short int _fuelType, unsigned short int _transmissionType, unsigned int _power,
            unsigned int _displacement);

public:
    virtual ~Vehicle();
    virtual Vehicle* clone() const=0;

    bool isEqual(Vehicle* ptr) const;
    bool isBetween(VehicleSearchResult* values) const;

    virtual bool isBetweenType(VehicleSearchResult *values) const=0;
    virtual unsigned int emissionClass() const=0;
    virtual bool isNoviceDriver() const=0;
    virtual double vehicleTax() const=0;
    virtual double getFullPrice(bool warrantry) const=0;
    virtual double loansMonthlyPayment() const=0;

    string getMake() const;
    string getModel() const;
    unsigned int getRegistrationYear() const;
    unsigned int getMileage() const;
    double getBasePrice() const;
    unsigned short int getFuelType() const;
    string getFuelTypeStr() const;
    unsigned short int getTransmissionType() const;
    string getTransmissionTypeStr() const;
    unsigned int getPower() const;
    unsigned int getDisplacement() const;
};

#endif
