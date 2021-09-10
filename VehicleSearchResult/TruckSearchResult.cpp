#include "TruckSearchResult.h"

TruckSearchResult::TruckSearchResult(bool _make, bool _model, bool _warranty, bool _loan, bool _isMaxLoadability,
                                     unsigned short int _emissionClass, Truck* _minValues, Truck* _maxValues):
                                     VehicleSearchResult(_make, _model, _warranty, _loan, _isMaxLoadability, _emissionClass),
                                     minValues(_minValues),
                                     maxValues(_maxValues){}

TruckSearchResult::~TruckSearchResult(){ delete minValues; delete maxValues; }

Vehicle* TruckSearchResult::getMinValues() const { return minValues; }

Vehicle* TruckSearchResult::getMaxValues() const { return maxValues; }



