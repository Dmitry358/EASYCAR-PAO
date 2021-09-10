#include"Camper.h"

bool Camper::isBetweenType(VehicleSearchResult* values) const {
    Camper* minValues = dynamic_cast<Camper*>(values->getMinValues());

    if( getConditioner()    != minValues->getConditioner() ) return false;
    if( getPassengerNum()   != minValues->getPassengerNum() ) return false;
    if( getPintleHook()     != minValues->getPintleHook() ) return false;
    if( getSensors()        != minValues->getSensors() ) return false;

    if( getSleepingPlaces() != minValues->getSleepingPlaces() ) return false;
    if( getToilet()         != minValues->getToilet() ) return false;
    if( getKitchen()        != minValues->getKitchen() ) return false;

    return true;
}

Camper::Camper(string _make, string _model, unsigned int _registrationYear, unsigned int _mileage, double _basePrice,
               unsigned short int _fuelType, unsigned short int _transmissionType, unsigned int _power, unsigned int _displacement,
               bool _conditioner, unsigned int _passengerNum, bool _pintleHook, bool _sensors, unsigned int _sleepingPlaces,
               bool _toilet, bool _kitchen):

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
                    sleepingPlaces(_sleepingPlaces),
                    toilet(_toilet),
                    kitchen(_kitchen){}


Camper* Camper::clone() const { return new Camper(*this); }

unsigned int Camper::emissionClass() const{
    unsigned short int year=getRegistrationYear();
    if(year<1993) return 0;
    if(year>=1993 && year<1997) return 1;
    if(year>=1997 && year<2001) return 2;
    if(year>=2001 && year<2006) return 3;
    if(year>=2006 && year<2011) return 4;
    if(year>=2011 && year<2013) return 5;
    else return 6;
}

bool Camper::isNoviceDriver() const{
    if(getPower()>65) return false;
    else return true;
}

double Camper::vehicleTax() const{
    if(emissionClass()==0) return getPower()*3;
    if(emissionClass()==1) return getPower()*2.95;
    if(emissionClass()==2) return getPower()*2.8;
    if(emissionClass()==3) return getPower()*2.75;

    else return getPower()*2.58;
}

double Camper::getFullPrice(bool warranty) const {
    if(warranty) return getBasePrice()*1.15;
    else return getBasePrice();
}

double Camper::loansMonthlyPayment() const {
    return (getBasePrice()*1.2)/48;
}


unsigned int Camper::getSleepingPlaces() const { return sleepingPlaces; }

bool Camper::getToilet() const { return toilet; }

bool Camper::getKitchen() const { return kitchen; }