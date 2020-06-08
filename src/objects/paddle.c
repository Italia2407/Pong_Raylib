//
// Created by IGRec on 6 Jun 2020.
//

#include "paddle.h"

#define PADDLE_SPEED 5.0f


const int PADDLE_WIDTH = 36;
const int PADDLE_HEIGHT = 90;

Paddle InitPaddle(Vector2 position, KeyboardKey upKey, KeyboardKey downKey, Color colour)
{
	Paddle newPaddle = {0};
	
	newPaddle.position = position;
	newPaddle.scale = (Vector2){PADDLE_WIDTH, PADDLE_HEIGHT};
	newPaddle.upKey = upKey;
	newPaddle.downKey = downKey;
	newPaddle.colour = colour;
	
	return newPaddle;
}

void MovePaddle(Paddle* paddle)
{
	// Vertical Movement
	//------------------------------------------------------------------------------------------------------------------
	if (IsKeyDown(paddle->upKey))
	{
		paddle->position.y -= PADDLE_SPEED;
	}
	if (IsKeyDown(paddle->downKey))
	{
		paddle->position.y += PADDLE_SPEED;
	}
	//------------------------------------------------------------------------------------------------------------------
	
	// Boundary Check
	//------------------------------------------------------------------------------------------------------------------
	paddle->position.y = Clamp(paddle->position.y, 0.0f, GetScreenHeight() - PADDLE_HEIGHT);
	//------------------------------------------------------------------------------------------------------------------
}

void ResetPosition(Paddle* paddle, Vector2 origin)
{
	paddle->position = origin;
}

void DrawPaddle(Paddle paddle)
{
	DrawRectangleRec(paddle.boundingBox, paddle.colour);
}