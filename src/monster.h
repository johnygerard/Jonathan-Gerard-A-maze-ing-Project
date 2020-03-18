#ifndef __MONSTER_AGENT__H
#define __MONSTER_AGENT__H 
#include <vector>
#include <tuple>
#include "enviro.h"

using namespace enviro;

class MonsterController : public Process, public AgentInterface {

    public:
    MonsterController() : Process(), AgentInterface() {}

    void init() {
        label(std::to_string(hp), 0,0);

    }
    void start() {}
    void update() {
        label(std::to_string(hp), 0,0);

        if (hp < 0) {
        remove_agent(id());
        }
        notice_collisions_with("Bullet", [&](Event &e) {
            hp--;
        }); 
        omni_move_toward(vect[idx%2],20, 0.9);

        if (abs(x()-vect[idx%2]) < 0.05){

            idx++;

        }

    }
    
    void stop() {}
    private:
    int hp = 5;
    int idx = 0;
    std::vector<double> vect= {-40,40};

};

class Monster : public Agent {
    public:
    Monster(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    MonsterController c;
};

DECLARE_INTERFACE(Monster)

#endif