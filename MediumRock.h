//
//  MediumRock.hpp
//  Asteroids
//
//  Created by Gergõ Medveczky on 3/27/20.
//  Copyright © 2020 Gergõ Medveczky. All rights reserved.
//

#ifndef MediumRock_hpp
#define MediumRock_hpp

#include <stdio.h>
#include "rocks.h"

class MediumRock: public Rock
{
private:
    
public:
    
    MediumRock(Point point, Velocity velocity, int UporDown)
    {
        
        rotation = 5;
        radius = 8;
        this-> velocity = velocity;
        
        this->velocity.setDy(velocity.getDy()+ UporDown);
        this-> point = point;
        
        
        
    }
    void draw();
    int getRadius() const;
    void kill();
};
#endif /* MediumRock_hpp */
