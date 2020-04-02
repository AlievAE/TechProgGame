#ifndef ARCHER_CPP
#define ARCHER_CPP


#include "warriors.cpp"
#include "../include/archer.h"

archer::archer(bool ally, int level) :
    warrior(ally, level),
    min_range(ARCHER_MIN_RANGE[level]),
    melee_damage(ARCHER_MELEE_DAMAGE[level]) {

    current_health = ARCHER_HEALTH[level];
    max_health = current_health;
    speed = ARCHER_SPEED[level];
    cost = ARCHER_COST[level];
    bounty = ARCHER_BOUNTY[level];
    attack_range = ARCHER_ATTACK_RANGE[level];
    vision = ARCHER_VISION[level];
    damage = ARCHER_DAMAGE[level];
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

