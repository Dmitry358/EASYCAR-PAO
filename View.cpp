#include "View.h"
#include "Controller.h"
#include "view/search_result_dialogs/VehicleSearchResultDialog.h"
#include "view/search_result_dialogs/MotoSearchResultDialog.h"
#include "view/search_result_dialogs/CarSearchResultDialog.h"
#include "view/search_result_dialogs/CamperSearchResultDialog.h"
#include "view/search_result_dialogs/TruckSearchResultDialog.h"
#include <QApplication>
#include <QDesktopWidget>


void View::setController(Controller* _controller){
    controller=_controller;
}

View::View(QWidget *parent): QWidget(parent),
                             labelInsert(new QLabel("ISERISCI NUOVO VEICOLO",this)),
                             tabInsert(new QTabWidget(this)),
                             buttonInsert(new QPushButton(tr("INSERISCI"), this)),

                             labelSearch(new QLabel(tr("RICERCA VEICOLO"),this)),
                             tabSearch(new QTabWidget(this)),
                             buttonSearch(new QPushButton(tr("CERCA"), this)),

                             searchResultDialog(nullptr)

{
    QVBoxLayout* layoutMain=new QVBoxLayout;

    addMenuBar(layoutMain);
    addLayoutInsert(layoutMain);
    addLayoutSearch(layoutMain);

    showSearchLayout();

    layoutMain->setSpacing(0);
    layoutMain->setContentsMargins(10,10,10,10);
    setLayout(layoutMain);

    layoutMain->setAlignment(Qt::AlignTop);

    resize(QSize(700, 600));
    move(QApplication::desktop()->screen()->rect().center() - rect().center());

    connect(buttonInsert, SIGNAL(clicked()), this, SLOT(insertNewVehicle()));
    connect(buttonSearch, SIGNAL(clicked()), this, SLOT(searchVehicles()));

    connect(menuView->actions()[0], SIGNAL(triggered()), this, SLOT(showAllMoto()));
    connect(menuView->actions()[1], SIGNAL(triggered()), this, SLOT(showAllCar()));
    connect(menuView->actions()[2], SIGNAL(triggered()), this, SLOT(showAllCamper()));
    connect(menuView->actions()[3], SIGNAL(triggered()), this, SLOT(showAllTruck()));
    connect(menuSearch, SIGNAL(triggered()), this, SLOT(showSearchLayout()));
    connect(menuInsert, SIGNAL(triggered()), this, SLOT(showInsertLayout()));
}


void View::addMenuBar(QVBoxLayout* mainLayout){
    QMenuBar* menuBar=new QMenuBar(this);

    menuFile=new QMenu("File", menuBar);

    menuInsert=new QAction("Inserimento", menuBar);

    menuSearch=new QAction("Ricerca", menuBar);

    menuView=new QMenu("Visualizza", menuBar);

    menuClear=new QAction("Pulisci", menuBar);

    menuFile->addAction(new QAction("Chiudi app", menuView));

    menuView->addAction(new QAction("Moto", menuView));
    menuView->addAction(new QAction("Auto", menuView));
    menuView->addAction(new QAction("Camper", menuView));
    menuView->addAction(new QAction("Camion", menuView));

    menuBar->addMenu(menuFile);
    menuBar->addAction(menuInsert);
    menuBar->addAction(menuSearch);
    menuBar->addMenu(menuView);
    menuBar->addAction(menuClear);

    mainLayout->setAlignment(menuBar, Qt::AlignTop);
    mainLayout->addWidget(menuBar);

    connect(menuFile->actions()[0], SIGNAL(triggered()), this, SLOT(close()));
    connect(menuClear, SIGNAL(triggered()), this, SLOT(clearAllFields()));    
}

void View::addLayoutInsert(QVBoxLayout *layoutMain) const{
    QVBoxLayout* layoutTabInsert=new QVBoxLayout;
    QHBoxLayout* layoutButtonInsert=new QHBoxLayout;

    labelInsert->setAlignment(Qt::AlignCenter);
    labelInsert->setMinimumHeight(50);
    layoutTabInsert->addWidget(labelInsert);


    tabInsert->insertTab(0, new TabInsertMoto(tabInsert), "MOTO");
    tabInsert->insertTab(1, new TabInsertCar(tabInsert), "AUTO");
    tabInsert->insertTab(2, new TabInsertCamper(tabInsert), "CAMPER");
    tabInsert->insertTab(3, new TabInsertTruck(tabInsert), "TRUCK");
    tabInsert->setMovable(true);
    tabInsert->setTabPosition(QTabWidget::West);
    layoutTabInsert->addWidget(tabInsert);

    buttonInsert->setMinimumSize(110,40);

    layoutButtonInsert->addWidget(buttonInsert);
    layoutButtonInsert->setAlignment(buttonInsert, Qt::AlignRight|Qt::AlignBottom);
    layoutButtonInsert->setContentsMargins(11,13,50,0);

    layoutMain->addLayout(layoutTabInsert);
    layoutMain->addLayout(layoutButtonInsert);
}

void View::addLayoutSearch(QVBoxLayout* layoutMain) const {
    QVBoxLayout* layoutTabSearch=new QVBoxLayout;
    QHBoxLayout* layoutButtonSearch=new QHBoxLayout;

    labelSearch->setAlignment(Qt::AlignCenter);
    labelSearch->setMinimumHeight(35);
    layoutTabSearch->addWidget(labelSearch);

    tabSearch->insertTab(0, new TabSearchMoto(tabSearch), "MOTO");
    tabSearch->insertTab(1, new TabSearchCar(tabSearch), "AUTO");
    tabSearch->insertTab(2, new TabSearchCamper(tabSearch), "CAMPER");
    tabSearch->insertTab(3, new TabSearchTruck(tabSearch), "TRUCK");
    tabSearch->setMovable(true);
    tabSearch->setTabPosition(QTabWidget::West);
    layoutTabSearch->addWidget(tabSearch);

    buttonSearch->setMinimumSize(110,40);

    layoutButtonSearch->addWidget(buttonSearch);
    layoutButtonSearch->setAlignment(buttonSearch, Qt::AlignRight);
    layoutButtonSearch->setContentsMargins(11,13,50,0);

    layoutMain->addLayout(layoutTabSearch);
    layoutMain->addLayout(layoutButtonSearch);
}

void View::showSearchLayout() {
    labelInsert->hide();
    tabInsert->hide();
    buttonInsert->hide();

    labelSearch->show();
    tabSearch->show();
    buttonSearch->show();

    setWindowTitle("CERCA VEICOLO");
}

void View::showInsertLayout()  {
    labelSearch->hide();
    tabSearch->hide();
    buttonSearch->hide();

    labelInsert->show();
    tabInsert->show();
    buttonInsert->show();

    setWindowTitle("INSERISCI NUOVO VEICOLO");
}

int View::tabCurrentIndex() const {
    if(tabInsert->isVisible()) return tabInsert->currentIndex();
    if(tabSearch->isVisible()) return tabSearch->currentIndex();
    else return -1;
}



void View::insertNewVehicle() const { controller->insertNewVehicle(); }

Vehicle* View::returnVechicleForInsert() const {
    Vehicle* tmp=nullptr;
    if(tabInsert->currentIndex()==0) tmp = dynamic_cast<TabInsertMoto*>(tabInsert->currentWidget())->returnVehicleForInsert();
    if(tabInsert->currentIndex()==1) tmp = dynamic_cast<TabInsertCar*>(tabInsert->currentWidget())->returnVehicleForInsert();
    if(tabInsert->currentIndex()==2) tmp = dynamic_cast<TabInsertCamper*>(tabInsert->currentWidget())->returnVehicleForInsert();
    if(tabInsert->currentIndex()==3) tmp = dynamic_cast<TabInsertTruck*>(tabInsert->currentWidget())->returnVehicleForInsert();

    if(tmp==nullptr) throw std::runtime_error("Non tutti campi sono compilati");

    else return tmp;
}

void View::showInsertConfirm(){
    QMessageBox* confirm=new QMessageBox(this);

    confirm->setText("Veicolo è stato aggiunto");
    confirm->setBaseSize(220, 200);
    confirm->exec();
}



MotoSearchResult* View::returnMotoForSearch() const {

    MotoSearchResult* tmp=(dynamic_cast<TabSearchMoto*>(tabSearch->currentWidget()))->getMotoSearchValues();

    if(tmp==nullptr) throw std::runtime_error("Non tutti campi sono compilati correttamente");

    else return tmp;
}

CarSearchResult* View::returnCarForSearch() const {

    CarSearchResult* tmp=(dynamic_cast<TabSearchCar*>(tabSearch->currentWidget()))->getCarSearchValues();

    if(tmp==nullptr) throw std::runtime_error("Non tutti campi sono compilati correttamente");

    else return tmp;
}

CamperSearchResult* View::returnCamperForSearch() const {

    CamperSearchResult* tmp=(dynamic_cast<TabSearchCamper*>(tabSearch->currentWidget()))->getCamperSearchValues();

    if(tmp==nullptr) throw std::runtime_error("Non tutti campi sono compilati correttamente");

    else return tmp;
}

TruckSearchResult* View::returnTruckForSearch() const {

    TruckSearchResult* tmp=(dynamic_cast<TabSearchTruck*>(tabSearch->currentWidget()))->getTruckSearchValues();

    if(tmp==nullptr) throw std::runtime_error("Non tutti campi sono compilati correttamente");

    else return tmp;
}

void View::searchVehicles() const {
    if(tabSearch->currentIndex()==0) controller->searchMoto();
    if(tabSearch->currentIndex()==1) controller->searchCar();
    if(tabSearch->currentIndex()==2) controller->searchCamper();
    if(tabSearch->currentIndex()==3) controller->searchTruck();
}

void View::showAllMoto() const { controller->showAllMoto(); }

void View::showAllCar() const { controller->showAllCar(); }

void View::showAllCamper() const { controller->showAllCamper(); }

void View::showAllTruck() const { controller->showAllTruck(); }

void View::showSearchedMotoResultDialog(vector<pair<Moto, unsigned int>>* _result) {
    searchResultDialog=new MotoSearchResultDialog(_result, this);
}

void View::showSearchedCarResultDialog(vector<pair<Car, unsigned int>>* _result){
    searchResultDialog=new CarSearchResultDialog(_result, this);
}

void View::showSearchedCamperResultDialog(vector<pair<Camper, unsigned int>>* _result){
    searchResultDialog=new CamperSearchResultDialog(_result, this);
}

void View::showSearchedTruckResultDialog(vector<pair<Truck, unsigned int>>* _result){
    searchResultDialog=new TruckSearchResultDialog(_result, this);
}

void View::updateSearchResultDialog() const { searchResultDialog->updateSearchResultDialog(); }



void View::removeVehicle() const { controller->removeVehicle(); }

unsigned int View::returnVehicleForRemoveIndex() const {
    try{
        return searchResultDialog->returnVehicleForRemoveIndex();
    }

    catch(std::runtime_error exc){ throw exc; }
}

void View::showRemoveVehicleConfirm() {
    QDialog* dialog=new QDialog(searchResultDialog);
    QVBoxLayout* mainLayout= new QVBoxLayout;
    dialog->setLayout(mainLayout);

    mainLayout->addWidget(new QLabel(QString::fromStdString("Veicolo è stato rimosso"), searchResultDialog));
    mainLayout->setAlignment(Qt::AlignCenter);
    dialog->setMinimumHeight(120);
    dialog->setMinimumWidth(320);

    dialog->show();
}



void View::clearAllFields() const {
    if(tabInsert->isVisible()){
        if(tabCurrentIndex()==0) (dynamic_cast<TabInsertMoto*>(tabInsert->currentWidget()))->clearAllFields();
        if(tabCurrentIndex()==1) (dynamic_cast<TabInsertCar*>(tabInsert->currentWidget()))->clearAllFields();
        if(tabCurrentIndex()==2) (dynamic_cast<TabInsertCamper*>(tabInsert->currentWidget()))->clearAllFields();
        if(tabCurrentIndex()==3) (dynamic_cast<TabInsertTruck*>(tabInsert->currentWidget()))->clearAllFields();
    }

    if(tabSearch->isVisible()){
        if(tabCurrentIndex()==0) (dynamic_cast<TabSearchMoto*>(tabSearch->currentWidget()))->clearAllFields();
        if(tabCurrentIndex()==1) (dynamic_cast<TabSearchCar*>(tabSearch->currentWidget()))->clearAllFields();
        if(tabCurrentIndex()==2) (dynamic_cast<TabSearchCamper*>(tabSearch->currentWidget()))->clearAllFields();
        if(tabCurrentIndex()==3) (dynamic_cast<TabSearchTruck*>(tabSearch->currentWidget()))->clearAllFields();
    }
}

void View::showWarning(string str) {
    QDialog* dialog=new QDialog(this);
    QVBoxLayout* mainLayout= new QVBoxLayout;
    dialog->setLayout(mainLayout);

    mainLayout->addWidget(new QLabel(QString::fromStdString(str), dialog));
    mainLayout->setAlignment(Qt::AlignCenter);
    dialog->setMinimumHeight(120);

    dialog->show();
}

void View::closeSearchResultDialog(){
    delete searchResultDialog;
    searchResultDialog=nullptr;
}

