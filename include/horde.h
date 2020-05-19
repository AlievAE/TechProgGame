#ifndef HORDE_H
#define HORDE_H

#include<bits/stdc++.h>
#include "squad.h"

class Horde {
public:
    std::vector<Squad*> rgt;

    int type;
    bool dead;
    int pos;
    bool ready;
    Horde(int type);
    Horde(Squad*);
    void die();
    void fix_horde();
    void add(Squad*);
    int attack(Horde*);
    bool is_dead();
    int get_speed();
    void get_ready();
    int get_size();
    void buff();
    Squad* get_front();
    ~Horde() = default;
};

#endif /* HORDE_H */
