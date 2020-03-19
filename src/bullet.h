#ifndef __BULLET_AGENT__H
#define __BULLET_AGENT__H 

#include "enviro.h"

using namespace enviro;

////// This class initalizes the bullet and implements a remove agen that ilimunates the bullet once fired///////

class BulletController : public Process, public AgentInterface {

    public:
    BulletController() : Process(), AgentInterface(), counter(0) {}

    void init() {}

    void start() {}

    void update() {
        
        //////// counter that removes the bullet once activated by " "////////
        if ( counter++ > 10 ) {
            remove_agent(id());
        }
     }
    void stop() {}

    double counter;

};

class Bullet : public Agent {
    public:
    Bullet(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    BulletController c;
};

DECLARE_INTERFACE(Bullet)

#endif