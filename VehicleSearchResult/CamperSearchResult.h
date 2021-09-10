#ifndef CAMPERSEARCHRESULT_H
#define CAMPERSEARCHRESULT_H

#include "VehicleSearchResult.h"
#include "../hierarchy/Camper.h"

class CamperSearchResult: public VehicleSearchResult{
private:
    Camper* minValues;
    Camper* maxValues;


public:
    explicit CamperSearchResult(bool _make, bool _model, bool _warranty, bool _loan, bool _isNoviceDriver,
                                unsigned short int _emissionClass, Camper* _minValues, Camper* _maxValues);

    virtual ~CamperSearchResult();
    virtual Vehicle* getMinValues() const;
    virtual Vehicle* getMaxValues() const;
};



#endif // CAMPERSEARCHRESULT_H
