#ifndef ITEMCAMPER_H
#define ITEMCAMPER_H

#include<QWidget>
#include<QVBoxLayout>
#include<QLabel>
#include<QString>

class ItemCamper: public QWidget{
public:
    ItemCamper(QString _make, QString _model, QString _registrationYear, QString _mileage, QString _fullPrice,
               QString _fuelType, QString _transmissionType, QString _power, QString _displacement,
               QString _conditioner, QString _passengerNum, QString _pintleHook, QString _sensors, QString _sleepingPlaces,
               QString _toilet, QString _kitchen, QWidget* parent=nullptr);

    QLabel* make;
    QLabel* model;
    QLabel* registrationYear;
    QLabel* mileage;
    QLabel* fullPrice;
    QLabel* fuelType;
    QLabel* transmissionType;
    QLabel* power;
    QLabel* displacement;
    QLabel* description;
    QLabel* conditioner;
    QLabel* passengerNum;
    QLabel* pintleHook;
    QLabel* sensors;
    QLabel* sleepingPlaces;
    QLabel* toilet;
    QLabel* kitchen;
};

#endif // ITEMCAMPER_H
