#include "warriors.h"

class lancer : virtual public warrior {
public:
    int shield;
    bool is_defending;

    lancer(bool ally, int level);

    int type();

    void toss_shield();
    void shield_up();
    void shield_down();

    ~lancer() = default;
};
