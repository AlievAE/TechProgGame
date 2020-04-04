#ifndef FIELD_CPP
#define FIELD_CPP

#include "../include/field.h"

#include "lancer.cpp"
#include "archer.cpp"
#include "cavalry_lancer.cpp"
#include "cavalry_archer.cpp"

Player::Player(bool ally) :
    ally(ally),
    gold(0),
    army(),
    barrack{0, 0, 0}
{
    gold = FP.BASE_GOLD;
}

bool Player::upgrade(int type) {
    if (barrack[type] < 2 && gold >= FP.BARRACK_COST[type][barrack[type]]) {
        gold -= FP.BARRACK_COST[type][barrack[type]];
        barrack[type]++;
        return true;
    }
    return false;
}

bool Player::create_unit(int type) {
    warrior* tmp = nullptr;
    if (type == 1) {
        if (gold >= UP.LANCER_COST[barrack[0]]) {
            gold -= UP.LANCER_COST[barrack[0]];
            tmp = new lancer(ally, barrack[0]);
            army.push_back(tmp);
            return true;
        }
        return false;
    }
    else if (type == 2) {
        if (gold >= UP.ARCHER_COST[barrack[1]]) {
            gold -= UP.ARCHER_COST[barrack[1]];
            tmp = new archer(ally, barrack[1]);
            army.push_back(tmp);
            return true;
        }
        return false;
    }
    else if (type == 3) {
        if (gold >= UP.CAVALRY_LANCER_COST[barrack[2]]) {
            gold -= UP.CAVALRY_LANCER_COST[barrack[2]];
            tmp = new cavalry_lancer(ally, barrack[2]);
            army.push_back(tmp);
            return true;
        }
        return false;
    }
    else if (type == 4) {
        if (gold >= UP.CAVALRY_ARCHER_COST[barrack[2]]) {
            gold -= UP.CAVALRY_ARCHER_COST[barrack[2]];
            tmp = new cavalry_archer(ally, barrack[2]);
            army.push_back(tmp);
            return true;
        }
        return false;
    }
}

Field::Field(int size) :
    size(size),
    player{new Player(0), new Player(1)} {
}

void Field::upgrade(int type, bool ally) {
    if (!player[static_cast<int>(ally)]->upgrade(type)) {
        std::cout << "can't upgrade\n";
    }
}

void Field::create_unit(int type, bool ally) {
    if (!player[static_cast<int>(ally)]->create_unit(type)) {
        std::cout << "can't create unit\n";
    }
}

#endif /* FIELD_CPP */
