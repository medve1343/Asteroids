#ifndef rocks_h
#define rocks_h

#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10
#include "flyingObject.h"



// Define the following classes here:
//   Rock
//   BigRock
//   MediumRock
//   SmallRock
class Rock: public flyingObject
{
protected:
    int rotation;
    int radius;
public:
    Rock()
    {
        rotation = random(0, 360);
        
    }
    virtual void draw() = 0;
    int getRadius() const;
    void kill();
    
};



#endif /* rocks_h */
