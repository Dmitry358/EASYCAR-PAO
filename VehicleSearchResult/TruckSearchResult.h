#ifndef TRUCKSEARCHRESULT_H
#define TRUCKSEARCHRESULT_H

#include "VehicleSearchResult.h"
#include "../hierarchy/Truck.h"

class TruckSearchResult: public VehicleSearchResult{
private:
    Truck* minValues;
    Truck* maxValues;


public:
    explicit TruckSearchResult(bool _make, bool _model, bool _warranty, bool _loan, bool _isMaxLoadability,
                               unsigned short int _emissionClass, Truck* _minValues, Truck* _maxValues);

    virtual ~TruckSearchResult();
    virtual Vehicle* getMinValues() const;
    virtual Vehicle* getMaxValues() const;
};

#endif // TRUCKSEARCHRESULT_H
