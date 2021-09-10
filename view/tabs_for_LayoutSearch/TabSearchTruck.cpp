#include"TabSearchTruck.h"

TruckSearchResult* TabSearchTruck::getTruckSearchValues() const{
    if(checkTabTruckFieldsFilling()){
    Truck* minValues= new Truck(getMake(),
                                getModel(),
                                getRegistrationYearFrom(),
                                getMileageFrom(),
                                getFullPriceFrom(),
                                getFuelType(),
                                getTansmissionType(),
                                getEmissionClass(), //power
                                getVehicleTaxFrom(), //displacement

                                getMaxLoadabilityFrom(),
                                getSleepingPlace(),
                                getDangerousGood()
                                );

    Truck* maxValues= new Truck(getMake(),
                                getModel(),
                                getRegistrationYearTo(),
                                getMileageTo(),
                                getFullPriceTo(),
                                getFuelType(),
                                getTansmissionType(),
                                getEmissionClass(), //power
                                getVehicleTaxTo(), //displacement

                                getMaxLoadabilityTo(),
                                getSleepingPlace(),
                                getDangerousGood()
                                );

    return new TruckSearchResult((getMake()).empty() ? false : true,
                                 (getModel()).empty() ? false: true,
                                  getWarranty(),
                                  getPriceType(),
                                  getMaxLoadabilityFilling(),
                                  getEmissionClass(),
                                  minValues,
                                  maxValues
                                  );
    }

    else return nullptr;
}


TabSearchTruck::TabSearchTruck(QWidget* p):
              QWidget(p),
              make(new QLineEdit(this)),
              model(new QLineEdit(this)),
              registrationYearFrom(new QComboBox(this)),
              registrationYearTo(new QComboBox(this)),
              mileage(new QComboBox(this)),
              priceType(new QComboBox(this)),
              warranty(new QCheckBox("Garanzia",this)),
              fullPriceFrom(new QLineEdit(this)),
              fullPriceTo(new QLineEdit(this)),
              fuelType(new QComboBox(this)),
              transmissionType(new QComboBox(this)),

              maxLoadabilityFrom(new QLineEdit(this)),
              maxLoadabilityTo(new QLineEdit(this)),
              sleepingPlace(new QCheckBox("Posto per dormire", this)),
              dangerousGood(new QCheckBox("Sostanze pericolose", this)),

              emissionClass(new QComboBox(this)),
              vehicleTaxFrom(new QLineEdit(this)),
              vehicleTaxTo(new QLineEdit(this))
{
    QVBoxLayout* loTruckTab=new QVBoxLayout(this);

    QValidator* fullPriceValidator = new QIntValidator(0, 10000000, this);
    QValidator* vehicleTaxValidator = new QIntValidator(0, 10000, this);
    QValidator* maxLoadabilityValidator = new QIntValidator(0, 10000, this);

    make->setPlaceholderText("Marca");

    model->setPlaceholderText("Modello");

    registrationYearFrom->addItem("Immatricolazione da");
    for(int i=2021; i>1980; --i) registrationYearFrom->addItem(QString::number(i));

    registrationYearTo->addItem("Immatricolazione fino");
    for(int i=2021; i>1980; --i) registrationYearTo->addItem(QString::number(i));

    mileage->addItem("Chilometraggio");
    for(int i=0; i<400; i+=25) mileage->addItem(QString::fromStdString(std::to_string(i)+".000-"+std::to_string(i+25)+".000"));
    mileage->addItem("> 400.000");

    fullPriceFrom->setPlaceholderText("Prezzo da");
    fullPriceFrom->setValidator(fullPriceValidator);

    fullPriceTo->setPlaceholderText("Prezzo fino");
    fullPriceTo->setValidator(fullPriceValidator);

    priceType->addItem("Prezzo intero");
    priceType->addItem("Finaziamento");

    fuelType->addItem("Carburante");
    fuelType->addItem("Benzina");
    fuelType->addItem("Disel");

    transmissionType->addItem("Cambio");
    transmissionType->addItem("Manuale");
    transmissionType->addItem("Automatico");
    transmissionType->addItem("Ibrido");

    maxLoadabilityFrom->setPlaceholderText("Portata da");
    maxLoadabilityFrom->setValidator(maxLoadabilityValidator);

    maxLoadabilityTo->setPlaceholderText("Portata fino");
    maxLoadabilityTo->setValidator(maxLoadabilityValidator);

    for(int i=0; i<5; ++i) emissionClass->addItem(QString::fromStdString("EURO "+std::to_string(i)));

    vehicleTaxFrom->setPlaceholderText("Bollo da");
    vehicleTaxFrom->setValidator(vehicleTaxValidator);

    vehicleTaxTo->setPlaceholderText("Bollo fino");
    vehicleTaxTo->setValidator(vehicleTaxValidator);

    QGridLayout *grid= new QGridLayout;

    grid->addWidget(make,0,0,1,2);
    grid->addWidget(model,0,2,1,2);
    grid->addWidget(fullPriceFrom,1,0,1,2);
    grid->addWidget(fullPriceTo,1,2,1,2);
    grid->addWidget(priceType,2,0,1,2);
    grid->addWidget(warranty,2,2,1,2);
    grid->addWidget(mileage,3,0,1,2);
    grid->addWidget(emissionClass,3,2,1,2);
    grid->addWidget(registrationYearFrom,4,0,1,2);
    grid->addWidget(registrationYearTo,4,2,1,2);
    grid->addWidget(fuelType,5,0,1,2);
    grid->addWidget(transmissionType,5,2,1,2);
    grid->addWidget(vehicleTaxFrom,6,0,1,2);
    grid->addWidget(vehicleTaxTo,6,2,1,2);
    grid->addWidget(maxLoadabilityFrom,7,0,1,2);
    grid->addWidget(maxLoadabilityTo,7,2,1,2);
    grid->addWidget(sleepingPlace,8,0,1,2);
    grid->addWidget(dangerousGood,8,2,1,2);

    grid->setAlignment(Qt::AlignTop);
    grid->setSpacing(25);

    loTruckTab->addLayout(grid);
    setLayout(loTruckTab);
}



void TabSearchTruck::clearAllFields() const {
    make->setText("");
    model->setText("");
    registrationYearFrom->setCurrentIndex(0);
    registrationYearTo->setCurrentIndex(0);
    mileage->setCurrentIndex(0);
    priceType->setCurrentIndex(0);
    warranty->setChecked(false);
    fullPriceFrom->setText("");
    fullPriceTo->setText("");
    fuelType->setCurrentIndex(0);
    transmissionType->setCurrentIndex(0);

    maxLoadabilityFrom->setText("");
    maxLoadabilityTo->setText("");
    sleepingPlace->setChecked(false);
    dangerousGood->setChecked(false);

    emissionClass->setCurrentIndex(0);
    vehicleTaxFrom->setText("");
    vehicleTaxTo->setText("");
}

bool TabSearchTruck::checkTabTruckFieldsFilling() const {

    if (getRegistrationYearFrom() > getRegistrationYearTo()) return false;

    if (getFullPriceFrom() > getFullPriceTo()) return false;

    if (fuelType->currentIndex()==0) return false;

    if (transmissionType->currentIndex()==0) return false;

    if (getVehicleTaxFrom() > getVehicleTaxTo()) return false;

    if (getMaxLoadabilityFrom() > getMaxLoadabilityTo()) return false;

    return true;
}

bool TabSearchTruck::getMaxLoadabilityFilling() const {
    if(!(vehicleTaxFrom->text().isEmpty())) return true;
    if(!(vehicleTaxTo->text().isEmpty())) return true;
    return false;
}



string TabSearchTruck::getMake() const {
    QString str=make->text();
    return str.toStdString();
}

string TabSearchTruck::getModel() const {
    QString str=model->text();
    return str.toStdString();
}

unsigned int TabSearchTruck::getRegistrationYearFrom() const {
    if(registrationYearFrom->currentIndex()==0) return 1981;
    return (registrationYearFrom->currentText()).toUInt();
}

unsigned int TabSearchTruck::getRegistrationYearTo() const {
    if(registrationYearTo->currentIndex()==0) return 2021;
    return (registrationYearTo->currentText()).toUInt();
}

unsigned int TabSearchTruck::getMileageFrom() const {
    if(mileage->currentIndex()==0) return 0;
    if(mileage->currentIndex() > 16) return 400001;

    else return (mileage->currentIndex()-1)*25000;
}

unsigned int TabSearchTruck::getMileageTo() const {
    if(mileage->currentIndex() >16 || mileage->currentIndex()==0) return 2000000;

    else return (mileage->currentIndex())*25000;
}

bool TabSearchTruck::getPriceType() const {
    if(priceType->currentIndex()==0) return false;
    else return true;
}

bool TabSearchTruck::getWarranty() const {
    return warranty->isChecked();
}

double TabSearchTruck::getFullPriceFrom() const {
    if(fullPriceFrom->text().isEmpty()) return 0;
    QString str=fullPriceFrom->text();
    return str.toDouble();
}

double TabSearchTruck::getFullPriceTo() const {
    if(fullPriceTo->text().isEmpty()) return 10000000;
    QString str=fullPriceTo->text();
    return str.toDouble();
}

unsigned short int TabSearchTruck::getFuelType() const {
    if(fuelType->currentIndex() == 1) return 0;
    else return 1;
}

unsigned short int TabSearchTruck::getTansmissionType() const {
    if(transmissionType->currentText() == QString("Manuale")) return 0;
    if(transmissionType->currentText() == QString("Automatico")) return 1;
    else return 2;
}



unsigned int TabSearchTruck::getMaxLoadabilityFrom() const {
    if(vehicleTaxFrom->text().isEmpty()) return 0;
    QString str=vehicleTaxFrom->text();
    return str.toUInt();

}

unsigned int TabSearchTruck::getMaxLoadabilityTo() const {
    if(vehicleTaxTo->text().isEmpty()) return 10000;
    QString str=vehicleTaxTo->text();
    return str.toUInt();
}

bool TabSearchTruck::getSleepingPlace() const {
    return sleepingPlace->isChecked();
}

bool TabSearchTruck::getDangerousGood() const {
    return dangerousGood->isChecked();
}



unsigned short int TabSearchTruck::getEmissionClass() const {
    return emissionClass->currentIndex();
}

unsigned int TabSearchTruck::getVehicleTaxFrom() const {
    if(vehicleTaxFrom->text().isEmpty()) return 0;
    QString str=vehicleTaxFrom->text();
    return str.toUInt();
}

unsigned int TabSearchTruck::getVehicleTaxTo() const {
    if(vehicleTaxTo->text().isEmpty()) return 10000;
    QString str=vehicleTaxTo->text();
    return str.toUInt();
}
