#include "Container.h"
#include "DeepPtr.h"
#include "hierarchy/Vehicle.h"
#include <string>
using std::string;



void loadVehicles(Model& model){

int i=1995;

i=1995;
for(; i<2020; ++i){ //MOTO
    string str("BMW "); str.append(std::to_string(i-1995));

    Vehicle* moto=new Moto(str, //MAKE
                           "E0", //MODEL
                           i, //REGISTRATION YEAR
                           47000+(i*101.5), //MILEAGE
                           5000+(i*3), //BASEPRICE
                           0, //FUEL TYPE (0-3)
                           0, //TRANSMISSION (0-1)
                           40, //POWER
                           151, //DISPLACEMENT

                           false, //SIDECAR
                           false //ENGINEPROTECTION
                           );

    model.push_back(moto);
}


i=1995;
for(; i<2020; ++i){ //CAR
    string str("Audi "); str.append(std::to_string(i));
    Vehicle* car=new Car(str, "100" , 2000+i, 50000+(i*100), 15000+(i*10), 0, 0, 5, 15,
                          false, 2, true, true, true, false, true);
    model.push_back(car);
}


i=1995;
for(; i<2020; ++i){ //MOTO
    string str("KTM"); str.append(std::to_string(i-1994));

    Vehicle* moto=new Moto(str, //MAKE
                           "X3", //MODEL
                           i, //REGISTRATION YEAR
                           47000+(i*101.5), //MILEAGE
                           5000+(i*3), //BASEPRICE
                           0, //FUEL TYPE (0-3)
                           0, //TRANSMISSION (0-1)
                           40, //POWER
                           151, //DISPLACEMENT

                           false, //SIDECAR
                           true //ENGINEPROTECTION
                           );

    model.push_back(moto);
}


i=1995;
for(; i<2020; ++i){ //CAMPER
    string str("Camper "); str.append(std::to_string(i));
    Vehicle* camper=new Camper(str,
                              "Voyager" ,
                              2000+i,
                              50000+(i*100),
                              15000+(i*10),
                              0,
                              0,
                              5,
                              15,

                              false,
                              2,
                              true,
                              true,

                              4,
                              false,
                              true);
    model.push_back(camper);
}

i=1995;
for(; i<2020; ++i){ //TRUCK
    string str("IVECO "); str.append(std::to_string(i-1994));

    Vehicle* truck=new Truck(str, //MAKE
                             "F1", //MODEL
                             i, //REGISTRATION YEAR
                             47000+(i*101.5), //MILEAGE
                             5000+(i*3), //BASEPRICE
                             0 , //FUEL TYPE (0-3)
                             0, //TRANSMISSION (0-1)
                             40, //POWER
                             151, //DISPLACEMENT
                             10,//MAXLOADABILITY

                             false, //SIDECAR
                             false //ENGINEPROTECTION
                           );

    model.push_back(truck);
}



} //END
