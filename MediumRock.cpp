//
//  MediumRock.cpp
//  Asteroids
//
//  Created by Gergõ Medveczky on 3/27/20.
//  Copyright © 2020 Gergõ Medveczky. All rights reserved.
//

#include "MediumRock.h"

void MediumRock::draw()
{
    drawMediumAsteroid(point, rotation);
}



void MediumRock::kill()
{
    alive = false;
}
