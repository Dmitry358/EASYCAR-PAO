#include <QApplication>

#include "View.h"
#include "Controller.h"
#include "Container.h"
#include "DeepPtr.h"
#include "hierarchy/Vehicle.h"
#include "Model.h"

#include "loadData.h"


int main(int argc, char *argv[]){

    QApplication a(argc, argv);

    View view;
    Controller controlller;
    Model model;

    view.setController(&controlller);
    controlller.setView(&view);
    controlller.setModel(&model);


    loadVehicles(model);


    view.show();

    return a.exec();
}
