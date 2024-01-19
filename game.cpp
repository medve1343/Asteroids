/*********************************************************************
 * File: game.cpp
 * Description: Contains the implementaiton of the game class
 *  methods.
 *
 *********************************************************************/

#include "game.h"

// These are needed for the getClosestDistance function...
#include <limits>
#include <algorithm>
#include "flyingObject.h"

using namespace std;

void Game::draw(Interface ui)
{
    //if (ship.isAlive() == true)
    //{
    ship.draw();
    //}
    
    for (int i = 0; i < bullets.size(); i++)
    {
       if (bullets[i].isAlive())
       {
          bullets[i].draw();
        
       }
    }
    
    for (int i = 0; i < rocks.size(); i++)
    {
       if (rocks[i]->isAlive())
       {
          rocks[i]->draw();
       }
    }
    
    Point scoreLocation;
    scoreLocation.setX(-190);
    scoreLocation.setY(190);
    drawNumber(scoreLocation, score);
    
}

void Game::handleInput(Interface ui)
{
    if (ui.isLeft())
    {
        ship.moveLeft();
        
    }
    if (ui.isRight())
    {
        ship.moveRight();
    }
    if (ui.isUp())
    {
        ship.moveForward();
        
    }
    if (ui.isSpace())
    {
        Bullet newBullet;
        newBullet.fire(ship.getPoint(), ship.getRotation());
        
        bullets.push_back(newBullet);
    }
    if (ui.isDown())
    {
        ship.slowDown();
    }
}

void Game::advance()
{
    cleanUpZombies();
    handleCollision();
    ship.advance();
    for (int i = 0; i < bullets.size(); i++)
    {
       if (bullets[i].isAlive())
       {
          bullets[i].advance();
       }
    }
    
    for (int i = 0; i < rocks.size(); i++)
    {
       if (rocks[i]->isAlive())
       {
          rocks[i]->advance();
       }
    }
    if (rocks.size() == 0)
    {
        for (int i = 0; i< 5;i++)
        {
        Rock*rock = new BigRock;
        rocks.push_back(rock);
            
        }
    }
}

void Game::handleCollision()
{
    Rock* newRock = NULL;
    vector<Bullet>::iterator it2;
    vector<Rock*>::iterator it;
    vector <Rock *> tempRock;
    for (it = rocks.begin(); it != rocks.end(); it++)
    {
        if(getClosestDistance(*(*it),ship) < ship.getRadius() + (*it)->getRadius())
        {
            ship.kill();
        }
        for (it2 = bullets.begin(); it2 != bullets.end(); it2++)
        {
            if(getClosestDistance(*(*it), *it2) < (*it)->getRadius())
            {
                 (*it)->kill();
                 (*it2).kill();
                switch((*it)->getRadius())
                {
                    case 16:
                        score = score + 1;
                        newRock = new MediumRock((*it)->getPoint(), (*it)->getVelocity(), 1);
                        tempRock.push_back(newRock);
                        
                        newRock = new MediumRock((*it)->getPoint(), (*it)->getVelocity(), -1);
                        tempRock.push_back(newRock);
                        newRock = new SmallRock((*it)->getPoint(), (*it)->getVelocity(), 2);
                        tempRock.push_back(newRock);
                        break;
                    case 8:
                        score = score + 10;
                        newRock = new SmallRock((*it)->getPoint(), (*it)->getVelocity(), 3);
                        tempRock.push_back(newRock);
                        newRock = new SmallRock((*it)->getPoint(), (*it)->getVelocity(), -3);
                        tempRock.push_back(newRock);
                        break;
                    case 4:
                        score = score + 100;
                        break;
                }
            }
        }
    }
    
    //add all of tempROck to rocks
    rocks.insert(rocks.end(), tempRock.begin(), tempRock.end());
}

void Game::cleanUpZombies()
{
    
    vector<Rock*>::iterator it;
    for (it = rocks.begin(); it != rocks.end();)
    {
        if(!(*it)->isAlive())
        {
            delete (*it);
            it = rocks.erase(it);
        }
        else
        {
            it++;
        }
        
    
    }
    
     vector<Bullet>::iterator bulletIt = bullets.begin();
     while (bulletIt != bullets.end())
     {
        Bullet bullet = *bulletIt;
        
        if (!bullet.isAlive())
        {
           bulletIt = bullets.erase(bulletIt);
        }
        else
        {
           bulletIt++;
        }
     }
    
    
    
    
    
    
}
// You may find this function helpful...

/**********************************************************
 * Function: getClosestDistance
 * Description: Determine how close these two objects will
 *   get in between the frames.
 **********************************************************/

float Game :: getClosestDistance(const flyingObject &obj1, const flyingObject &obj2) const
{
   // find the maximum distance traveled
   float dMax = max(abs(obj1.getVelocity().getDx()), abs(obj1.getVelocity().getDy()));
   dMax = max(dMax, abs(obj2.getVelocity().getDx()));
   dMax = max(dMax, abs(obj2.getVelocity().getDy()));
   dMax = max(dMax, 0.1f); // when dx and dy are 0.0. Go through the loop once.
   
   float distMin = std::numeric_limits<float>::max();
   for (float i = 0.0; i <= dMax; i++)
   {
      Point point1(obj1.getPoint().getX() + (obj1.getVelocity().getDx() * i / dMax),
                     obj1.getPoint().getY() + (obj1.getVelocity().getDy() * i / dMax));
      Point point2(obj2.getPoint().getX() + (obj2.getVelocity().getDx() * i / dMax),
                     obj2.getPoint().getY() + (obj2.getVelocity().getDy() * i / dMax));
      
      float xDiff = point1.getX() - point2.getX();
      float yDiff = point1.getY() - point2.getY();
      
      float distSquared = (xDiff * xDiff) +(yDiff * yDiff);
      
      distMin = min(distMin, distSquared);
   }
   
   return sqrt(distMin);
}


/*bool Game::isOnScreen(const Point & point)
{
    return (point.getX() >= topLeft.getX() - OFF_SCREEN_BORDER_AMOUNT
        && point.getX() <= bottomRight.getX() + OFF_SCREEN_BORDER_AMOUNT
        && point.getY() >= bottomRight.getY() - OFF_SCREEN_BORDER_AMOUNT
        && point.getY() <= topLeft.getY() + OFF_SCREEN_BORDER_AMOUNT);
}
*/
