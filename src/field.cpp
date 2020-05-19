#ifndef FIELD_CPP
#define FIELD_CPP

#include "../include/field.h"

#include "horde.cpp"

Player::Player(bool ally) :
    ally(ally),
    gold(0),
    army(),
    squads(),
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
    int index = std::min(type - 1, 2);
    int need = UP.COSTS[type - 1][barrack[index]];
    if (gold < need) {
        return false;
    }
    gold -= need;
    if (type == 1) {
        tmp = new lancer(ally, barrack[index]);
    }
    else if (type == 2) {
        tmp = new archer(ally, barrack[index]);
    }
    else if (type == 3) {
        tmp = new cavalry_lancer(ally, barrack[index]);
    }
    else if (type == 4) {
        tmp = new cavalry_archer(ally, barrack[index]);
    }
    army[type - 1].push_back(tmp);
    return true;
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

void Player::make_squad(int type) {
    auto new_squad = new Squad(type);
    bool flag = false;
    for (auto war : army[type - 1]) {
        new_squad->add(war);
        flag = true;
    }
    army[type - 1].clear();
    if (flag) {
        squads[type - 1].push_back(new_squad);
    }
}

void Player::make_horde(int type) {
    if (!army[type - 1].empty()) {
        make_squad(type);
    }
    auto new_horde = new Horde(type);
    bool flag = false;
    for (auto sq : squads[type - 1]) {
        new_horde->add(sq);
        flag = true;
    }
    squads[type - 1].clear();
    if (flag) {
        hordes.push_back(new_horde);
    }
}

void Player::buff(int index) {
    if (index > static_cast<int>(hordes.size())) {
        std::cout << "wrong index of horde\n";
        return;
    }
    if (hordes[index]->ready) {
        std::cout << "horde is fighting, no buff allowed\n";
        return;
    }
    int type = hordes[index]->type;
    int need = hordes[index]->get_size() * UP.BUFF_COST[type - 1];
    if (gold >= need) {
        gold -= need;
        hordes[index]->buff();
    }
}

#endif /* FIELD_CPP */
