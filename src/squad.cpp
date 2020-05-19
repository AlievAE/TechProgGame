#ifndef SQUAD_CPP
#define SQUAD_CPP

#include "../include/squad.h"

#include "lancer.cpp"
#include "archer.cpp"
#include "cavalry_lancer.cpp"
#include "cavalry_archer.cpp"

Squad::Squad(int type) :
    party({}),
    type(type),
    dead(false) {
}

Squad::Squad(warrior* war) :
    party({war}),
    type(war->type()),
    dead(false) {
}


void Squad::die() {
    dead = true;
}

bool Squad::is_dead() {
    return dead;
}

warrior* Squad::get_front() {
    return party.back();
}

void Squad::fix_squad() {
    while (!party.empty() && party.back()->dead) {
        party.pop_back();
    }
    if (party.empty()) {
        die();
    }
}

void Squad::add(warrior* new_war) {
    if (new_war->type() != type) {
        std::cout << "wrong unit type\n";
        return;
    }
    party.push_back(new_war);
}

int Squad::get_speed() {
    if (party.empty()) {
        std::cout << "empty squad has no speed\n";
        return 0;
    }
    return party[0]->speed;
}

void Squad::buff() {
    for (auto war : party) {
        war->buff();
    }
}

int Squad::get_size() {
    return static_cast<int>(party.size());
}

int Squad::attack(Squad* enemy) {
    int bounty = 0;
    for (auto war : party) {
        if (enemy->is_dead()) return bounty;
        bounty += war->attack(enemy->get_front());
        enemy->fix_squad();
    }
    return bounty;
}
#endif /* SQUAD.cpp */
