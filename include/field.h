#ifndef FIELD_H
#define FIELD_H

#include "parameter.h"
#include "warriors.h"

class Player {
public:
    bool ally;
    int gold;
    std::vector<warrior*> army;
    int barrack[3];
    bool upgrade(int type);
    bool create_unit(int type);

    Player(bool ally);

    Field_parameter FP = Singleton::FP;
    Unit_parameter UP = Singleton::UP;
};

class Field {
public:
    int size;
    Player* player[2];
    void upgrade(int type, bool ally);
    void create_unit(int type, bool ally);

    constexpr static Field_parameter FP = Singleton::FP;

    friend class Sing;
private:
    Field(int size = FP.FIELD_SIZE);
};

class Sing {
public:
    inline static Field field = Field();
    Sing() = default;
};

#endif /* FIELD_H */
