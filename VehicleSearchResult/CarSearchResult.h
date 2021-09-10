#ifndef CARSEARCHRESULT_H
#define CARSEARCHRESULT_H

#include "VehicleSearchResult.h"
#include "../hierarchy/Car.h"

class CarSearchResult: public VehicleSearchResult{
private:
    Car* minValues;
    Car* maxValues;


public:
    explicit CarSearchResult(bool _make, bool _model, bool _warranty, bool _loan, bool _isNoviceDriver,
                             unsigned short int _emissionClass, Car* _minValues, Car* _maxValues);

    virtual ~CarSearchResult();
    virtual Vehicle* getMinValues() const;
    virtual Vehicle* getMaxValues() const;
};

#endif // CARSEARCHRESULT_H
