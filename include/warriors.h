#ifndef WARRIORS_H
#define WARRIORS_H

#include<bits/stdc++.h>

class warrior {
public:
    bool dead;
    bool should_go;
    int current_health;
    int max_health;
    int speed;
    int cost;
    int bounty;
    int attack_range;
    int position;
    int vision;
    bool ally;
    int level;
    int damage;

    warrior(bool ally, int level);

    virtual int type();

    int die();
    int update_health(int);
    int move();
    virtual int attack(warrior*);

    ~warrior() = default;

};

#endif /* WARRIORS_H */
