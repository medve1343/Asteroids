#include "ship.h"

// Put your ship methods here
void Ship::draw()
{
    drawShip(point, rotation, thrust);
    thrust = false;
}


void Ship::moveForward()
{
    float dx = cos(M_PI / 180.0 * (rotation + 90));
    float dy = sin(M_PI / 180.0 * (rotation + 90));
    velocity.setDy(velocity.getDy() + dy);
    velocity.setDx(velocity.getDx() + dx);
    thrust = true;
}
void Ship::moveRight()
{
    //velocity.setDx(velocity.getDx() + .1);
    rotation = rotation - 6;
}
void Ship::moveLeft()
{
    //velocity.setDx(velocity.getDx() - .1);
    rotation = rotation + 6;
}

void Ship::slowDown()
{
    velocity.setDx(velocity.getDx() *0.95);
    velocity.setDy(velocity.getDy()*0.95);
}
int Ship:: getRotation() const
{
    return rotation;
}

int Ship::getRadius() const
{
    return radius;
}

void Ship::kill()
{
    alive = false;
}
