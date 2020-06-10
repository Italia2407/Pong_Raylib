#include "globals.h"
#include "objects/paddle.h"
#include "objects/ball.h"

#define P1_DEF_POS (Vector2){LefterBound(), (PaddleLowerBound() + UpperBound()) / 2}
#define P2_DEF_POS (Vector2){PaddleRighterBound(), (PaddleLowerBound() + UpperBound()) / 2}
#define BALL_DEF_POS (Vector2){(BallRighterBound() + LefterBound()) / 2, (BallLowerBound() + UpperBound()) / 2}

int main(void)
{
	// Initialisation
	//------------------------------------------------------------------------------------------------------------------
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pong");
	SetTargetFPS(FPS_CAP);
	//------------------------------------------------------------------------------------------------------------------
	
	Paddle paddle1 = InitPaddle(P1_DEF_POS, KEY_W ,KEY_S, ORANGE);
	Paddle paddle2 = InitPaddle(P2_DEF_POS, KEY_UP ,KEY_DOWN, PURPLE);

	Ball ball = InitBall(BALL_DEF_POS, RED);

	bool canMove = false;
	// Main Game Loop
	//------------------------------------------------------------------------------------------------------------------
	while (!WindowShouldClose())
	{
		// Update
		//--------------------------------------------------------------------------------------------------------------
		if (canMove)
		{
			MovePaddle(&paddle1);
			MovePaddle(&paddle2);
			
			MoveBall(&ball);
		}
		
		if (!canMove && IsKeyPressed(KEY_ENTER))
		{
			canMove = true;
			StartBallMovement(&ball);
		}
		//--------------------------------------------------------------------------------------------------------------
		
		
		// Rendering
		//--------------------------------------------------------------------------------------------------------------
		BeginDrawing();
		
		ClearBackground(RAYWHITE);
		
		DrawPaddle(paddle1);
		DrawPaddle(paddle2);
		
		DrawBall(ball);
		
		EndDrawing();
		//--------------------------------------------------------------------------------------------------------------
	}
	//------------------------------------------------------------------------------------------------------------------
    return 0;
}