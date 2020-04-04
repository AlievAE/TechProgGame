#include "cavalry.cpp"
#include "../include/cavalry_lancer.h"

cavalry_lancer::cavalry_lancer(bool ally, int level) :
    cavalry(ally, level) {

    current_health = UP.CAVALRY_LANCER_HEALTH[level];
    max_health = current_health;
    speed = UP.CAVALRY_LANCER_SPEED[level];
    cost = UP.CAVALRY_LANCER_COST[level];
    bounty = UP.CAVALRY_LANCER_BOUNTY[level];
    attack_range = UP.CAVALRY_LANCER_ATTACK_RANGE[level];
    vision = UP.CAVALRY_LANCER_VISION[level];
    damage = UP.CAVALRY_LANCER_DAMAGE[level];
}

int cavalry_lancer::type() {
    return 4;
}

int cavalry_lancer::attack(warrior* enemy) {
    int result = enemy->update_health(-(damage + UP.CAVALRY_LANCER_BERSERK[streak]));
    if (result > 0 && streak < 4) streak++;
    return result;
}
