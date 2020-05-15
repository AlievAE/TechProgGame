#ifndef SQUAD_H
#define SQUAD_H

#include<bits/stdc++.h>
#include "warriors.h"

class Squad {
public:
    std::vector<warrior*> party;
    int type;
    bool dead;
    Squad(int type);
    Squad(warrior*);
    void die();
    void fix_squad();
    void add(warrior*);
    int attack(Squad*);
    int get_speed();
    bool is_dead();
    void buff();
    warrior* get_front();
    int get_size();
    ~Squad() = default;
};

#endif /* SQUAD_H */
