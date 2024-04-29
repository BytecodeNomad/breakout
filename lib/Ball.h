#ifndef BALL_H
#define BALL_H
#include <raylib.h>
#include <array>
#include "Paddle.h"



class Ball{
    public:
        float pos_x, pos_y;
        float radius;
        int speed_x, speed_y;

        // Ball(float, float, float, int, int);

        void draw();
        void update();
        Vector2 getCenter();
        void resetPosition(const Paddle&);
        
    private:
        int initialSpeedX, initialSpeedY;
        void limitMovement();
        

};


#endif