#include "cavalry.cpp"
#include "../include/cavalry_archer.h"

cavalry_archer::cavalry_archer(bool ally, int level) :
    cavalry(ally, level),
    min_range(UP.CAVALRY_ARCHER_MIN_RANGE[level]),
    melee_damage(UP.CAVALRY_ARCHER_MELEE_DAMAGE[level]) {

    current_health = UP.CAVALRY_ARCHER_HEALTH[level];
    max_health = current_health;
    speed = UP.CAVALRY_ARCHER_SPEED[level];
    cost = UP.CAVALRY_ARCHER_COST[level];
    bounty = UP.CAVALRY_ARCHER_BOUNTY[level];
    attack_range = UP.CAVALRY_ARCHER_ATTACK_RANGE[level];
    vision = UP.CAVALRY_ARCHER_VISION[level];
    damage = UP.CAVALRY_ARCHER_DAMAGE[level];
}

int cavalry_archer::type() {
    return 5;
}

int cavalry_archer::attack(warrior* enemy) {
    int result = 0;
    if (abs(enemy->position - position) >= min_range) {
        result = enemy->update_health(-(damage + UP.CAVALRY_LANCER_BERSERK[streak]));
    }
    else {
        result = enemy->update_health(-(melee_damage + UP.CAVALRY_LANCER_BERSERK[streak]));
    }
    if (result > 0 && streak < 4) streak++;
    return result;
}
