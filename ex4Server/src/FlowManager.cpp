#include "FlowManager.h"

/**
 * The constructor
 */
FlowManager::FlowManager() {
    taxiCenter = new TaxiCenter();
}

/**
 * Add a new driver.
 * Get an input and add the driver to taxi center.
 */
void FlowManager::addDriver() {

    int numDrivers;
    cin >> numDrivers;
    for(int i=0; i<numDrivers; i++){

    }

 /*   int id, age, experience, cabId;
    char status, buffer;
    // get an input from the user:
    cin >> id >> buffer >> age >> buffer >> status >> buffer >> experience >> buffer >> cabId;
    // add a driver
    taxiCenter->addDriver(new Driver(id, age, status, experience, cabId, map));*/
}

/**
 * add a taxi
 */
void FlowManager::addTaxi() {
    int id, taxiType;
    char manufactor, color, buffer;
    // get an input from the user
    cin >> id >> buffer >> taxiType >> buffer >> manufactor >> buffer >> color;

    // create a taxi according to the input
    if (taxiType == 1) {
        taxiCenter->addCab(new Cab(id, manufactor, color));
    } else {
        taxiCenter->addCab(new LuxuryCab(id, manufactor, color));
    }
}

/**
 *
 * @return the taxi center
 */
TaxiCenter *FlowManager::getTaxiCenter() {
    return taxiCenter;
}

/**
 * add a trip
 */
void FlowManager::addTrip() {
    int id, startX, startY, endX, endY, numPassengers;
    double tariff;
    char buffer;
    // get an input from the user:
    cin >> id >> buffer >> startX >> buffer >> startY >> buffer >>
        endX >> buffer >> endY >> buffer >> numPassengers >> buffer >> tariff;
    // create a new trip
    Trip *trip = new Trip(id, Point(startX, startY), Point(endX, endY), numPassengers, tariff);
    // send the trip to taxi center
    taxiCenter->answerCall(trip);
}

/**
 * start driving.
 */
void FlowManager::startDriving() {
    taxiCenter->startDriving();
}

/**
 * initialize the map.
 */
void FlowManager::initializeMap() {
    int numObstacles;
    char buffer;
    int x, y;
    int sizeX, sizeY;
    vector<Point> obstacles;

    // size grid
    cin >> sizeX >> sizeY;

    // create a grid node array
    arrGridNode = new GridNode **[sizeY];

    // get the number of obstacles
    cin >> numObstacles;
    // get the obstacles
    for (int i = 0; i < numObstacles; i++) {
        cin >> x >> buffer >> y;
        obstacles.push_back(Point(x, y));
    }

    // create a new map
    map = new Map(sizeX, sizeY, &obstacles, arrGridNode);
}

/**
 * Get the driver's place
 */
void FlowManager::getDriverPlace() {
    int driverId;
    Point currentPlace;
    // get the driver's id
    cin >> driverId;
    // get the current place of the driver
    currentPlace = taxiCenter->getDriverPlace(driverId);
    // print the current place of the driver:
    printf("(%d,%d)\n", currentPlace.getX(), currentPlace.getY());
}

/**
 * destructor.
 */
FlowManager::~FlowManager() {
    if(map != NULL) {
        delete map;
    }
    if(taxiCenter != NULL) {
        delete taxiCenter;
    }
}