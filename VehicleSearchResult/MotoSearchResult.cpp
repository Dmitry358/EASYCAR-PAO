#include "MotoSearchResult.h"

MotoSearchResult::MotoSearchResult(bool _make, bool _model, bool _warranty, bool _loan, bool _isNoviceDriver,
                                   unsigned short int _emissionClass, Moto* _minValues, Moto* _maxValues):
                                   VehicleSearchResult(_make, _model, _warranty, _loan, _isNoviceDriver, _emissionClass),
                                   minValues(_minValues),
                                   maxValues(_maxValues){}

MotoSearchResult::~MotoSearchResult(){ delete minValues; delete maxValues; }

Vehicle* MotoSearchResult::getMinValues() const { return minValues; }

Vehicle* MotoSearchResult::getMaxValues() const { return maxValues; }




