#include "flyingObject.h"


// Put your FlyingObject method bodies here
void flyingObject::advance()
{
    point.addX(velocity.getDx());
    point.addY(velocity.getDy());
    if(point.getX() > 200)
    {
        point.setX(-200);
    }
    if(point.getY() > 200)
    {
        point.setY(-200);
    }
    if(point.getX() < -200)
    {
        point.setX(200);
    }
    if(point.getY() < -200)
    {
        point.setY(200);
    }
}

void flyingObject::setPoint(Point point)
{
    this->point= point;
}

Point flyingObject::getPoint() const
{
    return point;
}

bool flyingObject::isAlive()
{
    return alive;
}

Velocity flyingObject::getVelocity() const
{
    return velocity;
}
