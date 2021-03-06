#ifndef __MONSTER2_AGENT__H
#define __MONSTER2_AGENT__H 
#include <vector>
#include <tuple>
#include "enviro.h"

using namespace enviro;

////////// This class initializes the First monster closest to the player ////////////
class Monster2Controller : public Process, public AgentInterface {

    public:
    Monster2Controller() : Process(), AgentInterface() {}

    void init() {
        /////// Initial label for Health Ponts (HP) ///////////////
        label(std::to_string(hp), 0,0);

    }
    void start() {}
    void update() {

        //////// Dispositons HP location from origin ///////////
        label(std::to_string(hp), -6,0);

        //////// conditional statement to check collison of Bullets ///////
        //////// If true, it decrements defined HP level ////////// 
        if (hp < 0) {
        remove_agent(id());
        }
        notice_collisions_with("Bullet", [&](Event &e) {
            hp--;
        }); 

        ////// Dispositions monster and moves from defined location ///////
        omni_move_toward(vect[idx%2],-160, 0.9);

        ////// condition for monsters disposition ////////
        if (abs(x()-vect[idx%2]) < 0.05){

            idx++;

        }

    }
    
    void stop() {}
    private:
    int hp = 5;
    int idx = 0;
    std::vector<double> vect= {-40,60};

};

class Monster2 : public Agent {
    public:
    Monster2(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    Monster2Controller c;
};

DECLARE_INTERFACE(Monster2)

#endif