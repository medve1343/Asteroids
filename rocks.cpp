#include "rocks.h"

// Put your Rock methods here
void Rock::kill()
{
    alive = false;
}

int Rock::getRadius() const
{
    return radius;
}
