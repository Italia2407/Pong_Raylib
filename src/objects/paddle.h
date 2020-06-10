//
// Created by IGRec on 6 Jun 2020.
//

#include "../globals.h"

#ifndef PONG_RAYLIB_PADDLE_H
#define PONG_RAYLIB_PADDLE_H

typedef struct paddle
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
	
	Color colour;
	
	KeyboardKey upKey;
	KeyboardKey downKey;
} Paddle;

extern const int PADDLE_WIDTH;
extern const int PADDLE_HEIGHT;

Paddle InitPaddle(Vector2 position, KeyboardKey upKey, KeyboardKey downKey, Color colour);

void MovePaddle(Paddle* paddle);
void PaddleResetPosition(Paddle* paddle, Vector2 origin);

void DrawPaddle(Paddle paddle);

int PaddleLowerBound();
int PaddleRighterBound();

#endif //PONG_RAYLIB_PADDLE_H
