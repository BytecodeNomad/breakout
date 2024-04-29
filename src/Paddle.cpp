#include "lib/Paddle.h"




void Paddle::draw() {
    DrawRectangleRounded(getRectangle(), 0.7, 0, color);
}

Rectangle Paddle::getRectangle(){
            return Rectangle{pos_x, pos_y, width, height};
}


void Paddle::update() {
    if(IsKeyDown(KEY_LEFT)) {
        pos_x -= speed_x;
    }
    if(IsKeyDown(KEY_RIGHT)) {
        pos_x += speed_x;
    }
    limitMovement();
}

void Paddle::limitMovement() {
    if(pos_x <= 0) {
        pos_x = 0;

    }
    if(pos_x + width >= GetScreenWidth()) {
        pos_x = GetScreenWidth() - width;
    }
}