#include "cavalry.h"

class cavalry_lancer : public cavalry {
public:

    cavalry_lancer(bool ally, int level);
    int type();
    int attack(warrior*);

    ~cavalry_lancer() = default;
};
