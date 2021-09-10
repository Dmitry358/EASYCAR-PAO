#include "ItemCar.h"

ItemCar::ItemCar(QString _make, QString _model, QString _registrationYear, QString _mileage, QString _fullPrice,
                 QString _fuelType, QString _transmissionType, QString _power, QString _displacement,
                 QString _conditioner, QString _passengerNum, QString _pintleHook, QString _sensors, QString _stWagon,
                 QString _sunroof, QString _luggagerack, QWidget* parent):

                 QWidget(parent),
                 make(new QLabel(_make, this)),
                 model(new QLabel(_model, this)),
                 registrationYear(new QLabel(_registrationYear, this)),
                 mileage(new QLabel(_mileage, this)),
                 fullPrice(new QLabel(_fullPrice, this)),
                 fuelType(new QLabel(_fuelType, this)),
                 transmissionType(new QLabel(_transmissionType, this)),
                 power(new QLabel(_power, this)),
                 displacement(new QLabel(_displacement, this)),

                 conditioner(new QLabel(_conditioner, this)),
                 passengerNum(new QLabel(_passengerNum, this)),
                 pintleHook(new QLabel(_pintleHook, this)),
                 sensors(new QLabel(_sensors, this)),

                 stWagon(new QLabel(_stWagon, this)),
                 sunroof(new QLabel(_sunroof, this)),
                 luggagerack(new QLabel(_luggagerack, this))

{

    QVBoxLayout* mainLayout=new QVBoxLayout(this);
    mainLayout->setSpacing(2);

    QHBoxLayout* makeLayout=new QHBoxLayout();
    makeLayout->addWidget(new QLabel("Marca:", this));
    makeLayout->addWidget(make);
    mainLayout->addLayout(makeLayout);

    QHBoxLayout* modelLayout=new QHBoxLayout();
    modelLayout->addWidget(new QLabel("Modello:", this));
    modelLayout->addWidget(model);
    mainLayout->addLayout(modelLayout);

    QHBoxLayout* yearLayout=new QHBoxLayout();
    yearLayout->addWidget(new QLabel("Anno:", this));
    yearLayout->addWidget(registrationYear);
    mainLayout->addLayout(yearLayout);

    QHBoxLayout* mileageLayout=new QHBoxLayout();
    mileageLayout->addWidget(new QLabel("Km:", this));
    mileageLayout->addWidget(mileage);
    mainLayout->addLayout(mileageLayout);

    QHBoxLayout* priceLayout=new QHBoxLayout();
    priceLayout->addWidget(new QLabel("Prezzo:", this));
    priceLayout->addWidget(fullPrice);
    mainLayout->addLayout(priceLayout);

    QHBoxLayout* fuelTypeLayout=new QHBoxLayout();
    fuelTypeLayout->addWidget(new QLabel("Carburante:", this));
    fuelTypeLayout->addWidget(fuelType);
    mainLayout->addLayout(fuelTypeLayout);

    QHBoxLayout* transmissionTypeLayout=new QHBoxLayout();
    transmissionTypeLayout->addWidget(new QLabel("Trassmissione:", this));
    transmissionTypeLayout->addWidget(transmissionType);
    mainLayout->addLayout(transmissionTypeLayout);

    QHBoxLayout* powerLayout=new QHBoxLayout();
    powerLayout->addWidget(new QLabel("Potenza:", this));
    powerLayout->addWidget(power);
    mainLayout->addLayout(powerLayout);

    QHBoxLayout* displacementLayout=new QHBoxLayout();
    displacementLayout->addWidget(new QLabel("Cilindrarta:", this));
    displacementLayout->addWidget(displacement);
    mainLayout->addLayout(displacementLayout);

    QHBoxLayout* conditionerLayout=new QHBoxLayout();
    conditionerLayout->addWidget(new QLabel("Climatizzatore:", this));
    conditionerLayout->addWidget(conditioner);
    mainLayout->addLayout(conditionerLayout);

    QHBoxLayout* passengerNumLayout=new QHBoxLayout();
    passengerNumLayout->addWidget(new QLabel("Numero passeggeri:", this));
    passengerNumLayout->addWidget(passengerNum);
    mainLayout->addLayout(passengerNumLayout);

    QHBoxLayout* pintleHookLayout=new QHBoxLayout();
    pintleHookLayout->addWidget(new QLabel("Gancio traino:", this));
    pintleHookLayout->addWidget(pintleHook);
    mainLayout->addLayout(pintleHookLayout);

    QHBoxLayout* sensorsLayout=new QHBoxLayout();
    sensorsLayout->addWidget(new QLabel("Sensori parcheggio:", this));
    sensorsLayout->addWidget(sensors);
    mainLayout->addLayout(sensorsLayout);

    QHBoxLayout* stWagonLayout=new QHBoxLayout();
    stWagonLayout->addWidget(new QLabel("Station Wagon:", this));
    stWagonLayout->addWidget(stWagon);
    mainLayout->addLayout(stWagonLayout);

    QHBoxLayout* sunroofLayout=new QHBoxLayout();
    sunroofLayout->addWidget(new QLabel("Lunotto:", this));
    sunroofLayout->addWidget(sunroof);
    mainLayout->addLayout(sunroofLayout);

    QHBoxLayout* luggagerackLayout=new QHBoxLayout();
    luggagerackLayout->addWidget(new QLabel("Portapacchi:", this));
    luggagerackLayout->addWidget(luggagerack);
    mainLayout->addLayout(luggagerackLayout);
}
