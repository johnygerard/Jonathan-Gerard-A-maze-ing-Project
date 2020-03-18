#ifndef __MONSTER3_AGENT__H
#define __MONSTER3_AGENT__H 
#include <vector>
#include <tuple>
#include "enviro.h"

using namespace enviro;

class Monster3Controller : public Process, public AgentInterface {

    public:
    Monster3Controller() : Process(), AgentInterface() {}

    void init() {
        label(std::to_string(hp), 0,0);

    }
    void start() {}
    void update() {
        label(std::to_string(hp), -6,0);

        if (hp < 0) {
        remove_agent(id());
        }
        notice_collisions_with("Bullet", [&](Event &e) {
            hp--;
        }); 
        omni_move_toward(vect[idx%2],-100, 0.9);

        if (abs(x()-vect[idx%2]) < 0.05){

            idx++;

        }

    }
    
    void stop() {}
    private:
    int hp = 5;
    int idx = 0;
    std::vector<double> vect= {-250,0};

};

class Monster3 : public Agent {
    public:
    Monster3(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    Monster3Controller c;
};

DECLARE_INTERFACE(Monster3)

#endif