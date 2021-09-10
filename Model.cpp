#include "Model.h"

Model::Model(){}


void Model::insertNewVehicle(Vehicle* _vehicle){
    push_back(_vehicle);
}


std::vector<pair<Moto, unsigned int>>* Model::searchMoto(MotoSearchResult* values) const {

        std::vector<pair<Moto, unsigned int>>* result = new std::vector<pair<Moto, unsigned int>>;

        auto it=cbegin();
        unsigned int ix=0;

        for(; it!=cend(); ++it){
            Vehicle* aux = (*it).get();
            Vehicle* minValues = values->getMinValues();

            if(aux != nullptr && minValues != nullptr){
                if(aux->isEqual(minValues)){
                    if(aux->isBetween(values)){
                        Moto* moto=dynamic_cast<Moto*>(aux);
                        pair<Moto, unsigned int> mi(*moto, ix);
                        result->push_back(mi);
                    }
                }
            }
        }

        delete values;

        if(result->empty()){
            delete result;
            return nullptr;
        }
        else return result;
}

std::vector<pair<Car, unsigned int>>* Model::searchCar(CarSearchResult* values) const {

        std::vector<pair<Car, unsigned int>>* result = new std::vector<pair<Car, unsigned int>>;

        auto it=cbegin();
        unsigned int ix=0;

        for(; it!=cend(); ++it){
            Vehicle* aux = (*it).get();
            Vehicle* minValues = values->getMinValues();

            if(aux != nullptr && minValues != nullptr){
                if(aux->isEqual(minValues)){
                    if(aux->isBetween(values)){
                        Car* car=dynamic_cast<Car*>(aux);
                        pair<Car, unsigned int> mi(*car, ix);
                        result->push_back(mi);
                    }
                }
            }
        }

        delete values;

        if(result->empty()){
            delete result;
            return nullptr;
        }
        return result;
}

std::vector<pair<Camper, unsigned int>>* Model::searchCamper(CamperSearchResult* values) const {

        std::vector<pair<Camper, unsigned int>>* result = new std::vector<pair<Camper, unsigned int>>;

        auto it=cbegin();
        unsigned int ix=0;

        for(; it!=cend(); ++it){
            Vehicle* aux = (*it).get();
            Vehicle* minValues = values->getMinValues();

            if(aux != nullptr && minValues != nullptr){
                if(aux->isEqual(minValues)){
                    if(aux->isBetween(values)){
                        Camper* camper=dynamic_cast<Camper*>(aux);
                        pair<Camper, unsigned int> mi(*camper, ix);
                        result->push_back(mi);
                    }
                }
            }
        }

        delete values;

        if(result->empty()){
            delete result;
            return nullptr;
        }
        return result;
}

std::vector<pair<Truck, unsigned int>>* Model::searchTruck(TruckSearchResult* values) const {

        std::vector<pair<Truck, unsigned int>>* result = new std::vector<pair<Truck, unsigned int>>;

        auto it=cbegin();
        unsigned int ix=0;

        for(; it!=cend(); ++it){
            Vehicle* aux = (*it).get();
            Vehicle* minValues = values->getMinValues();

            if(aux != nullptr && minValues != nullptr){
                if(aux->isEqual(minValues)){
                    if(aux->isBetween(values)){
                        Truck* truck=dynamic_cast<Truck*>(aux);
                        pair<Truck, unsigned int> mi(*truck, ix);
                        result->push_back(mi);
                    }
                }
            }
        }

        delete values;

        if(result->empty()){
            delete result;
            return nullptr;
        }
        return result;
}



std::vector<pair<Moto, unsigned int>>* Model::showAllMoto() const {
    std::vector<pair<Moto, unsigned int>>* result = new std::vector<pair<Moto, unsigned int>>;

    Moto* moto=nullptr;
    unsigned int ix=0;
    auto it=begin();

    if(it.isValid()){
        for(; it!=end(); ++it){
            moto=dynamic_cast<Moto*>((*it).get());

            if(moto){
                Moto* mp=moto->clone();
                pair<Moto, unsigned int> aux(*mp,ix);
                result->push_back(aux);
                delete mp;
            }
            ++ix;
        }
    }

    if(result->empty()){
        delete result;
        return nullptr;
    }

    else return result;
}

std::vector<pair<Car, unsigned int>>* Model::showAllCar() const {
    std::vector<pair<Car, unsigned int>>* result = new std::vector<pair<Car, unsigned int>>;

    Car* car=nullptr;
    unsigned int ix=0;
    auto it=begin();

    if(it.isValid()){
        for(; it!=end(); ++it){
            car=dynamic_cast<Car*>((*it).get());

            if(car){
                Car* cp=car->clone();
                pair<Car, unsigned int> aux(*cp,ix);
                result->push_back(aux);
                delete cp;
            }
            ++ix;
        }
    }

    if(result->empty()){
        delete result;
        return nullptr;
    }

    else return result;
}

std::vector<pair<Camper, unsigned int>>* Model::showAllCamper() const {

    std::vector<pair<Camper, unsigned int>>* result = new std::vector<pair<Camper, unsigned int>>;

    Camper* camper=nullptr;

    unsigned int ix=0;
    auto it=begin();

    if(it.isValid()){
        for(; it!=end(); ++it){
            camper=dynamic_cast<Camper*>((*it).get());

            if(camper){
                Camper* cp=camper->clone();
                pair<Camper, unsigned int> aux(*cp,ix);
                result->push_back(aux);
                delete cp;
            }
            ++ix;
        }
    }
    if(result->empty()){
        delete result;
        return nullptr;
    }

    else return result;
}

std::vector<pair<Truck, unsigned int>>* Model::showAllTruck() const {

    std::vector<pair<Truck, unsigned int>>* result = new std::vector<pair<Truck, unsigned int>>;

    Truck* truck=nullptr;

    unsigned int ix=0;
    auto it=begin();

    if(it.isValid()){
        for(; it!=end(); ++it){
            truck=dynamic_cast<Truck*>((*it).get());

            if(truck){
                Truck* tp=truck->clone();
                pair<Truck, unsigned int> aux(*tp,ix);
                result->push_back(aux);
                delete tp;
            }
            ++ix;
        }
    }
    if(result->empty()){
        delete result;
        return nullptr;
    }

    else return result;
}



bool Model::removeVehicle(unsigned int ix){
    auto it = begin() + ix;
    it = erase(it);

    return it.isValid() ? true : false;
}


