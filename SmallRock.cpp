//
//  SmallRock.cpp
//  Asteroids
//
//  Created by Gergõ Medveczky on 3/27/20.
//  Copyright © 2020 Gergõ Medveczky. All rights reserved.
//

#include "SmallRock.h"

void SmallRock::draw()
{
    drawSmallAsteroid(point, rotation);
}



void SmallRock::kill()
{
    alive = false;
}
