#include"TabInsertTruck.h"

TabInsertTruck::TabInsertTruck(QWidget* p):
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

              maxLoadability(new QLineEdit(this)),
              sleepingPlace(new QCheckBox("Posto per dormire", this)),
              dangerousGood(new QCheckBox("Sostanze pericolose", this))
{
    QVBoxLayout* loTruckTab=new QVBoxLayout(this);

    QValidator* priceValidator = new QIntValidator(0, 10000000, this);
    QValidator* mileageValidator = new QIntValidator(0, 2000000, this);
    QValidator* powerValidator = new QIntValidator(0, 1000, this);
    QValidator* displacementValidator = new QIntValidator(0, 20000, this);
    QValidator* maxLoadabilityValidator = new QIntValidator(0, 50000, this);

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

    transmissionType->addItem("Cambio");
    transmissionType->addItem("Manuale");
    transmissionType->addItem("Automatico");
    transmissionType->addItem("Ibrido");

    power->setPlaceholderText("Potenza");
    power->setValidator(powerValidator);

    displacement->setPlaceholderText("Cilindrata");
    displacement->setValidator(displacementValidator);

    maxLoadability->setPlaceholderText("Portata massima");
    maxLoadability->setValidator(maxLoadabilityValidator);


    QGridLayout *grid= new QGridLayout;

    grid->addWidget(make,0,0,1,2);
    grid->addWidget(model,0,2,1,2);

    grid->addWidget(registrationYear,1,0,1,2);
    grid->addWidget(mileage,1,2,1,2);

    grid->addWidget(basePrice,2,0,1,2);
    grid->addWidget(fuelType,2,2);
    grid->addWidget(transmissionType,2,3);

    grid->addWidget(power,3,0,1,2);
    grid->addWidget(displacement,3,2,1,2);

    grid->addWidget(maxLoadability,4,0,1,2);
    grid->addWidget(sleepingPlace,4,2,1,2);
    grid->addWidget(dangerousGood,5,0,1,2);

    grid->setSpacing(25);

    loTruckTab->addLayout(grid);
    setLayout(loTruckTab);
}

bool TabInsertTruck::checkTabTruckFieldsFilling() const {

    if (make->text().isEmpty()) return false;
    if (model->text().isEmpty()) return false;
    if (registrationYear->currentIndex()==0) return false;
    if (mileage->text().isEmpty()) return false;
    if (basePrice->text().isEmpty()) return false;
    if (fuelType->currentIndex()==0) return false;
    if (transmissionType->currentIndex()==0) return false;
    if (power->text().isEmpty()) return false;
    if (displacement->text().isEmpty()) return false;
    if (maxLoadability->text().isEmpty()) return false;

    else return true;
}

void TabInsertTruck::clearAllFields() const {
    make->setText("");
    model->setText("");
    registrationYear->setCurrentIndex(0);
    mileage->setText("");
    basePrice->setText("");
    fuelType->setCurrentIndex(0);
    transmissionType->setCurrentIndex(0);
    power->setText("");
    displacement->setText("");

    maxLoadability->setText("");
    sleepingPlace->setChecked(false);
    dangerousGood->setChecked(false);
}

Truck* TabInsertTruck::returnVehicleForInsert() const {
    if(checkTabTruckFieldsFilling()){
       return new Truck(getMake(),
                        getModel(),
                        getRegistrationYear(),
                        getMileage(),
                        getBasePrice(),
                        getFuelType(),
                        getTansmissionType(),
                        getPower(),
                        getDisplacement(),

                        getMaxLoadability(),
                        getSleepingPlace(),
                        getDangerousGood()
                        );
    }

    else return nullptr;
}



string TabInsertTruck::getMake() const {
    QString str=make->text();
    return str.toStdString();
}

string TabInsertTruck::getModel() const {
    QString str=model->text();
    return str.toStdString();
}

unsigned int TabInsertTruck::getRegistrationYear() const { return (registrationYear->currentText()).toUInt(); }

unsigned int TabInsertTruck::getMileage() const {
    QString str=mileage->text();
    return str.toUInt();
}

double TabInsertTruck::getBasePrice() const {
    QString str=basePrice->text();
    return str.toDouble();
}

unsigned short int TabInsertTruck::getFuelType() const {
    if(fuelType->currentText() == QString("Benzina")) return 0;
    else return 1;
}

unsigned short int TabInsertTruck::getTansmissionType() const {
    if(transmissionType->currentText() == QString("Manuale")) return 0;
    if(transmissionType->currentText() == QString("Automatico")) return 1;
    else return 2;
}

unsigned int TabInsertTruck::getPower() const {
    QString str=power->text();
    return str.toUInt();
}

unsigned int TabInsertTruck::getDisplacement() const {
    QString str=displacement->text();
    return str.toUInt();
}


unsigned int TabInsertTruck::getMaxLoadability() const {
    QString str=maxLoadability->text();
    return str.toUInt();
 }

bool TabInsertTruck::getSleepingPlace() const { return sleepingPlace->isChecked(); }

bool TabInsertTruck::getDangerousGood() const { return dangerousGood->isChecked(); }