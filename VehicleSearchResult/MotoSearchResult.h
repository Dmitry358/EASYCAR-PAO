#ifndef MOTOSEARCHRESULT_H
#define MOTOSEARCHRESULT_H

#include "VehicleSearchResult.h"
#include "../hierarchy/Moto.h"

class MotoSearchResult: public VehicleSearchResult{
private:
    Moto* minValues;
    Moto* maxValues;


public:
    explicit MotoSearchResult(bool _make, bool _model, bool _warranty, bool _loan, bool _isNoviceDriver,
                              unsigned short int _emissionClass, Moto* _minValues, Moto* _maxValues);

    virtual ~MotoSearchResult();
    virtual Vehicle* getMinValues() const;
    virtual Vehicle* getMaxValues() const;
};


#endif // MOTOSEARCHRESULT_H
