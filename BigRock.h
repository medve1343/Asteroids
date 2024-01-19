//
//  BigRock.hpp
//  Asteroids
//
//  Created by Gergõ Medveczky on 3/27/20.
//  Copyright © 2020 Gergõ Medveczky. All rights reserved.
//

#ifndef BigRock_hpp
#define BigRock_hpp
#include "rocks.h"
#include <stdio.h>
class BigRock:public Rock
{
private:
public:
    
    BigRock()
    {
        int angle = random(0,360);
        rotation = 2;
        radius = 16;
        point.setX(random(-200, 200));
        point.setY(random(-200, 200));
        velocity.setDy(sin(M_PI /180.0 * angle));
    
        velocity.setDx(cos(M_PI / 180.0 * angle));
    }
    
    
    void draw();
    int getRadius() const;
    void kill();
};
#endif /* BigRock_hpp */
