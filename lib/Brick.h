#ifndef BRICKS_H
#define BRICKS_H

#include <raylib.h>
#include <array>

class Brick{
    public:
        float height, pos_x, pos_y, width;
        int row_number;
        Color color {0,228, 48,255};
        bool destroy = false;

        void draw();
        Rectangle getRecProps();
        
        

        bool operator==(Brick&);
        // void createBricks(int = 10);
};
#endif