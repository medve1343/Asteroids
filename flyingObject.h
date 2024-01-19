#ifndef flyingObject_h
#define flyingObject_h
#include "point.h"
#include "velocity.h"
#include "uiDraw.h"


// Put your FlyingObject class here
class flyingObject
{
protected:
    Point point;
    Velocity velocity;
    bool alive;
    
public:
    flyingObject()
    {
        alive = true;
    }
    void setPoint(Point point);
    virtual void draw() = 0;
    void advance();
    Point getPoint() const;
    bool isAlive();
    Velocity getVelocity() const;
};



#endif /* flyingObject_h */
