#include "CarSearchResultDialog.h"

CarSearchResultDialog::CarSearchResultDialog(vector<pair<Car, unsigned int>>* _result, View* _view, QWidget* _parent):
                                               VehicleSearchResultDialog(_parent),
                                               view(_view),
                                               result(_result),
                                               buttonClose(new QPushButton(tr("Chiudi"), this)),
                                               buttonDelete(new QPushButton(tr("Elimina"), this))

{
    setModal(true);
    setMinimumSize(400,500);
    resize(600,400);

    QVBoxLayout* mainLayout=new QVBoxLayout(this);
    QHBoxLayout* layoutButtons=new QHBoxLayout;
    mainLayout->setContentsMargins(5,5,5,0);

    searchList=new QListWidget(this);
    searchList->setGeometry(100,100,600,600);

    buttonDelete->setMinimumSize(100,40);
    buttonDelete->setMaximumSize(100,40);

    buttonClose->setMinimumSize(100,40);
    buttonClose->setMaximumSize(100,40);

    mainLayout->addWidget(searchList);
    layoutButtons->addWidget(buttonDelete);
    layoutButtons->addWidget(buttonClose);
    layoutButtons->setAlignment(buttonDelete, Qt::AlignLeft);
    layoutButtons->setAlignment(buttonClose, Qt::AlignRight);
    layoutButtons->setContentsMargins(35,5,35,15);

    mainLayout->addLayout(layoutButtons);
    setWindowTitle("AUTO DISPONIBILI");

    int i=0;
    for(auto it=result->begin(); it !=result->end(); ++it){

        ItemCar* itemCar=new ItemCar(QString::fromStdString(it->first.getMake()),
                                     QString::fromStdString(it->first.getModel()),
                                     QString::number(it->first.getRegistrationYear()),
                                     QString::number(it->first.getMileage()),
                                     QString::number(it->first.getBasePrice()),
                                     QString::fromStdString(it->first.getFuelTypeStr()),
                                     QString::fromStdString(it->first.getTransmissionTypeStr()),
                                     QString::number(it->first.getPower()),
                                     QString::number(it->first.getDisplacement()),

                                     QString::fromStdString(it->first.getConditioner() ? "Si" : "No"),
                                     QString::number(it->first.getPassengerNum()),
                                     QString::fromStdString(it->first.getPintleHook() ? "Si" : "No"),
                                     QString::fromStdString(it->first.getSensors() ? "Si" : "No"),

                                     QString::fromStdString(it->first.getStWagon() ? "Si" : "No"),
                                     QString::fromStdString(it->first.getSunroof() ? "Si" : "No"),
                                     QString::fromStdString(it->first.getLuggagerack() ? "Si" : "No"),
                                     searchList);

        QListWidgetItem* lwi=new QListWidgetItem(searchList);
        lwi->setSizeHint(itemCar->sizeHint());
        searchList->setItemWidget(lwi, itemCar);
        searchList->addItem(lwi);

        ++i;
    }

    connect(buttonDelete, SIGNAL(clicked()), this , SLOT(removeVehicle()));
    connect(buttonClose, SIGNAL(clicked()), this , SLOT(removeDialog()));

    show();
}

void CarSearchResultDialog::removeVehicle() const {
    view->removeVehicle();
}

void CarSearchResultDialog::removeDialog() const {
    searchList->close();
    delete result;
    view->closeSearchResultDialog();
}

unsigned int CarSearchResultDialog::returnVehicleForRemoveIndex() const {
    if(searchList->count()>0){
        int ix = searchList->currentRow();

        if (ix<0)  throw std::runtime_error("Non è stato selezionato nessun veicolo");

        else{
            auto it = result->begin() + ix;
            return (*it).second;
        }
    }

    else throw std::runtime_error("Non ci sono veicoli da eliminare");
}

void CarSearchResultDialog::updateSearchResultDialog() const {

    if(searchList->count()>0){
        unsigned int ix = searchList->currentRow();

        auto it = result->begin() + ix;
        it = result->erase(it);

        for(; it != result->end(); ++it) --((*it).second);

        auto removePtr = searchList->takeItem(ix);

        delete removePtr;

        if(searchList->count() <= 0) buttonDelete->setEnabled(false);
    }
}