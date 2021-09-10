#ifndef ITEMMOTO_H
#define ITEMMOTO_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QString>


class ItemMoto: public QWidget{
public:
    ItemMoto(QString _make, QString _model, QString _registrationYear, QString _mileage, QString _fullPrice,
             QString _fuelType, QString _transmissionType, QString _power, QString _displacement, QString _sidecar,
             QString _engineProtection, QWidget* parent=nullptr);
    QPixmap* image;
    QLabel* make;
    QLabel* model;
    QLabel* registrationYear;
    QLabel* mileage;
    QLabel* fullPrice;
    QLabel* fuelType;
    QLabel* transmissionType;
    QLabel* power;
    QLabel* displacement;

    QLabel* sidecar;
    QLabel* engineProtection;
};

#endif // ITEMMOTO_H