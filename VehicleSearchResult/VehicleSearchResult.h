#ifndef VEHICLESEARCHRESULT_H
#define VEHICLESEARCHRESULT_H

#include "../hierarchy/Vehicle.h"

class Vehicle;


class VehicleSearchResult {
private:
    bool make;
    bool model;
    bool warranty;
    bool loan;
    bool isNoviceDriver;
    unsigned short int emissionClass;

public:
    explicit VehicleSearchResult(bool _make, bool _model, bool _warranty, bool _loan, bool _isNoviceDriver,
                                 unsigned short int _emissionClass);

    virtual ~VehicleSearchResult();

    virtual Vehicle* getMinValues() const=0;
    virtual Vehicle* getMaxValues() const=0;

    bool getMake() const;
    bool getModel() const;
    bool getWarranty() const;
    bool getLoan() const;
    bool getIsNoviceDriver() const;
    unsigned short int getEmissionClass() const;
};


#endif // VEHICLESEARCHRESULT_H
