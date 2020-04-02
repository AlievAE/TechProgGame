#include "warriors.cpp"
#include "../include/lancer.h"

lancer::lancer(bool ally, int level) :
    warrior(ally, level),
    shield(SHIELD[level]),
    is_defending(false) {

    current_health = LANCER_HEALTH[level];
    max_health = current_health;
    speed = LANCER_SPEED[level];
    cost = LANCER_COST[level];
    bounty = LANCER_BOUNTY[level];
    attack_range = LANCER_ATTACK_RANGE[level];
    vision = LANCER_VISION[level];
    damage = LANCER_DAMAGE[level];
}

int lancer::type() {
    return is_defending && shield > 0 ? 0 : 1;
}

void lancer::toss_shield() {
    shield = 0;
    is_defending = false;
    speed = LANCER_MARCH_SPEED[level];
}

void lancer::shield_up() {
    if (is_defending) return;
    is_defending = true;
    speed = LANCER_DEF_SPEED[level];
    damage = LANCER_DEF_DAMAGE[level];
    vision = LANCER_DEF_VISION[level];
}

void lancer::shield_down() {
    if (!is_defending) return;
    is_defending = false;
    speed = LANCER_SPEED[level];
    damage = LANCER_DAMAGE[level];
    vision = LANCER_VISION[level];
}
