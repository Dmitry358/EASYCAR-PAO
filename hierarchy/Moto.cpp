#include"Moto.h"

Moto::Moto(string _make, string _model, unsigned int _registrationYear, unsigned int _mileage, double _basePrice,
           unsigned short int _fuelType, unsigned short int _transmissionType, unsigned int _power, unsigned int _displacement,
           bool _sidecar, bool _engineProtection):

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
              sidecar(_sidecar),
              engineProtection(_engineProtection){}


bool Moto::isBetweenType(VehicleSearchResult* values) const {

    if( getSidecar()          != dynamic_cast<Moto*>(values->getMinValues())->getSidecar() ) return false;
    if( getEngineProtection() != dynamic_cast<Moto*>(values->getMinValues())->getEngineProtection() ) return false;
    return true;
}

Moto* Moto::clone() const { return new Moto(*this); }

unsigned int Moto::emissionClass() const {
    unsigned short int year=getRegistrationYear();
    if(getFuelType()==3) return 5;
    if(year<1999) return 0;
    if(year>=1999 && year<2003) return 1;
    if(year>=2003 && year<2006) return 2;
    if(year>=2006 && year<2016) return 3;
    if(year>=2016 && year<2019) return 4;    
    else return 5;
}

bool Moto::isNoviceDriver() const {
    if(getDisplacement()<=50 || getPower()<=4) return true;
    if(getDisplacement()>50 && getDisplacement()<=125 && getPower()<=11) return true;
    if(getDisplacement()>125 && getDisplacement()<=250 && getPower()<=35) return true;

    else return false;
}

double Moto::vehicleTax() const {
    if(emissionClass()==0) return 38.5;
    if(emissionClass()==1) return 27.8;
    if(emissionClass()==2) return 21;

    else return 19.11;
}

double Moto::getFullPrice(bool warranty) const {
    if(warranty) return getBasePrice()*1.05;
    else return getBasePrice();
}

double Moto::loansMonthlyPayment() const {
    return (getBasePrice()*1.1)/48;
}


bool Moto::getSidecar() const { return sidecar; }

bool Moto::getEngineProtection() const { return engineProtection; }
