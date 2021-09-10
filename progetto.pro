#-------------------------------------------------
#
# Project created by QtCreator 2021-09-08T17:48:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = progetto
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    hierarchy/Auto.cpp \
    hierarchy/Camper.cpp \
    hierarchy/Car.cpp \
    hierarchy/Moto.cpp \
    hierarchy/Truck.cpp \
    hierarchy/Vehicle.cpp \
    VehicleSearchResult/CamperSearchResult.cpp \
    VehicleSearchResult/CarSearchResult.cpp \
    VehicleSearchResult/MotoSearchResult.cpp \
    VehicleSearchResult/TruckSearchResult.cpp \
    VehicleSearchResult/VehicleSearchResult.cpp \
    view/search_result_dialogs/CamperSearchResultDialog.cpp \
    view/search_result_dialogs/CarSearchResultDialog.cpp \
    view/search_result_dialogs/MotoSearchResultDialog.cpp \
    view/search_result_dialogs/TruckSearchResultDialog.cpp \
    view/search_result_dialogs/VehicleSearchResultDialog.cpp \
    view/tabs_for_LayoutInsert/TabInsertCamper.cpp \
    view/tabs_for_LayoutInsert/TabInsertCar.cpp \
    view/tabs_for_LayoutInsert/TabInsertMoto.cpp \
    view/tabs_for_LayoutInsert/TabInsertTruck.cpp \
    view/tabs_for_LayoutSearch/TabSearchCamper.cpp \
    view/tabs_for_LayoutSearch/TabSearchCar.cpp \
    view/tabs_for_LayoutSearch/TabSearchMoto.cpp \
    view/tabs_for_LayoutSearch/TabSearchTruck.cpp \
    view/widget_items/ItemCamper.cpp \
    view/widget_items/ItemCar.cpp \
    view/widget_items/ItemMoto.cpp \
    view/widget_items/ItemTruck.cpp \
    Controller.cpp \
    main.cpp \
    Model.cpp \
    View.cpp

HEADERS += \
    hierarchy/Auto.h \
    hierarchy/Camper.h \
    hierarchy/Car.h \
    hierarchy/Moto.h \
    hierarchy/Truck.h \
    hierarchy/Vehicle.h \
    VehicleSearchResult/CamperSearchResult.h \
    VehicleSearchResult/CarSearchResult.h \
    VehicleSearchResult/MotoSearchResult.h \
    VehicleSearchResult/TruckSearchResult.h \
    VehicleSearchResult/VehicleSearchResult.h \
    view/search_result_dialogs/CamperSearchResultDialog.h \
    view/search_result_dialogs/CarSearchResultDialog.h \
    view/search_result_dialogs/MotoSearchResultDialog.h \
    view/search_result_dialogs/TruckSearchResultDialog.h \
    view/search_result_dialogs/VehicleSearchResultDialog.h \
    view/tabs_for_LayoutInsert/TabInsertCamper.h \
    view/tabs_for_LayoutInsert/TabInsertCar.h \
    view/tabs_for_LayoutInsert/TabInsertMoto.h \
    view/tabs_for_LayoutInsert/TabInsertTruck.h \
    view/tabs_for_LayoutSearch/TabSearchCamper.h \
    view/tabs_for_LayoutSearch/TabSearchCar.h \
    view/tabs_for_LayoutSearch/TabSearchMoto.h \
    view/tabs_for_LayoutSearch/TabSearchTruck.h \
    view/widget_items/ItemCamper.h \
    view/widget_items/ItemCar.h \
    view/widget_items/ItemMoto.h \
    view/widget_items/ItemTruck.h \
    Container.h \
    Controller.h \
    DeepPtr.h \
    loadData.h \
    Model.h \
    View.h
