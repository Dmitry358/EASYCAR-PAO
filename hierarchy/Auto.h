#ifndef AUTO_H
#define AUTO_H

#include "Vehicle.h"

class Auto: public Vehicle{
private:
    bool conditioner;
    unsigned int passengerNum;
    bool pintleHook;
    bool sensors;

protected:
    Auto(string _make, string _model, unsigned int _registrationYear, unsigned int _mileage, double _basePrice,
         unsigned short int _fuelType, unsigned short int _transmissionType, unsigned int _power, unsigned int _displacement,
         bool _conditioner, unsigned int _passengerNum, bool _pintleHook, bool _sensors);

public:
    bool getConditioner() const;
    unsigned int getPassengerNum() const;
    bool getPintleHook() const;
    bool getSensors() const;
};

#endif // AUTO_H
