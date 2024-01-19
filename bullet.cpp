#include "bullet.h"


// Put your bullet methods here
void Bullet :: draw()
{
    drawCircle(point, 2);
    bulletLife = bulletLife -1;
    if (bulletLife == 0)
    {
        kill();
    }
}

void Bullet :: fire(Point point, float angle)
{
    setPoint(point);
    
    float dx = BULLET_SPEED * (cos(M_PI / 180.0 * (angle+90)));
    float dy = BULLET_SPEED * (sin(M_PI / 180.0 * (angle+90)));
    
    velocity.setDx(dx);
    velocity.setDy(dy);
}

void Bullet:: kill()
{
    alive = false;
}
