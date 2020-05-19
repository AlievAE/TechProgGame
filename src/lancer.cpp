#include "warriors.cpp"
#include "../include/lancer.h"

lancer::lancer(bool ally, int level) :
    warrior(ally, level),
    shield(UP.SHIELD[level]),
    is_defending(false) {

    current_health = UP.LANCER_HEALTH[level];
    max_health = current_health;
    speed = UP.LANCER_SPEED[level];
    cost = UP.LANCER_COST[level];
    bounty = UP.LANCER_BOUNTY[level];
    attack_range = UP.LANCER_ATTACK_RANGE[level];
    vision = UP.LANCER_VISION[level];
    damage = UP.LANCER_DAMAGE[level];
}

int lancer::type() {
    return is_defending && shield > 0 ? 0 : 1;
}

void lancer::toss_shield() {
    shield = 0;
    is_defending = false;
    speed = UP.LANCER_MARCH_SPEED[level];
}

void lancer::shield_up() {
    if (is_defending) return;
    is_defending = true;
    speed = UP.LANCER_DEF_SPEED[level];
    damage = UP.LANCER_DEF_DAMAGE[level];
    vision = UP.LANCER_DEF_VISION[level];
}

void lancer::shield_down() {
    if (!is_defending) return;
    is_defending = false;
    speed = UP.LANCER_SPEED[level];
    damage = UP.LANCER_DAMAGE[level];
    vision = UP.LANCER_VISION[level];
}
