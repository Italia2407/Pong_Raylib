//
// Created by IGRec on 9 Jun 2020.
//

#include "ball.h"

#define HORIZONTAL_SPEED 4.0f
#define MAX_VERTICAL_SPEED 5.0f
#define RANDOM_VARIATION 8.0f

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

void UpdatePosition(Ball* ball)
{
    ball->position = Vector2Add(ball->position, ball->velocity);
    
    // Checks if the ball collides with the vertical bounds
    if (ball->position.y <= UpperBound() || ball->position.y >= BallLowerBound())
	{
    	ball->position.y = Clamp(ball->position.y, UpperBound(), BallLowerBound());
    	ball->velocity.y = -(ball->velocity.y);
	}
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

bool CheckPaddleCollision(Paddle paddle, Ball* ball)
{
	if (CheckCollisionRecs(paddle.boundingBox, ball->boundingBox))
	{
		float randomVariation = GetRandomValue(-RANDOM_VARIATION, RANDOM_VARIATION) / 10.0f;
		
		ball->position.x = Clamp(ball->position.x, LefterBound() + PADDLE_WIDTH, BallRighterBound() - PADDLE_WIDTH);
		ball->velocity.x = -(ball->velocity.x);
		
		ball->velocity.y = Clamp(ball->velocity.y + randomVariation, -MAX_VERTICAL_SPEED, MAX_VERTICAL_SPEED);
		
		return true;
	}
	
	return false;
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