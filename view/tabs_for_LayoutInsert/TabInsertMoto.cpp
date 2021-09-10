#include "TabInsertMoto.h"

TabInsertMoto::TabInsertMoto(QWidget* p):
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

              sidecar(new QCheckBox("Carrozzino", this)),
              engineProtection(new QCheckBox("Paramotore", this))
{
    QVBoxLayout* loMotoTab=new QVBoxLayout(this);

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
    fuelType->addItem("Elettrica");

    transmissionType->addItem("Cambio");
    transmissionType->addItem("Manuale");
    transmissionType->addItem("Automatico");

    power->setPlaceholderText("Potenza");
    power->setValidator(powerValidator);

    displacement->setPlaceholderText("Cilindrata");
    displacement->setValidator(displacementValidator);


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

    grid->addWidget(sidecar,4,0,1,2);
    grid->addWidget(engineProtection,4,2,1,2);

    grid->setSpacing(35);

    loMotoTab->addLayout(grid);
    setLayout(loMotoTab);
}



bool TabInsertMoto::checkTabMotoFieldsFilling() const {

    if (make->text().isEmpty()) return false;
    if (model->text().isEmpty()) return false;
    if (registrationYear->currentIndex()==0) return false;
    if (mileage->text().isEmpty()) return false;
    if (basePrice->text().isEmpty()) return false;
    if (fuelType->currentIndex()==0) return false;
    if (transmissionType->currentIndex()==0) return false;
    if (power->text().isEmpty()) return false;
    if (displacement->text().isEmpty()) return false;

    else return true;
}

Moto* TabInsertMoto::returnVehicleForInsert() const {
    if(checkTabMotoFieldsFilling()){
        return new Moto(getMake(),
                        getModel(),
                        getRegistrationYear(),
                        getMileage(),
                        getBasePrice(),
                        getFuelType(),
                        getTansmissionType(),
                        getPower(),
                        getDisplacement(),

                        getSidecar(),
                        getEngineProtection()
                        );
     }

    else return nullptr;
}

void TabInsertMoto::clearAllFields() const {
    make->setText("");
    model->setText("");
    registrationYear->setCurrentIndex(0);
    mileage->setText("");
    basePrice->setText("");
    fuelType->setCurrentIndex(0);
    transmissionType->setCurrentIndex(0);
    power->setText("");
    displacement->setText("");

    sidecar->setChecked(false);
    engineProtection->setChecked(false);
}



string TabInsertMoto::getMake() const {
    QString str=make->text();
    return str.toStdString();
}

string TabInsertMoto::getModel() const {
    QString str=model->text();
    return str.toStdString();
}

unsigned int TabInsertMoto::getRegistrationYear() const { return (registrationYear->currentText()).toUInt(); }

unsigned int TabInsertMoto::getMileage() const {
    QString str=mileage->text();
    return str.toUInt();
}

double TabInsertMoto::getBasePrice() const {
    QString str=basePrice->text();
    return str.toDouble();
}

unsigned short int TabInsertMoto::getFuelType() const {
    if(fuelType->currentText() == QString("Benzina")) return 0;
    else return 3;
}

unsigned short int TabInsertMoto::getTansmissionType() const {
    if(transmissionType->currentText() == QString("Manuale")) return 0;
    else return 1;
}

unsigned int TabInsertMoto::getPower() const {
    QString str=power->text();
    return str.toUInt();
}

unsigned int TabInsertMoto::getDisplacement() const {
    QString str=displacement->text();
    return str.toUInt();
}



bool TabInsertMoto::getSidecar() const { return sidecar->isChecked(); }

bool TabInsertMoto::getEngineProtection() const { return engineProtection->isChecked(); }
