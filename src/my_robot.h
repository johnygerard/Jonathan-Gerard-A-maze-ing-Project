#ifndef __MY_ROBOT_AGENT__H
#define __MY_ROBOT_AGENT__H 
#include "enviro.h"
#include "styles.h"
#include <vector>



typedef std::chrono::high_resolution_clock Clock;


using namespace std::chrono;
using namespace std;
using namespace enviro;


///////// Class initialzes the robot/player ///////////////
class MyRobotController : public Process, public AgentInterface {

    public:
    MyRobotController() : Process(), AgentInterface(), v(0), omega(0), firing(false) {}

    void init() {
        ///////////// define W, A, S, D for player control //////////////
        watch("keydown", [&](Event &e) {
            auto k = e.value()["key"].get<std::string>();
            if ( k == " " && !firing ) {
                //////// initialize bullets //////////
                  Agent& bullet = add_agent("Bullet", 
                    x() + 17*cos(angle()), 
                    y() + 17*sin(angle()), 
                    angle(), 
                    BULLET_STYLE);    
                    bullet.apply_force(100,0);
                  firing = true;
            } else if ( k == "w" ) {
                  v = v_m;              
            } else if ( k == "s" ) {
                  v = -v_m;  
            } else if ( k == "a" ) {
                  omega = -omega_m;
            } else if ( k == "d" ) {
                  omega = omega_m;
            } 
        });   

        /////////// when no keys are pressed, each function is reseted back to zero ////////////     
        watch("keyup", [&](Event &e) {
            auto k = e.value()["key"].get<std::string>();
            if ( k == " " ) {
                firing = false;
            } else if ( k == "w" || k == "s" ) {
                  v = 0;               
            } else if ( k == "a" ) {
                  omega = 0;
            } else if ( k == "d" ) {
                  omega = 0;
            } 
        });
       
    }
    void start() { }
    void update() {
        ////////// velocity and turn angle definition /////////////
        track_velocity(v,omega,10,400);
        
    }
    void stop() {}

    double v, omega;
    ///////// sensitivty to movement /////////////
    double const v_m = 25, omega_m = 0.5;
    bool firing;
    

};
    

class MyRobot : public Agent {
    public:
    MyRobot(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    MyRobotController c;
    
};

DECLARE_INTERFACE(MyRobot)

#endif