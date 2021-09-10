#include "CamperSearchResult.h"


CamperSearchResult::CamperSearchResult(bool _make, bool _model, bool _warranty, bool _loan, bool _isNoviceDriver,
                                       unsigned short int _emissionClass, Camper* _minValues, Camper* _maxValues):
                                       VehicleSearchResult(_make, _model, _warranty, _loan, _isNoviceDriver, _emissionClass),
                                       minValues(_minValues),
                                       maxValues(_maxValues){}

CamperSearchResult::~CamperSearchResult(){ delete minValues; delete maxValues; }

Vehicle* CamperSearchResult::getMinValues() const { return minValues; }

Vehicle* CamperSearchResult::getMaxValues() const { return maxValues; }



