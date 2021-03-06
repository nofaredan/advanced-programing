
#ifndef EX2_DRIVER_H
#define EX2_DRIVER_H

#include <iostream>
#include "Cab.h"
#include "Trip.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;
#include <fstream>
#include <sstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/assign/list_of.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/iostreams/device/back_inserter.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
using namespace boost::archive;

class Driver {

    friend class boost::serialization::access;
    template<class Archive>

    void serialize(Archive &ar, const unsigned int version){
        // attache to boost -

        ar & id;
        ar & age;
        ar & status;
        ar & yearsExperience;
        ar & avgSatisfaction;
        ar & cabId;
        ar & satisfaction;
        ar & customers;
        ar & cab;
        ar & currTrip;
        ar & currentPlace;
    }
private:
    int id;
    int age;
    char status;
    int yearsExperience;
    int avgSatisfaction;
    Cab* cab;
    int cabId;
    int satisfaction;
    int customers;
    Trip* currTrip;
    Point currentPlace;


public:
    Driver(){};
    Driver(int driverId, int driverAge, char driverStatus,int experience,
           int taxiId);
    ~Driver();
    Cab* getCab();
    int getCabId();
    void setCab(Cab* cab);
    void setCurrTrip(Trip* tripDriver);
    void move(Point* newPlace);
    int getId();
    Point getCurrentPlace();
    bool getHasTrip();
};


#endif //EX2_DRIVER_H
