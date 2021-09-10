#include"Car.h"

bool Car::isBetweenType(VehicleSearchResult* values) const {

    Car* minValues = dynamic_cast<Car*>(values->getMinValues());

    if( getConditioner()      != minValues->getConditioner() ) return false;
    if( getPassengerNum()     != minValues->getPassengerNum() ) return false;
    if( getPintleHook()       != minValues->getPintleHook() ) return false;
    if( getSensors()          != minValues->getSensors() ) return false;

    if( getStWagon()          != minValues->getStWagon() ) return false;
    if( getSunroof()          != minValues->getSunroof() ) return false;
    if( getLuggagerack()      != minValues->getLuggagerack() ) return false;

    return true;

}

Car::Car(string _make, string _model, unsigned int _registrationYear, unsigned int _mileage, double _basePrice,
         unsigned short int _fuelType, unsigned short int _transmissionType, unsigned int _power, unsigned int _displacement,
         bool _conditioner, unsigned int _passengerNum, bool _pintleHook, bool _sensors, bool _stWagon,
         bool _sunroof, bool _luggagerack):

            Auto(_make,
                 _model,
                 _registrationYear,
                 _mileage,
                 _basePrice,
                 _fuelType,
                 _transmissionType,
                 _power,
                 _displacement,
                 _conditioner,
                 _passengerNum,
                 _pintleHook,
                 _sensors),
           stWagon(_stWagon),
           sunroof(_sunroof),
           luggagerack(_luggagerack){}

Car* Car::clone() const { return new Car(*this); }

unsigned int Car::emissionClass() const {
    unsigned short int year=getRegistrationYear();
    if(getFuelType()==3) return 6;
    if(year<1993) return 0;
    if(year>=1993 && year<1997) return 1;
    if(year>=1997 && year<2001) return 2;
    if(year>=2001 && year<2006) return 3;
    if(year>=2006 && year<2011) return 4;
    if(year>=2011 && year<2015) return 5;
    else return 6;
}

bool Car::isNoviceDriver() const{
    if(getPower()>70) return false;
    else return true;
}

double Car::vehicleTax() const{
    if(emissionClass()==0) return getPower()*3;
    if(emissionClass()==1) return getPower()*2.9;
    if(emissionClass()==2) return getPower()*2.8;
    if(emissionClass()==3) return getPower()*2.7;

    else return getPower()*2.58;
}

double Car::getFullPrice(bool warranty) const {
    if(warranty) return getBasePrice()*1.1;
    else return getBasePrice();
}

double Car::loansMonthlyPayment() const {
    return (getBasePrice()*1.15)/48;
}


bool Car::getStWagon() const { return stWagon; }

bool Car::getSunroof() const { return sunroof; }

bool Car::getLuggagerack() const { return luggagerack; }
