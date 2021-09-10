#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"
#include "Auto.h"
#include "../VehicleSearchResult/VehicleSearchResult.h"

class Car: public Auto{
private:
    bool stWagon;
    bool sunroof;
    bool luggagerack;

public:
    Car(string _make, string _model, unsigned int _registrationYear, unsigned int _mileage, double _basePrice,
        unsigned short int _fuelType, unsigned short int _transmissionType, unsigned int _power, unsigned int _displacement,
        bool _conditioner, unsigned int _passengerNum, bool _pintleHook, bool _sensors, bool _stWagon,
        bool _sunroof, bool _luggagerack);


    virtual Car* clone() const;
    virtual bool isBetweenType(VehicleSearchResult* values) const;
    virtual unsigned int emissionClass() const;
    virtual bool isNoviceDriver() const;
    virtual double vehicleTax() const;
    virtual double getFullPrice(bool warranty) const;
    virtual double loansMonthlyPayment() const;

    bool getStWagon() const;
    bool getSunroof() const;
    bool getLuggagerack() const;
};

#endif
