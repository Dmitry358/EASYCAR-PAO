#ifndef ITEMTRUCK_H
#define ITEMTRUCK_H

#include<QWidget>
#include<QVBoxLayout>
#include<QLabel>
#include<QString>


class ItemTruck: public QWidget{
public:
    ItemTruck(QString _make, QString _model, QString _registrationYear, QString _mileage, QString _fullPrice,
              QString _fuelType, QString _transmissionType, QString _power, QString _displacement,
              QString _maxLoadability, QString _sleepingPlace, QString _dangerousGood, QWidget* parent=nullptr);

    QLabel* make;
    QLabel* model;
    QLabel* registrationYear;
    QLabel* mileage;
    QLabel* fullPrice;
    QLabel* fuelType;
    QLabel* transmissionType;
    QLabel* power;
    QLabel* displacement;

    QLabel* maxLoadability;
    QLabel* sleepingPlace;
    QLabel* dangerousGood;
};

#endif // ITEMTRUCK_H
