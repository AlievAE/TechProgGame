#ifndef CAVALRY_CPP
#define CAVALRY_CPP

#include "warriors.cpp"
#include "../include/cavalry.h"

cavalry::cavalry(bool ally, int level) :
    warrior(ally, level) {
}

int cavalry::type() {
    return 3;
}

#endif /* CAVALRY.CPP */
