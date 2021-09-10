#include "Controller.h"


Controller::Controller(QObject* parent): QObject(parent){}

void Controller::setView(View* _view){ view=_view; }

void Controller::setModel(Model* _model){ model=_model; }



void Controller::insertNewVehicle() const {
    try{
        Vehicle* tmp = view->returnVechicleForInsert();
        model->insertNewVehicle(tmp);
        view->showInsertConfirm();
    }
    catch(std::runtime_error err){
        view->showWarning(err.what());
    }
}



void Controller::searchMoto() const {
    try{
        MotoSearchResult* values = view->returnMotoForSearch();

        vector<pair<Moto, unsigned int>>* result = model->searchMoto(values);

        if(result==nullptr) throw std::runtime_error("Non sono stati trovati i veicoli con parametri richiesti");

        else view->showSearchedMotoResultDialog(result);
    }

    catch(std::runtime_error exc){
        view->showWarning(exc.what());
    }    
}

void Controller::searchCar() const {
    try{
        CarSearchResult* values = view->returnCarForSearch();

        vector<pair<Car, unsigned int>>* result = model->searchCar(values);

        if(result==nullptr) throw std::runtime_error("Non sono stati trovati i veicoli con parametri richiesti");

        else view->showSearchedCarResultDialog(result);
    }

    catch(std::runtime_error exc){
        view->showWarning(exc.what());
    }
}

void Controller::searchCamper() const {
    try{
        CamperSearchResult* values = view->returnCamperForSearch();

        vector<pair<Camper, unsigned int>>* result = model->searchCamper(values);

        if(result==nullptr) throw std::runtime_error("Non sono stati trovati i veicoli con parametri richiesti");

        else view->showSearchedCamperResultDialog(result);
    }

    catch(std::runtime_error exc){
        view->showWarning(exc.what());
    }
}

void Controller::searchTruck() const {
    try{
        TruckSearchResult* values = view->returnTruckForSearch();

        vector<pair<Truck, unsigned int>>* result = model->searchTruck(values);

        if(result==nullptr) throw std::runtime_error("Non sono stati trovati i veicoli con parametri richiesti");

        else view->showSearchedTruckResultDialog(result);
    }

    catch(std::runtime_error exc){
        view->showWarning(exc.what());
    }
}



void Controller::showAllMoto() const {
    vector<pair<Moto, unsigned int>>* result = model->showAllMoto();

    if(result==nullptr) view->showWarning ("Nessun veicolo trovato");

    else view->showSearchedMotoResultDialog(result);
}

void Controller::showAllCar() const {
    vector<pair<Car, unsigned int>>* result = model->showAllCar();

    if(result==nullptr) view->showWarning ("Nessun veicolo trovato");

    else view->showSearchedCarResultDialog(result);
}

void Controller::showAllCamper() const {
    vector<pair<Camper, unsigned int>>* result = model->showAllCamper();

    if(result==nullptr) view->showWarning ("Nessun veicolo trovato");

    else view->showSearchedCamperResultDialog(result);
}

void Controller::showAllTruck() const {
    vector<pair<Truck, unsigned int>>* result = model->showAllTruck();

    if(result==nullptr) view->showWarning ("Nessun veicolo trovato");

    else view->showSearchedTruckResultDialog(result);
}

void Controller::removeVehicle() const {
    try{
        unsigned int ix=view->returnVehicleForRemoveIndex();
        if(model->removeVehicle(ix)){
            view->updateSearchResultDialog();
            view->showRemoveVehicleConfirm();
        }

        else throw std::runtime_error ("Errore, veicolo non è stato rimosso");
    }

    catch(std::runtime_error exc){
        view->showWarning(exc.what());
    }
}


