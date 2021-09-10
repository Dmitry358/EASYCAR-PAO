#include"TabInsertCar.h"

TabInsertCar::TabInsertCar(QWidget* p):
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

              stWagon(new QCheckBox("Station Wagon", this)),
              sunroof(new QCheckBox("Lunotto",this)),
              luggagerack(new QCheckBox("Portapacchi", this))

{
    QVBoxLayout* loCarTab=new QVBoxLayout(this);

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
    fuelType->addItem("Elettrica");

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

    grid->addWidget(stWagon,6,0,1,2);
    grid->addWidget(sunroof,6,2,1,2);
    grid->addWidget(luggagerack,6,4,1,2);

    grid->setSpacing(25);

    loCarTab->addLayout(grid);
    setLayout(loCarTab);
}

bool TabInsertCar::checkTabCarFieldsFilling() const {

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

    else return true;
}

void TabInsertCar::clearAllFields() const {
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

    stWagon->setChecked(false);
    sunroof->setChecked(false);
    luggagerack->setChecked(false);
}

Car* TabInsertCar::returnVehicleForInsert() const {
    if(checkTabCarFieldsFilling()){
        return new Car(getMake(),
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

                       getStWagon(),
                       getSunroof(),
                       getLuggagerack()
                       );
    }

    else return nullptr;
}


string TabInsertCar::getMake() const {
    QString str=make->text();
    return str.toStdString();
}

string TabInsertCar::getModel() const {
    QString str=model->text();
    return str.toStdString();
}

unsigned int TabInsertCar::getRegistrationYear() const { return (registrationYear->currentText()).toUInt(); }

unsigned int TabInsertCar::getMileage() const {
    QString str=mileage->text();
    return str.toUInt();
}

double TabInsertCar::getBasePrice() const {
    QString str=basePrice->text();
    return str.toDouble();
}

unsigned short int TabInsertCar::getFuelType() const {
    if(fuelType->currentText() == QString("Benzina")) return 0;
    if(fuelType->currentText() == QString("Disel")) return 1;
    if(fuelType->currentText() == QString("Gas")) return 2;
    else return 3;
}

unsigned short int TabInsertCar::getTansmissionType() const {
    if(transmissionType->currentText() == QString("Manuale")) return 0;
    if(transmissionType->currentText() == QString("Automatico")) return 1;
    else return 2;
}

unsigned int TabInsertCar::getPower() const {
    QString str=power->text();
    return str.toUInt();
}

unsigned int TabInsertCar::getDisplacement() const {
    QString str=displacement->text();
    return str.toUInt();
}


bool TabInsertCar::getConditioner() const { return  conditioner->isChecked(); }

unsigned int TabInsertCar::getPassengerNum() const { return (passengerNum->currentText()).toUInt(); }

bool TabInsertCar::getPintleHook() const { return pintleHook->isChecked(); }

bool TabInsertCar::getSensors() const { return sensors->isChecked(); }


bool TabInsertCar::getStWagon() const { return stWagon->isChecked(); }

bool TabInsertCar::getSunroof() const { return sunroof->isChecked(); }

bool TabInsertCar::getLuggagerack() const { return luggagerack->isChecked(); }
