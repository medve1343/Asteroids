//
//  SmallRock.hpp
//  Asteroids
//
//  Created by Gergõ Medveczky on 3/27/20.
//  Copyright © 2020 Gergõ Medveczky. All rights reserved.
//

#ifndef SmallRock_hpp
#define SmallRock_hpp

#include <stdio.h>
#include "rocks.h"
class SmallRock: public Rock
{
private:
    
public:
    SmallRock(Point point, Velocity velocity, int LeftorRight)
    {
        rotation = 10;
        radius = 4;
        this-> velocity = velocity;
        
        this->velocity.setDx(velocity.getDx()+ LeftorRight);
        this-> point = point;
    }
    void draw();
    int getRadius() const;
    void kill();
};
#endif /* SmallRock_hpp */
