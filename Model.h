#ifndef MODEL_H
#define MODEL_H


#include <typeinfo>
#include <utility>
#include <vector>

#include "Container.h"
#include "DeepPtr.h"
#include "hierarchy/Vehicle.h"
#include "hierarchy/Moto.h"
#include "hierarchy/Car.h"
#include "hierarchy/Camper.h"
#include "hierarchy/Truck.h"

#include "VehicleSearchResult/MotoSearchResult.h"
#include "VehicleSearchResult/CarSearchResult.h"
#include "VehicleSearchResult/CamperSearchResult.h"
#include "VehicleSearchResult/TruckSearchResult.h"

using std::pair;
using std::vector;

class Model : public Container<DeepPtr<Vehicle>> {

public:
    explicit Model();

    void insertNewVehicle(Vehicle* _vehicle);

    std::vector<pair<Moto, unsigned int>>* showAllMoto() const;
    std::vector<pair<Car, unsigned int>>* showAllCar() const;
    std::vector<pair<Camper, unsigned int>>* showAllCamper() const;
    std::vector<pair<Truck, unsigned int>>* showAllTruck() const;


    std::vector<pair<Moto, unsigned int>>* searchMoto(MotoSearchResult* values) const;
    std::vector<pair<Car, unsigned int>>* searchCar(CarSearchResult* values) const;
    std::vector<pair<Camper, unsigned int>>* searchCamper(CamperSearchResult* values) const;
    std::vector<pair<Truck, unsigned int>>* searchTruck(TruckSearchResult* values) const;


    bool removeVehicle(unsigned int ix);

};

#endif // MODEL_H