#include "velocity.h"


// Put your velocity methods here
Velocity ::Velocity()
{
    setDx(0);
    setDy(0);
}
Velocity ::Velocity(float Dx, float Dy)
{
    setDx(Dx);
    setDy(Dy);
}
//getter for Dx
float Velocity::getDx() const
{
    return Dx;
}

//getter for Dy
float Velocity::getDy() const
{
    return Dy;
}

//setter for Dx
void Velocity::setDx(float Dx)
{
    this -> Dx = Dx;
}

//setter for Dy
void Velocity::setDy(float Dy)
{
    this -> Dy = Dy;
}
