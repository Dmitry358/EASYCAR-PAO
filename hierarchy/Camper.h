#ifndef CAMPER_H
#define CAMPER_H

#include "Auto.h"
#include "../VehicleSearchResult/VehicleSearchResult.h"

class Camper: public Auto{

private:
    unsigned int sleepingPlaces;
    bool toilet;
    bool kitchen;


public:
    Camper(string _make, string _model, unsigned int _registrationYear, unsigned int _mileage, double _basePrice,
           unsigned short int _fuelType, unsigned short int _transmissionType, unsigned int _power, unsigned int _displacement,
           bool _conditioner, unsigned int _passengerNum, bool _pintleHook, bool _sensors, unsigned int _sleepingPlaces,
           bool _toilet, bool _kitchen);


    virtual Camper* clone() const;
    virtual bool isBetweenType(VehicleSearchResult* values) const;

    virtual unsigned int emissionClass() const;
    virtual bool isNoviceDriver() const;
    virtual double vehicleTax() const;
    virtual double getFullPrice(bool warranty) const;
    virtual double loansMonthlyPayment() const;

    unsigned int getSleepingPlaces() const;
    bool getToilet() const;
    bool getKitchen() const;
};

#endif
