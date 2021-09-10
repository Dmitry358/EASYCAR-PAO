#include"TabSearchCamper.h"

CamperSearchResult* TabSearchCamper::getCamperSearchValues() const {
    if(checkTabCamperFieldsFilling()){
    Camper* minValues= new Camper(getMake(),
                              getModel(),
                              getRegistrationYearFrom(),
                              getMileageFrom(),
                              getFullPriceFrom(),
                              getFuelType(),
                              getTansmissionType(),
                              getEmissionClass(), //power
                              getVehicleTaxFrom(), //displacement

                              getConditioner(),
                              getPassengerNum(),
                              getPintleHook(),
                              getSensors(),

                              getSleepingPlaces(),
                              getToilet(),
                              getKitchen()
                              );

    Camper* maxValues= new Camper(getMake(),
                              getModel(),
                              getRegistrationYearTo(),
                              getMileageTo(),
                              getFullPriceTo(),
                              getFuelType(),
                              getTansmissionType(),
                              getEmissionClass(), //power
                              getVehicleTaxTo(), //displacement

                              getConditioner(),
                              getPassengerNum(),
                              getPintleHook(),
                              getSensors(),

                              getSleepingPlaces(),
                              getToilet(),
                              getKitchen()
                              );

    return new CamperSearchResult((getMake()).empty() ? false : true,
                                 (getModel()).empty() ? false: true,
                                  getWarranty(),
                                  getPriceType(),
                                  getIsNoviceDriver(),
                                  getEmissionClass(),
                                  minValues,
                                  maxValues
                                  );
    }

    else return nullptr;
}

TabSearchCamper::TabSearchCamper(QWidget* p):
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

              conditioner(new QCheckBox("Climatizzatore", this)),
              passengerNum(new QComboBox(this)),
              pintleHook(new QCheckBox("Gancio traino", this)),
              sensors(new QCheckBox("Sensori parcheggio", this)),

              sleepingPlaces(new QComboBox(this)),
              toilet(new QCheckBox("Bagno", this)),
              kitchen(new QCheckBox("Cucina", this)),

              isNoviceDriver(new QCheckBox("Neopatentato", this)),
              emissionClass(new QComboBox(this)),
              vehicleTaxFrom(new QLineEdit(this)),
              vehicleTaxTo(new QLineEdit(this))


{
    QVBoxLayout* loCamperTab=new QVBoxLayout(this);

    QValidator* fullPriceValidator = new QIntValidator(0, 10000000, this);
    QValidator* vehicleTaxValidator = new QIntValidator(0, 10000, this);

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
    fuelType->addItem("Gas");

    transmissionType->addItem("Cambio");
    transmissionType->addItem("Manuale");
    transmissionType->addItem("Automatico");
    transmissionType->addItem("Ibrido");

    for(int i=0; i<7; ++i) emissionClass->addItem(QString::fromStdString("EURO "+std::to_string(i)));

    vehicleTaxFrom->setPlaceholderText("Bollo da");
    vehicleTaxFrom->setValidator(vehicleTaxValidator);

    vehicleTaxTo->setPlaceholderText("Bollo fino");
    vehicleTaxTo->setValidator(vehicleTaxValidator);

    passengerNum->addItem("Numero passeggeri");
    for(int i=1; i<5; ++i) passengerNum->addItem(QString::fromStdString(std::to_string(i)));

    sleepingPlaces->addItem("Posti per dormire");
    for(int i=1; i<4; ++i) sleepingPlaces->addItem(QString::fromStdString(std::to_string(i)));


    QGridLayout *grid= new QGridLayout;
    QGridLayout *grid_1= new QGridLayout;

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
    grid->addWidget(sleepingPlaces,7,0,1,2);
    grid->addWidget(passengerNum,7,2,1,2);

    grid_1->addWidget(conditioner,0,0);
    grid_1->addWidget(pintleHook,0,1);
    grid_1->addWidget(sensors,0,2);    
    grid_1->addWidget(isNoviceDriver,1,0);
    grid_1->addWidget(toilet,1,1);
    grid_1->addWidget(kitchen,1,2);


    grid->setAlignment(Qt::AlignTop);
    grid->setSpacing(25);
    grid_1->setAlignment(Qt::AlignTop);
    grid_1->setSpacing(20);

    loCamperTab->addLayout(grid);
    loCamperTab->addLayout(grid_1);
    setLayout(loCamperTab);
}

void TabSearchCamper::clearAllFields() const {
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

    conditioner->setChecked(false);
    passengerNum->setCurrentIndex(0);
    pintleHook->setChecked(false);
    sensors->setChecked(false);

    sleepingPlaces->setCurrentIndex(0);
    toilet->setChecked(false);
    kitchen->setChecked(false);

    isNoviceDriver->setChecked(false);
    emissionClass->setCurrentIndex(0);
    vehicleTaxFrom->setText("");
    vehicleTaxTo->setText("");
}

bool TabSearchCamper::checkTabCamperFieldsFilling() const {

    if (getRegistrationYearFrom() > getRegistrationYearTo()) return false;

    if (getFullPriceFrom() > getFullPriceTo()) return false;

    if (fuelType->currentIndex()==0) return false;

    if (transmissionType->currentIndex()==0) return false;

    if (getVehicleTaxFrom() > getVehicleTaxTo()) return false;

    if (passengerNum->currentIndex()==0) return false;

    if (sleepingPlaces->currentIndex()==0) return false;

    return true;
}


string TabSearchCamper::getMake() const {
    QString str=make->text();
    return str.toStdString();
}

string TabSearchCamper::getModel() const {
    QString str=model->text();
    return str.toStdString();
}

unsigned int TabSearchCamper::getRegistrationYearFrom() const {
    if(registrationYearFrom->currentIndex()==0) return 1981;
    return (registrationYearFrom->currentText()).toUInt();
}

unsigned int TabSearchCamper::getRegistrationYearTo() const {
    if(registrationYearTo->currentIndex()==0) return 2021;
    return (registrationYearTo->currentText()).toUInt();
}

unsigned int TabSearchCamper::getMileageFrom() const {
    if(mileage->currentIndex()==0) return 0;
    if(mileage->currentIndex() > 16) return 400001;

    else return (mileage->currentIndex()-1)*25000;
}

unsigned int TabSearchCamper::getMileageTo() const {
    if(mileage->currentIndex() >16 || mileage->currentIndex()==0) return 2000000;

    else return (mileage->currentIndex())*25000;
}

bool TabSearchCamper::getPriceType() const {
    if(priceType->currentIndex()==0) return false;
    else return true;
}

bool TabSearchCamper::getWarranty() const {
    return warranty->isChecked();
}

double TabSearchCamper::getFullPriceFrom() const {
    if (fullPriceFrom->text().isEmpty()) return 0;
    QString str=fullPriceFrom->text();
    return str.toDouble();
}

double TabSearchCamper::getFullPriceTo() const {
    if(fullPriceTo->text().isEmpty()) return 10000000;
    QString str=fullPriceTo->text();
    return str.toDouble();
}

unsigned short int TabSearchCamper::getFuelType() const {
    if(fuelType->currentIndex() == 1) return 0;
    if(fuelType->currentIndex() == 2) return 1;
    else return 2;
}

unsigned short int TabSearchCamper::getTansmissionType() const {
    if(transmissionType->currentText() == QString("Manuale")) return 0;
    if(transmissionType->currentText() == QString("Automatico")) return 1;
    else return 2;
}


bool TabSearchCamper::getConditioner() const {
    return conditioner->isChecked();
}

unsigned short int TabSearchCamper::getPassengerNum() const {
    return passengerNum->currentIndex();
}

bool TabSearchCamper::getPintleHook() const {
    return pintleHook->isChecked();
}

bool TabSearchCamper::getSensors() const {
    return sensors->isChecked();
}

unsigned short TabSearchCamper::getSleepingPlaces() const {
    return sleepingPlaces->currentIndex();
}

bool TabSearchCamper::getToilet() const {
    return toilet->isChecked();
}

bool TabSearchCamper::getKitchen() const {
    return kitchen->isChecked();
}



bool TabSearchCamper::getIsNoviceDriver() const {
    return isNoviceDriver->isChecked();
}

unsigned short int TabSearchCamper::getEmissionClass() const {
    return emissionClass->currentIndex();
}

unsigned int TabSearchCamper::getVehicleTaxFrom() const {
    if (vehicleTaxFrom->text().isEmpty()) return 0;
    QString str=vehicleTaxFrom->text();
    return str.toUInt();
}

unsigned int TabSearchCamper::getVehicleTaxTo() const {
    if (vehicleTaxTo->text().isEmpty()) return 10000;
    QString str=vehicleTaxTo->text();
    return str.toUInt();
}

