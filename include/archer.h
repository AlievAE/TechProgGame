#include "warriors.h"

class archer : public warrior {
public:
    int min_range;
    int melee_damage;

    int type();
    int attack(warrior*);

    archer(bool ally, int level);

    ~archer() = default;
};
