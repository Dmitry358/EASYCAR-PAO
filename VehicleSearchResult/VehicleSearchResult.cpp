#include "VehicleSearchResult.h"

VehicleSearchResult::VehicleSearchResult(bool _make, bool _model, bool _warranty, bool _loan, bool _isNoviceDriver,
                                         unsigned short int _emissionClass):
                                         make(_make),
                                         model(_model),
                                         warranty(_warranty),
                                         loan(_loan),
                                         isNoviceDriver(_isNoviceDriver),
                                         emissionClass(_emissionClass){}

VehicleSearchResult::~VehicleSearchResult(){}

bool VehicleSearchResult::getMake() const { return make; }

bool VehicleSearchResult::getModel() const { return model; }

bool VehicleSearchResult::getWarranty() const { return warranty; }

bool VehicleSearchResult::getLoan() const { return loan; }

bool VehicleSearchResult::getIsNoviceDriver() const { return isNoviceDriver; }

unsigned short int VehicleSearchResult::getEmissionClass() const { return emissionClass; }