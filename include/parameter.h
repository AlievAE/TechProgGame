#ifndef PARAMETER_H
#define PARAMETER_H

class Unit_parameter {
public:
    const int LANCER_HEALTH[3] = {4, 8, 12};
    const int LANCER_SPEED[3] = {1, 2, 3};
    const int SHIELD[3] = {1, 2, 3};
    const int LANCER_VISION[3] = {1, 2, 3};
    const int LANCER_BOUNTY[3] = {3, 2, 1};
    const int LANCER_ATTACK_RANGE[3] = {2, 2, 3};
    const int LANCER_DAMAGE[3] = {3, 6, 9};
    const int LANCER_MARCH_SPEED[3] = {2, 2, 2};
    const int LANCER_DEF_SPEED[3] = {0, 0, 0};
    const int LANCER_DEF_DAMAGE[3] = {0, 1, 2};
    const int LANCER_DEF_VISION[3] = {0, 1, 2};

    const int ARCHER_HEALTH[3] = {2, 5, 8};
    const int ARCHER_SPEED[3] = {1, 2, 3};
    const int ARCHER_VISION[3] = {4, 6, 8};
    const int ARCHER_BOUNTY[3] = {5, 3, 1};
    const int ARCHER_ATTACK_RANGE[3] = {5, 7, 9};
    const int ARCHER_DAMAGE[3] = {2, 6, 10};
    const int ARCHER_MIN_RANGE[3] = {5, 4, 3};
    const int ARCHER_MELEE_DAMAGE[3] = {1, 3, 5};

    const int CAVALRY_LANCER_HEALTH[3] = {12, 18, 24};
    const int CAVALRY_LANCER_SPEED[3] = {3, 3, 3};
    const int CAVALRY_LANCER_VISION[3] = {1, 2, 3};
    const int CAVALRY_LANCER_BOUNTY[3] = {10, 8, 6};
    const int CAVALRY_LANCER_DAMAGE[3] = {7, 10, 13};
    const int CAVALRY_LANCER_ATTACK_RANGE[3] = {2, 2, 3};
    const int CAVALRY_LANCER_BERSERK[5] = {2, 4, 6, 9, 13};

    const int CAVALRY_ARCHER_HEALTH[3] = {2, 5, 8};
    const int CAVALRY_ARCHER_SPEED[3] = {1, 2, 3};
    const int CAVALRY_ARCHER_VISION[3] = {4, 6, 8};
    const int CAVALRY_ARCHER_BOUNTY[3] = {5, 3, 1};
    const int CAVALRY_ARCHER_ATTACK_RANGE[3] = {5, 7, 9};
    const int CAVALRY_ARCHER_DAMAGE[3] = {2, 6, 10};
    const int CAVALRY_ARCHER_MIN_RANGE[3] = {3, 2, 1};
    const int CAVALRY_ARCHER_MELEE_DAMAGE[3] = {1, 3, 5};
    const int CAVALRY_ARCHER_BERSERK[5] = {2, 4, 6, 9, 13};

    const int DAMAGE_BUFF = 2;

    const int BUFF_COST[4] = {5, 6, 7, 8};


    //const int LANCER_COST[3] = {2, 4, 6};
    //const int ARCHER_COST[3] = {3, 6, 9};
    //const int CAVALRY_LANCER_COST[3] = {10, 20, 30};
    //const int CAVALRY_ARCHER_COST[3] = {3, 6, 9};
    int COSTS[4][3] = {{2, 4, 6}, {3, 6, 9}, {10, 20, 30}, {3, 6, 9}};

    friend class Singleton;
private:
    Unit_parameter() = default;
};

class Field_parameter {
public:
    const int FIELD_SIZE = 30;

    const int BARRACK_COST[3][2] = {{15, 25}, {18, 30}, {40, 60}};

    const int BASE_GOLD = 20;

    friend class Singleton;

private:
    Field_parameter() = default;
};

class Singleton {
public:
    constexpr inline static Unit_parameter UP = Unit_parameter();
    constexpr inline static Field_parameter FP = Field_parameter();
    Singleton() = default;
};

#endif /* PARAMETER_H */
