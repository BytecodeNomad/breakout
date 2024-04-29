#ifndef PADDLE_H

#define PADDLE_H
#include <raylib.h>

class Paddle{
    public:
        float width, height, pos_x, pos_y;
        int speed_x;
        
        Color color{253, 249, 0, 255};

        // Paddle(int, int, int, int);

        void draw();
        void update();

        KeyboardKey direction();
        
        Rectangle getRectangle();
    private:
        void limitMovement();
};

#endif