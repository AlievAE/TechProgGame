#include "cavalry.h"

class cavalry_archer : public cavalry {
public:

    int min_range;
    int melee_damage;

    cavalry_archer(bool ally, int level);
    int type();
    int attack(warrior*);

    ~cavalry_archer() = default;
};
