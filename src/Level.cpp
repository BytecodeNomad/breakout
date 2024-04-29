#include "lib/Brick.h"
#include "Brick.cpp"
#include "lib/Ball.h"
#include "Ball.cpp"





#include <vector>
#include <algorithm>
#include <stdexcept>
#include <cmath>
using namespace std;

class Level{
    public:
        int number_of_bricks;
        unsigned int bricks_per_row;

        int padding_left = 10;
        int padding_right = 10;
        int padding_top = 7;

        int spacing_x = 5;
        int spacing_y = 7;

       

        vector<Brick> container_bricks;
        
        void createBricks();
        void drawBricks();
        void checkCollisionBallAndBrick(Ball&);
        void checkCollisionBallAndPaddle(Ball&, Paddle&);
        void resolveCollision(Brick& brick, Ball& ball);
        int findBrick(Brick& el_check_for, vector<Brick>& bricks);
        
};

void Level::createBricks() {
        int block_width = (GetScreenWidth() - padding_left - padding_right - 9*spacing_x) / bricks_per_row;

        int numberOfBricks = number_of_bricks;
        Brick brick;
        brick.height = 20;
        brick.width = block_width;
        brick.row_number = 0;

        int start_draw_location_x = padding_left;
        int start_draw_location_y = spacing_y;

        while(numberOfBricks > 0) {



            unsigned int i;
            for(i = 1; i <= bricks_per_row; i++) {
                brick.pos_x = start_draw_location_x;
                brick.pos_y = start_draw_location_y;

                container_bricks.push_back(brick);
                
                start_draw_location_x = start_draw_location_x + block_width + spacing_x;
            }

            start_draw_location_x = padding_left;
            start_draw_location_y = start_draw_location_y + brick.height + spacing_y;

            brick.row_number++;
            numberOfBricks -= i;
    }
}
void Level::drawBricks() {
    for(Brick& brick: container_bricks) {
        brick.draw();

    }
}
void Level::checkCollisionBallAndBrick(Ball& ball) {
    for(Brick& brick: container_bricks) {
        if(CheckCollisionCircleRec(ball.getCenter(), ball.radius, brick.getRecProps())){
            resolveCollision(brick, ball);
        }
        if(brick.destroy) {
            int it = findBrick(brick, container_bricks);

            if(it != -1) {
                container_bricks.erase(it + container_bricks.begin());
            }
        }
    }
}

void Level::checkCollisionBallAndPaddle(Ball& ball, Paddle& paddle) {
    if(CheckCollisionCircleRec(ball.getCenter(), ball.radius, paddle.getRectangle())) {
            
        ball.speed_x *= -1;
        ball.speed_y *= -1;

            
        }
}

void Level::resolveCollision(Brick& brick, Ball& ball) {
            ball.speed_y *= -1;
            ball.speed_x *= -1;
            brick.color.a -= 85;

            if(brick.color.a == 0) {
                brick.destroy = true;
            }
            
}

int Level::findBrick(Brick& el_check_for, vector<Brick>& bricks)
{
        for(size_t i = 0; i < bricks.size(); i++) {

            if(el_check_for == bricks[i]) {
                return i;
            }
        }
        return -1;
}