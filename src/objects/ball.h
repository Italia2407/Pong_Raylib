//
// Created by IGRec on 9 Jun 2020.
//

#include "../globals.h"
#include "paddle.h"

#ifndef PONG_RAYLIB_BALL_H
#define PONG_RAYLIB_BALL_H

typedef struct Ball
{
    union 
    {
        struct
        {
            Vector2 position;
            Vector2 scale;
        };
        
        Rectangle boundingBox;
    };

    Vector2 velocity;

    Color colour;
} Ball;

extern const int BALL_SIDE_LGTH;

Ball InitBall(Vector2 position, Color colour);

void UpdatePosition(Ball* ball);
void StartBallMovement(Ball* ball);
void BallResetPosition(Ball* ball, Vector2 origin);

bool ResolvePaddleCollisions(Paddle paddle1, Paddle paddle2, Ball* ball);

void DrawBall(Ball ball);

int BallLowerBound();
int BallRighterBound();

#endif