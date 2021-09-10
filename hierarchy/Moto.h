#ifndef MOTO_H
#define MOTO_H


#include "Vehicle.h"
#include "../VehicleSearchResult/VehicleSearchResult.h"


class Moto: public Vehicle{
private:
    bool sidecar;
    bool engineProtection;

public:
    Moto(string _make, string _model, unsigned int _registrationYear, unsigned int _mileage, double _basePrice,
         unsigned short int _fuelType, unsigned short int _transmissionType, unsigned int _power, unsigned int _displacement,
         bool _sidecar, bool _engineProtection);


    virtual Moto* clone() const;
    virtual bool isBetweenType(VehicleSearchResult* values) const;
    virtual unsigned int emissionClass() const;
    virtual bool isNoviceDriver() const;
    virtual double vehicleTax() const;
    virtual double getFullPrice(bool warranty) const;
    virtual double loansMonthlyPayment() const;

    bool getSidecar() const;
    bool getEngineProtection() const;
};

#endif
