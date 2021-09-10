#ifndef ITEMCAR_H
#define ITEMCAR_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QString>


class ItemCar: public QWidget{
public:
    ItemCar(QString _make, QString _model, QString _registrationYear, QString _mileage, QString _fullPrice,
            QString _fuelType, QString _transmissionType, QString _power, QString _displacement,
            QString _conditioner, QString _passengerNum, QString _pintleHook, QString _sensors, QString _stWagon,
            QString _sunroof, QString _luggagerack, QWidget* parent=nullptr);

    QLabel* make;
    QLabel* model;
    QLabel* registrationYear;
    QLabel* mileage;
    QLabel* fullPrice;
    QLabel* fuelType;
    QLabel* transmissionType;
    QLabel* power;
    QLabel* displacement;

    QLabel* conditioner;
    QLabel* passengerNum;
    QLabel* pintleHook;
    QLabel* sensors;

    QLabel* stWagon;
    QLabel* sunroof;
    QLabel* luggagerack;

};

#endif // ITEMCAR_H
