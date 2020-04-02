#ifndef WARRIORS_CPP
#define WARRIORS_CPP


#include "../include/warriors.h"
#include "../include/parameter.h"

warrior::warrior(bool ally, int level) :
    dead(false),
    should_go(false),
    current_health(0),
    max_health(0),
    speed(0),
    cost(0),
    bounty(0),
    attack_range(0),
    position(0),
    vision(0),
    ally(ally),
    level(level),
    damage(0) {
}

int warrior::update_health(int shift) {
    current_health += shift;
    if (current_health <= 0) {
        return die();
    }
    return 0;
}

int warrior::move() {
    position += speed;
}

int warrior::die() {
    dead = true;
    return bounty;
}

int warrior::attack(warrior* enemy) {
    return enemy->update_health(-damage);
}

int warrior::type() {
    return 0;
}

#endif /* WARRIORS_CPP */
