#ifndef __MONSTER4_AGENT__H
#define __MONSTER4_AGENT__H 
#include <vector>
#include <tuple>
#include "enviro.h"

using namespace enviro;

class Monster4Controller : public Process, public AgentInterface {

    public:
    Monster4Controller() : Process(), AgentInterface() {}

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
        omni_move_toward(vect[idx%2],-40, 0.9);

        if (abs(x()-vect[idx%2]) < 0.05){

            idx++;

        }

    }
    
    void stop() {}
    private:
    int hp = 5;
    int idx = 0;
    std::vector<double> vect= {-200,0};

};

class Monster4 : public Agent {
    public:
    Monster4(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    Monster4Controller c;
};

DECLARE_INTERFACE(Monster4)

#endif