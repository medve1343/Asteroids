#ifndef bullet_h
#define bullet_h

#define BULLET_SPEED 5
#define BULLET_LIFE 40
#include "velocity.h"
#include "point.h"
#include "flyingObject.h"
#include <cmath> // used for sin, cos, and M_PI
#include "uiDraw.h"

// Put your Bullet class here
class Bullet : public flyingObject
{
private:
    int bulletLife;
public:
    Bullet()
    {
        bulletLife = 40;
    }
    
    void draw();
    void fire(Point point, float angle);
    void kill();
};



#endif /* bullet_h */
