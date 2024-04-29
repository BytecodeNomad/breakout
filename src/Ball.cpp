#include "lib/Ball.h"

using namespace std;

// Ball::Ball(float x, float y, float radius, int speedX, int speedY) : 
//     pos_x{x}, pos_y{y}, radius{radius}, speed_x{speedX}, speed_y{speedY},
//     initialSpeedX{speedX}, initialSpeedY{speedY}
//     {}


void Ball::draw() {
    DrawCircle(pos_x, pos_y, radius, WHITE);
}
void Ball::update() {
    pos_x += speed_x;
    pos_y += speed_y;
    limitMovement();
}

Vector2 Ball::getCenter() {
    return Vector2{pos_x, pos_y};
}

void Ball::limitMovement() {
    if(pos_x + radius >= GetScreenWidth()) {
        speed_x *= -1;
    }
    if(pos_x - radius <= 0) {
        speed_x *= -1;
    }
    if(pos_y - radius <= 0) {
        speed_y *= -1;
    }
}
void Ball::resetPosition(const Paddle& player_paddle) {
     {
        pos_x = player_paddle.pos_x + (player_paddle.width / 2);
        pos_y = GetScreenHeight() - player_paddle.height - radius - 10;

    }
}
