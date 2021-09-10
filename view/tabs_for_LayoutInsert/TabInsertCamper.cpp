#include"TabInsertCamper.h"

TabInsertCamper::TabInsertCamper(QWidget* p):
              QWidget(p),
              make(new QLineEdit(this)),
              model(new QLineEdit(this)),
              registrationYear(new QComboBox(this)),
              mileage(new QLineEdit(this)),
              basePrice(new QLineEdit(this)),
              fuelType(new QComboBox(this)),
              transmissionType(new QComboBox(this)),
              power(new QLineEdit(this)),
              displacement(new QLineEdit(this)),

              conditioner(new QCheckBox("Climatizzatore", this)),
              passengerNum(new QComboBox(this)),
              pintleHook(new QCheckBox("Gancio traino", this)),
              sensors(new QCheckBox("Sensori parcheggio", this)),

              sleepingPlaces(new QComboBox(this)),
              toilet(new QCheckBox("Bagno", this)),
              kitchen(new QCheckBox("Cucina", this))

{
    QVBoxLayout* loCamperTab=new QVBoxLayout(this);

    QValidator* priceValidator = new QIntValidator(0, 10000000, this);
    QValidator* mileageValidator = new QIntValidator(0, 2000000, this);
    QValidator* powerValidator = new QIntValidator(0, 1000, this);
    QValidator* displacementValidator = new QIntValidator(0, 20000, this);

    make->setPlaceholderText("Marca");
    make->setMaxLength(20);

    model->setPlaceholderText("Modello");
    model->setMaxLength(20);

    registrationYear->addItem("Anno immatricolazione");
    for(int i=2021; i>1980; --i) registrationYear->addItem(QString::number(i));

    mileage->setPlaceholderText("Chilometraggio");
    mileage->setValidator(mileageValidator);

    basePrice->setPlaceholderText("Prezzo");
    basePrice->setValidator(priceValidator);

    fuelType->addItem("Carburante");
    fuelType->addItem("Benzina");
    fuelType->addItem("Disel");
    fuelType->addItem("Gas");

    transmissionType->addItem("Cambio");
    transmissionType->addItem("Manuale");
    transmissionType->addItem("Automatico");
    transmissionType->addItem("Ibrido");

    power->setPlaceholderText("Potenza");
    power->setValidator(powerValidator);


    displacement->setPlaceholderText("Cilindrata");
    displacement->setValidator(displacementValidator);


    passengerNum->addItem("Numero passeggeri");
    for(int i=1; i<7; ++i) passengerNum->addItem(QString::number(i));

    sleepingPlaces->addItem("Posti per dormire");
    for(int i=1; i<5; ++i) sleepingPlaces->addItem(QString::number(i));

    QGridLayout *grid= new QGridLayout;

    grid->addWidget(make,0,0,1,3);
    grid->addWidget(model,0,3,1,3);

    grid->addWidget(registrationYear,1,0,1,3);
    grid->addWidget(mileage,1,3,1,3);

    grid->addWidget(basePrice,3,0,1,2);
    grid->addWidget(fuelType,3,4,1,2);
    grid->addWidget(transmissionType,3,2,1,2);

    grid->addWidget(power,4,0,1,2);
    grid->addWidget(displacement,4,2,1,2);

    grid->addWidget(conditioner,5,0,1,2);
    grid->addWidget(passengerNum,4,4,1,2);
    grid->addWidget(pintleHook,5,2,1,2);
    grid->addWidget(sensors,5,4,1,2);

    grid->addWidget(kitchen,6,0,1,2);
    grid->addWidget(toilet,6,2,1,2);
    grid->addWidget(sleepingPlaces,6,4,1,2);

    grid->setSpacing(25);

    loCamperTab->addLayout(grid);
    setLayout(loCamperTab);
}

bool TabInsertCamper::checkTabCamperFieldsFilling() const {

    if (make->text().isEmpty()) return false;
    if (model->text().isEmpty()) return false;
    if (registrationYear->currentIndex()==0) return false;
    if (mileage->text().isEmpty()) return false;
    if (basePrice->text().isEmpty()) return false;
    if (fuelType->currentIndex()==0) return false;
    if (transmissionType->currentIndex()==0) return false;
    if (power->text().isEmpty()) return false;
    if (displacement->text().isEmpty()) return false;
    if (passengerNum->currentIndex()==0) return false;
    if (sleepingPlaces->currentIndex()==0) return false;

    else return true;
}

void TabInsertCamper::clearAllFields() const {
    make->setText("");
    model->setText("");
    registrationYear->setCurrentIndex(0);
    mileage->setText("");
    basePrice->setText("");
    fuelType->setCurrentIndex(0);
    transmissionType->setCurrentIndex(0);
    power->setText("");
    displacement->setText("");

    conditioner->setChecked(false);
    passengerNum->setCurrentIndex(0);
    pintleHook->setChecked(false);
    sensors->setChecked(false);

    sleepingPlaces->setCurrentIndex(0);
    toilet->setChecked(false);
    kitchen->setChecked(false);
}

Camper* TabInsertCamper::returnVehicleForInsert() const {
    if(checkTabCamperFieldsFilling()){
        return new Camper(getMake(),
                          getModel(),
                          getRegistrationYear(),
                          getMileage(),
                          getBasePrice(),
                          getFuelType(),
                          getTansmissionType(),
                          getPower(),
                          getDisplacement(),

                          getConditioner(),
                          getPassengerNum(),
                          getPintleHook(),
                          getSensors(),

                          getSleepingPlaces(),
                          getToilet(),
                          getKitchen()
                          );
    }

    else return nullptr;
}


string TabInsertCamper::getMake() const {
    QString str=make->text();
    return str.toStdString();
}

string TabInsertCamper::getModel() const {
    QString str=model->text();
    return str.toStdString();
}

unsigned int TabInsertCamper::getRegistrationYear() const { return (registrationYear->currentText()).toUInt(); }

unsigned int TabInsertCamper::getMileage() const {
    QString str=mileage->text();
    return str.toUInt();
}

double TabInsertCamper::getBasePrice() const {
    QString str=basePrice->text();
    return str.toDouble();
}

unsigned short int TabInsertCamper::getFuelType() const {
    if(fuelType->currentText() == QString("Benzina")) return 0;
    if(fuelType->currentText() == QString("Disel")) return 1;
    if(fuelType->currentText() == QString("Gas")) return 2;
    else return 3;
}

unsigned short int TabInsertCamper::getTansmissionType() const {
    if(transmissionType->currentText() == QString("Manuale")) return 0;
    if(transmissionType->currentText() == QString("Automatico")) return 1;
    else return 2;
}

unsigned int TabInsertCamper::getPower() const {
    QString str=power->text();
    return str.toUInt();
}

unsigned int TabInsertCamper::getDisplacement() const {
    QString str=displacement->text();
    return str.toUInt();
}


bool TabInsertCamper::getConditioner() const { return  conditioner->isChecked(); }

unsigned int TabInsertCamper::getPassengerNum() const { return (passengerNum->currentText()).toUInt(); }

bool TabInsertCamper::getPintleHook() const { return pintleHook->isChecked(); }

bool TabInsertCamper::getSensors() const { return sensors->isChecked(); }


unsigned int TabInsertCamper::getSleepingPlaces() const { return (sleepingPlaces->currentText()).toUInt(); }

bool TabInsertCamper::getToilet() const { return  toilet->isChecked(); }

bool TabInsertCamper::getKitchen() const { return  kitchen->isChecked();}