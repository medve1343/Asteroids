//
//  BigRock.cpp
//  Asteroids
//
//  Created by Gergõ Medveczky on 3/27/20.
//  Copyright © 2020 Gergõ Medveczky. All rights reserved.
//

#include "BigRock.h"

void BigRock::draw()
{
    drawLargeAsteroid(point, rotation);
}



void BigRock::kill()
{
    alive = false;
}
