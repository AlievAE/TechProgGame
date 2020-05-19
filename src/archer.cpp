#ifndef ARCHER_CPP
#define ARCHER_CPP


#include "warriors.cpp"
#include "../include/archer.h"

archer::archer(bool ally, int level) :
    warrior(ally, level),
    min_range(UP.ARCHER_MIN_RANGE[level]),
    melee_damage(UP.ARCHER_MELEE_DAMAGE[level]) {

    current_health = UP.ARCHER_HEALTH[level];
    max_health = current_health;
    speed = UP.ARCHER_SPEED[level];
    cost = UP.ARCHER_COST[level];
    bounty = UP.ARCHER_BOUNTY[level];
    attack_range = UP.ARCHER_ATTACK_RANGE[level];
    vision = UP.ARCHER_VISION[level];
    damage = UP.ARCHER_DAMAGE[level];
}

int archer::type() {
    return 2;
}

int archer::attack(warrior* enemy) {
    if (abs(enemy->position - position) >= min_range) {
        return enemy->update_health(-damage);
    }
    else {
        return enemy->update_health(-melee_damage);
    }
}

#endif /* ARCHER_CPP */

