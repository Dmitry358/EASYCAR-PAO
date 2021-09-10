#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"
#include "../VehicleSearchResult/VehicleSearchResult.h"

class Truck: public Vehicle{
private:
    unsigned int maxLoadability;
    bool sleepingPlace;
    bool dangerousGood;


public:
    Truck(string _make, string _model, unsigned int _registrationYear, unsigned int _mileage, double _basePrice,
          unsigned short int _fuelType, unsigned short int _transmissionType, unsigned int _power, unsigned int _displacement,
          unsigned int _maxLoadability, bool _sleepingPlace, bool _dangerousGood);


    virtual Truck* clone() const;
    virtual bool isBetweenType(VehicleSearchResult* values) const;
    virtual unsigned int emissionClass() const;
    virtual bool isNoviceDriver() const;
    virtual double vehicleTax() const;
    virtual double getFullPrice(bool warranty) const;
    virtual double loansMonthlyPayment() const;

    unsigned int getMaxLoadability() const;
    bool getSleepingPlace() const;
    bool getDangerousGood() const;
};

#endif
