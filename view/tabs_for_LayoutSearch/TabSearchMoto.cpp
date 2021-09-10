#include"TabSearchMoto.h"

MotoSearchResult* TabSearchMoto::getMotoSearchValues() const {
    if(checkTabMotoFieldsFilling()){
    Moto* minValues= new Moto(getMake(),
                              getModel(),
                              getRegistrationYearFrom(),
                              getMileageFrom(),
                              getFullPriceFrom(),
                              getFuelType(),
                              getTansmissionType(),
                              getEmissionClass(), //power
                              getVehicleTaxFrom(), //displacement

                              getSidecar(),
                              getEngineProtection()
                              );

    Moto* maxValues= new Moto(getMake(),
                              getModel(),
                              getRegistrationYearTo(),
                              getMileageTo(),
                              getFullPriceTo(),
                              getFuelType(),
                              getTansmissionType(),
                              getEmissionClass(), //power
                              getVehicleTaxTo(), //displacement

                              getSidecar(),
                              getEngineProtection()
                              );

    return new MotoSearchResult( (getMake()).empty() ? false : true,
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


TabSearchMoto::TabSearchMoto(QWidget* p):
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

              sidecar(new QCheckBox("Carrozzina", this)),
              engineProtection(new QCheckBox("Paramotore", this)),

              isNoviceDriver(new QCheckBox("Neopatentato", this)),
              emissionClass(new QComboBox(this)),
              vehicleTaxFrom(new QLineEdit(this)),
              vehicleTaxTo(new QLineEdit(this))
{
    QVBoxLayout* loMotoTab=new QVBoxLayout(this); //Serve??

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
    fuelType->addItem("Elettrica");

    transmissionType->addItem("Cambio");
    transmissionType->addItem("Manuale");
    transmissionType->addItem("Automatico");

    for(int i=0; i<6; ++i) emissionClass->addItem(QString::fromStdString("EURO "+std::to_string(i)));

    vehicleTaxFrom->setPlaceholderText("Bollo da");
    vehicleTaxFrom->setValidator(vehicleTaxValidator);

    vehicleTaxTo->setPlaceholderText("Bollo fino");
    vehicleTaxTo->setValidator(vehicleTaxValidator);

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

    grid_1->addWidget(isNoviceDriver,0,0);
    grid_1->addWidget(engineProtection,0,1);
    grid_1->addWidget(sidecar,0,2);

    grid->setAlignment(Qt::AlignTop);
    grid->setSpacing(25);
    grid_1->setAlignment(Qt::AlignTop);
    grid_1->setSpacing(37);
    grid_1->setContentsMargins(0,15,0,0);

    loMotoTab->addLayout(grid);
    loMotoTab->addLayout(grid_1);
    setLayout(loMotoTab);
}



void TabSearchMoto::clearAllFields() const {
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

    sidecar->setChecked(false);
    engineProtection->setChecked(false);

    isNoviceDriver->setChecked(false);
    emissionClass->setCurrentIndex(0);
    vehicleTaxFrom->setText("");
    vehicleTaxTo->setText("");
}

bool TabSearchMoto::checkTabMotoFieldsFilling() const {

    if (getRegistrationYearFrom() > getRegistrationYearTo()) return false;

    if (getFullPriceFrom() > getFullPriceTo()) return false;

    if (fuelType->currentIndex()==0) return false;

    if (transmissionType->currentIndex()==0) return false;

    if (getVehicleTaxFrom() > getVehicleTaxTo()) return false;

    return true;
}



string TabSearchMoto::getMake() const {
    QString str=make->text();
    return str.toStdString();
}

string TabSearchMoto::getModel() const {
    QString str=model->text();
    return str.toStdString();
}

unsigned int TabSearchMoto::getRegistrationYearFrom() const {
    if(registrationYearFrom->currentIndex()==0) return 1981;
    return (registrationYearFrom->currentText()).toUInt();
}

unsigned int TabSearchMoto::getRegistrationYearTo() const {
    if(registrationYearTo->currentIndex()==0) return 2021;
    return (registrationYearTo->currentText()).toUInt();
}

unsigned int TabSearchMoto::getMileageFrom() const {
    if(mileage->currentIndex()==0) return 0;
    if(mileage->currentIndex() > 16) return 400001;

    else return (mileage->currentIndex()-1)*25000;
}

unsigned int TabSearchMoto::getMileageTo() const {
    if(mileage->currentIndex() >16 || mileage->currentIndex()==0) return 2000000;

    else return (mileage->currentIndex())*25000;
}

bool TabSearchMoto::getPriceType() const {
    if(priceType->currentIndex()==0) return false;
    else return true;
}

bool TabSearchMoto::getWarranty() const {
    return warranty->isChecked();
}

double TabSearchMoto::getFullPriceFrom() const {
    if(fullPriceFrom->text().isEmpty()) return 0;
    QString str=fullPriceFrom->text();
    return str.toDouble();
}

double TabSearchMoto::getFullPriceTo() const {
    if(fullPriceTo->text().isEmpty()) return 10000000;
    QString str=fullPriceTo->text();
    return str.toDouble();
}

unsigned short int TabSearchMoto::getFuelType() const {
    if(fuelType->currentIndex() == 1) return 0;
    else return 3;
}

unsigned short int TabSearchMoto::getTansmissionType() const {
    if(transmissionType->currentText() == QString("Manuale")) return 0;
    else return 1;
}


bool TabSearchMoto::getSidecar() const {
    return sidecar->isChecked();
}

bool TabSearchMoto::getEngineProtection() const {
    return engineProtection->isChecked();
}


bool TabSearchMoto::getIsNoviceDriver() const {
    return isNoviceDriver->isChecked();
}

unsigned short int TabSearchMoto::getEmissionClass() const {
    return emissionClass->currentIndex();
}

unsigned int TabSearchMoto::getVehicleTaxFrom() const {
    if(vehicleTaxFrom->text().isEmpty()) return 0;
    QString str=vehicleTaxFrom->text();
    return str.toUInt();
}

unsigned int TabSearchMoto::getVehicleTaxTo() const {
    if(vehicleTaxTo->text().isEmpty()) return 10000;
    QString str=vehicleTaxTo->text();
    return str.toUInt();
}
