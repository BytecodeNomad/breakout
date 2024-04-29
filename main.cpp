#include <raylib.h>
#include <iostream>
#include <array>



#include "lib/Paddle.h"
#include "src/Paddle.cpp"
#include "src/Level.cpp"

using namespace std;

#define SCREEN_WIDTH 900
#define SCREEN_HEIGHT 600
#define FPS 60



int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Breakout");
    SetTargetFPS(FPS);


    Paddle player_paddle;
    player_paddle.width = 100;
    player_paddle.height = 20;
    player_paddle.speed_x = 6;
    player_paddle.pos_x = SCREEN_WIDTH / 2 - player_paddle.width;
    player_paddle.pos_y = SCREEN_HEIGHT - player_paddle.height - 5;

    Ball ball;
    ball.radius = 15;
    ball.pos_x = player_paddle.pos_x + (player_paddle.width / 2);
    ball.pos_y = SCREEN_HEIGHT - player_paddle.height - ball.radius - 10;
    ball.speed_x = ball.speed_y = 5;

    Level level;
    level.number_of_bricks = 50;
    level.bricks_per_row = 10;
    level.createBricks();

    while(!WindowShouldClose()) {

        BeginDrawing();

        ball.update();
        player_paddle.update();


        if(ball.pos_y + ball.radius >= GetScreenHeight()) {
            ball.resetPosition(player_paddle);
        }
        level.checkCollisionBallAndBrick(ball);
        level.checkCollisionBallAndPaddle(ball, player_paddle);

        ClearBackground(BLACK);

        level.drawBricks();
        ball.draw();
        player_paddle.draw();
        
        EndDrawing();
    }

    CloseWindow();
}
