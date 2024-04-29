#include "lib/Brick.h"

void Brick::draw() {
    DrawRectangle(pos_x, pos_y, width, height, color);
}
Rectangle Brick::getRecProps() {
    return Rectangle{pos_x, pos_y, width, height};
}

bool Brick::operator==(Brick& compare_against) {

    return pos_x == compare_against.pos_x && pos_y == compare_against.pos_y;
}
