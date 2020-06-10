//
// Created by IGRec on 9 Jun 2020.
//

#include "ball.h"

#define HORIZONTAL_SPEED 4.0f
#define MAX_VERTICAL_SPEED 5.0f

const int BALL_SIDE_LGTH = 24;

Ball InitBall(Vector2 position, Color colour)
{
	Ball newBall = {0};
	
	newBall.position = position;
	newBall.scale = (Vector2){BALL_SIDE_LGTH, BALL_SIDE_LGTH};
	newBall.velocity = Vector2Zero();
	newBall.colour = colour;
	
	return newBall;
}

void MoveBall(Ball* ball)
{
    ball->position = Vector2Add(ball->position, ball->velocity);
}

void StartBallMovement(Ball* ball)
{
	float horizontal = (GetRandomValue(0, 1) * 2 - 1) * HORIZONTAL_SPEED;
	float vertical = GetRandomValue(-MAX_VERTICAL_SPEED, MAX_VERTICAL_SPEED);
	
	ball->velocity = (Vector2){horizontal, vertical};
}

void BallResetPosition(Ball* ball, Vector2 origin)
{
	ball->velocity = Vector2Zero();
    ball->position = origin;
}

void DrawBall(Ball ball)
{
    DrawRectangleRec(ball.boundingBox, ball.colour);
}

int BallLowerBound()
{
    return LowerBound() - BALL_SIDE_LGTH;
}

int BallRighterBound()
{
    return RighterBound() - BALL_SIDE_LGTH;
}