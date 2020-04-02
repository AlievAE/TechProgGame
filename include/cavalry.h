#ifndef CAVALRY_H
#define CAVALRY_H


#include "warriors.h"

class cavalry : public warrior {
public:

    int streak;

    virtual int type();

    cavalry(bool ally, int level);

    ~cavalry() = default;
};

#endif /* CAVALRY_H */
