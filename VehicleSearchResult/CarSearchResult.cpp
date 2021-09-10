#include "CarSearchResult.h"

CarSearchResult::CarSearchResult(bool _make, bool _model, bool _warranty, bool _loan, bool _isNoviceDriver,
                                 unsigned short int _emissionClass, Car* _minValues, Car* _maxValues):
                                 VehicleSearchResult(_make, _model, _warranty, _loan, _isNoviceDriver, _emissionClass),
                                 minValues(_minValues),
                                 maxValues(_maxValues){}

CarSearchResult::~CarSearchResult(){ delete minValues; delete maxValues; }

Vehicle* CarSearchResult::getMinValues() const { return minValues; }

Vehicle* CarSearchResult::getMaxValues() const { return maxValues; }

