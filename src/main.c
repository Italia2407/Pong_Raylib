#include "globals.h"
#include "objects/paddle.h"
#include "objects/ball.h"
#include <string.h>

#define P1_DEF_POS (Vector2){LefterBound(), (PaddleLowerBound() + UpperBound()) / 2}
#define P2_DEF_POS (Vector2){PaddleRighterBound(), (PaddleLowerBound() + UpperBound()) / 2}
#define BALL_DEF_POS (Vector2){(BallRighterBound() + LefterBound()) / 2, (BallLowerBound() + UpperBound()) / 2}

void DrawBoundsDebug(Color boundColour, Color centreColour);

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
			UpdatePosition(&ball);
			
			MovePaddle(&paddle1);
			MovePaddle(&paddle2);
			
			// Left-Paddle Collision
			CheckPaddleCollision(paddle1, &ball);
			// Right-Paddle Collision
			CheckPaddleCollision(paddle2, &ball);
		} else if (IsKeyPressed(KEY_ENTER))
		{
			canMove = true;
			StartBallMovement(&ball);
		}
		//--------------------------------------------------------------------------------------------------------------
		
		
		// Rendering
		//--------------------------------------------------------------------------------------------------------------
		BeginDrawing();
		
		ClearBackground(RAYWHITE);
		
		DrawBoundsDebug(BLUE, BLACK);
		DrawText(TextFormat("%f", ball.velocity.y), 0, 0, 24, BLACK);
		
		DrawPaddle(paddle1);
		DrawPaddle(paddle2);
		
		DrawBall(ball);
		
		EndDrawing();
		//--------------------------------------------------------------------------------------------------------------
	}
	//------------------------------------------------------------------------------------------------------------------
    return 0;
}

void DrawBoundsDebug(Color boundColour, Color centreColour)
{
DrawRectangle(0, 0, SCREEN_WIDTH, UpperBound(), boundColour);
DrawRectangle(0, LowerBound(), SCREEN_WIDTH, SCREEN_HEIGHT - LowerBound(), boundColour);

DrawRectangle(0, 0, LefterBound(), SCREEN_HEIGHT, boundColour);
DrawRectangle(RighterBound(), 0, SCREEN_WIDTH - RighterBound(), SCREEN_HEIGHT, boundColour);

DrawLine(0, (LowerBound() + UpperBound()) / 2, SCREEN_WIDTH, (LowerBound() + UpperBound()) / 2, centreColour);
DrawLine((RighterBound() + LefterBound()) / 2, 0, (RighterBound() + LefterBound()) / 2, SCREEN_HEIGHT, centreColour);
}