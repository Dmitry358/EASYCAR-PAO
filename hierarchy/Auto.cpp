#include"Auto.h"

Auto::Auto(string _make, string _model, unsigned int _registrationYear, unsigned int _mileage, double _basePrice,
           unsigned short int _fuelType, unsigned short int _transmissionType, unsigned int _power, unsigned int _displacement,
           bool _conditioner, unsigned int _passengerNum, bool _pintleHook, bool _sensors):

                Vehicle(_make,
                        _model,
                        _registrationYear,
                        _mileage,
                        _basePrice,
                        _fuelType,
                        _transmissionType,
                        _power,
                        _displacement
                        ),
                conditioner(_conditioner),
                passengerNum(_passengerNum),
                pintleHook(_pintleHook),
                sensors(_sensors){}


bool Auto::getConditioner() const { return conditioner; }

unsigned int Auto::getPassengerNum() const { return passengerNum; }

bool Auto::getPintleHook() const { return pintleHook; }

bool Auto::getSensors() const { return sensors; }
