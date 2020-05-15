#ifndef HORDE_CPP
#define HORDE_CPP

#include "../include/horde.h"
#include "squad.cpp"

Horde::Horde(int type) :
    rgt({}),
    type(type),
    dead(false),
    ready(false) {
}

Horde::Horde(Squad* war) :
    rgt({war}),
    type(war->type),
    dead(false) {
}


void Horde::die() {
    dead = true;
}

bool Horde::is_dead() {
    return dead;
}

Squad* Horde::get_front() {
    return rgt.back();
}

int Horde::get_speed() {
    if (rgt.empty()) {
        std::cout << "empty horde has no speed\n";
        return 0;
    }
    return rgt[0]->get_speed();
}

void Horde::fix_horde() {
    while (!rgt.empty() && rgt.back()->dead) {
        rgt.pop_back();
    }
    if (rgt.empty()) {
        die();
    }
}

void Horde::add(Squad* new_squad) {
    if (new_squad->type != type) {
        std::cout << "wrong squad type\n";
        return;
    }
    rgt.push_back(new_squad);
}

void Horde::get_ready() {
    ready ^= 1;
}

void Horde::buff() {
    for (auto sq : rgt) {
        sq->buff();
    }
}

int Horde::get_size() {
    int res = 0;
    for (auto sq : rgt) {
        res += sq->get_size();
    }
}

int Horde::attack(Horde* enemy) {
    int bounty = 0;
    for (auto sq : rgt) {
        if (enemy->is_dead()) return bounty;
        bounty += sq->attack(enemy->get_front());
        enemy->fix_horde();
    }
    return bounty;
}
#endif /* HORDE.cpp */
