#ifndef ship_h
#define ship_h

#define SHIP_SIZE 10

#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.5
#include "flyingObject.h"
#include "uiDraw.h"
#include "velocity.h"
// Put your Ship class here
class Ship :public flyingObject
{
private:
    int rotation;
    bool thrust;
    int radius;
public:
    void draw();
    Ship()
    {
        radius = 10;
        rotation = 0;
        thrust = false;
    }
    void moveForward();
    void moveRight();
    void moveLeft();
    void slowDown();
    int getRotation() const;
    int getRadius() const;
    void kill();
    
};

#endif /* ship_h */
