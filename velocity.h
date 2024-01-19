#ifndef VELOCITY_H
#define VELOCITY_H


// Put your velocity class here, or overwrite this file with your own
// velocity class from the previous project
class Velocity
{
private:
    float Dx;
    float Dy;
public:
    //Non-default constructor
    Velocity();
    //Default constructor
    Velocity(float Dx, float Dy);
    //getter for Dx
    float getDx() const;
    //getter for Dy
    float getDy() const;
    //setter for Dx
    void setDx(float Dx);
    //setter for Dy
    void setDy(float Dy);
};

#endif /* velocity_h */
