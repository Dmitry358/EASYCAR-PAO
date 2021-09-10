#include"Vehicle.h"

Vehicle::Vehicle(string _make, string _model, unsigned int _registrationYear, unsigned int _mileage, double _basePrice,
                 unsigned short int _fuelType, unsigned short int _transmissionType, unsigned int _power, unsigned int _displacement):

                 make(_make),
                 model(_model),
                 registrationYear(_registrationYear),
                 mileage(_mileage),
                 basePrice(_basePrice),
                 fuelType(_fuelType),
                 transmissionType(_transmissionType),
                 power(_power),
                 displacement(_displacement)
                 {}

Vehicle::~Vehicle(){}

bool Vehicle::isEqual(Vehicle* ptr) const {
    if(typeid(*this)==typeid(*ptr)) return true;
    else return false;
}

bool Vehicle::isBetween(VehicleSearchResult *values) const {

    Vehicle* minValues = values->getMinValues();
    Vehicle* maxValues =values->getMaxValues();

    if( values->getMake() ){
        if( getMake() != minValues->getMake() ) return false;
    }

    if( values->getModel() ){
        if( getModel() != minValues->getModel() ) return false;
    }

    bool warranty = values->getWarranty();
    if( values->getLoan() ){
        if( loansMonthlyPayment() < minValues->getFullPrice(false) ) return false;
        if( loansMonthlyPayment() > maxValues->getFullPrice(false) ) return false;
    }
    else{
        if( getFullPrice(warranty) < minValues->getFullPrice(false) ) return false;
        if( getFullPrice(warranty) > maxValues->getFullPrice(false) ) return false;
    }

    if( getMileage() < minValues->getMileage() ) return false;
    if( getMileage() > maxValues->getMileage() ) return false;

    if( emissionClass() !=  minValues->getPower() ) return false;

    if( getRegistrationYear() < minValues->getRegistrationYear() ) return false;
    if( getRegistrationYear() > maxValues->getRegistrationYear() ) return false;

    if( getFuelType() !=  minValues->getFuelType() ) return false;

    if( getTransmissionType() !=  minValues->getTransmissionType() ) return false;

    if( vehicleTax() < minValues->getDisplacement() ) return false;
    if( vehicleTax() > maxValues->getDisplacement() ) return false;

    if( values->getIsNoviceDriver() ){
        if( !isNoviceDriver() ) return false;
    }

     return isBetweenType(values);
}


string Vehicle::getMake() const { return make; }

string Vehicle::getModel() const { return model; }

unsigned int Vehicle::getRegistrationYear() const { return registrationYear; }

unsigned int Vehicle::getMileage() const { return mileage; }

double Vehicle::getBasePrice() const { return basePrice; }

unsigned short int Vehicle::getFuelType() const { return fuelType; }

unsigned short int Vehicle::getTransmissionType() const { return transmissionType; }

string Vehicle::getFuelTypeStr() const {
    if(fuelType==0) return "benzina";
    if(fuelType==1) return "diesel";
    if(fuelType==2) return "gas";
    else  return "electrica";
}

string Vehicle::getTransmissionTypeStr() const {
    if(transmissionType == 0) return "manuale";
    if(transmissionType == 1) return "automatico";
    else return "ibrido";
}

unsigned int Vehicle::getPower() const { return power; }

unsigned int Vehicle::getDisplacement() const { return displacement; }
