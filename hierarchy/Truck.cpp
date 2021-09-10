#include"Truck.h"

bool Truck::isBetweenType(VehicleSearchResult* values) const {
    Truck* minValues = dynamic_cast<Truck*>(values->getMinValues());
    Truck* maxValues = dynamic_cast<Truck*>(values->getMinValues());


    if( getMaxLoadability() < minValues->getMaxLoadability() ) return false;
    if( getMaxLoadability() > maxValues->getMaxLoadability() ) return false;

    if( getSleepingPlace()  != minValues->getSleepingPlace() ) return false;

    if( getDangerousGood()  != minValues->getDangerousGood() ) return false;

    return true;
}

Truck::Truck(string _make, string _model, unsigned int _registrationYear, unsigned int _mileage, double _basePrice,
             unsigned short int _fuelType, unsigned short int _transmissionType, unsigned int _power, unsigned int _displacement,
             unsigned int _maxLoadability, bool _sleepingPlace, bool _dangerousGood):

                    Vehicle(_make,
                            _model,
                            _registrationYear,
                            _mileage,
                            _basePrice,
                            _fuelType,
                            _transmissionType,
                            _power,
                            _displacement),
                    maxLoadability(_maxLoadability),
                    sleepingPlace(_sleepingPlace),
                    dangerousGood(_dangerousGood){}


Truck* Truck::clone() const { return new Truck(*this); }

unsigned int Truck::emissionClass() const {
    unsigned short int year=getRegistrationYear();
    if(year<1993) return 0;
    if(year>=1993 && year<1997) return 1;
    if(year>=1997 && year<2001) return 2;
    if(year>=2001 && year<2006) return 3;
    else return 4;
}

bool Truck::isNoviceDriver() const {
    return true;
}

double Truck::vehicleTax() const {
    if(getMaxLoadability()>=100) return 517.56;
    if(getMaxLoadability()>=75) return 400.31;
    if(getMaxLoadability()>=50) return 317.19;
    if(getMaxLoadability()>=25) return 234.1;

    else return 156.47;
}

double Truck::getFullPrice(bool warranty) const {
    if(warranty) return getBasePrice()*1.1;
    else return getBasePrice();
}

double Truck::loansMonthlyPayment() const {
    return (getBasePrice()*1.15)/48;
}


bool Truck::getSleepingPlace() const { return sleepingPlace;}

unsigned int Truck::getMaxLoadability() const { return maxLoadability;}

bool Truck::getDangerousGood() const { return dangerousGood;}