#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <assert.h>
#include <iostream>
#include <stdexcept>
#include <chrono>
#include <vector>
#include "elma/elma.h"
#include "my_robot.h"
#include "enviro.h"


//using namespace elma;
using namespace std::chrono;
//typedef duration<double,std::ratio<1,1>>seconds;

    

class Stopwatch {
    public:

    Stopwatch();

    void start();              // starts the timer
    void stop();               // stops the timer
    void reset();              // sets stopwatch to zero
    double get_minutes();      // number of minutes counted, as a double
    double get_seconds();      // number of seconds counted, as a double
    double get_milliseconds(); // number of milliseconds counted, as a double
    double get_nanoseconds();  // number of nanoseconds counted, as a double
    
    high_resolution_clock::duration value();//Get the time stored by the stopwatch

    private:
    bool flag;
    

    bool _running;
    high_resolution_clock::time_point _start_time;
    high_resolution_clock::duration _elapsed;
    
};



#endif