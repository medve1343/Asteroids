/*********************************************************************
 * File: game.h
 * Description: Defines the game class for Asteroids
 *
 *********************************************************************/

#ifndef GAME_H
#define GAME_H
#include "point.h"
#include "uiInteract.h"
#include "ship.h"
#include <vector>
#include "bullet.h"
#include "rocks.h"
#include "flyingObject.h"
#include "BigRock.h"
#include "MediumRock.h"
#include "SmallRock.h"
class Game
{
private:
    Point topLeft;
    Point bottomrRight;
    Ship ship;
    std::vector<Bullet>bullets;
    std::vector<Rock*>rocks;
    void handleCollision();
    float getClosestDistance(const flyingObject &obj1, const flyingObject &obj2) const;
    void cleanUpZombies();
    int score;
    
public:
    
    Game(Point topLeft, Point bottomRight)
    {
        score = 0;
        for (int i = 0; i< 5;i++)
        {
        Rock*rock = new BigRock;
        rocks.push_back(rock);
            
        }
    }
    void advance();
    void draw(Interface ui);
    void handleInput(Interface ui);
    
    
    
    
};


#endif /* GAME_H */
