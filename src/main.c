#include "globals.h"

#include "objects/paddle.h"
#include "objects/ball.h"

#include "management/game-manager.h"
#include "management/gui-manager.h"

//#define DRAW_DEBUG

void DrawBoundsDebug(Color boundColour, Color centreColour);

void GetConsoleInput()
{
	const char* P1Buf = calloc(256, sizeof(char));
	const char* P2Buf = calloc(256, sizeof(char));
	
	printf("Please enter Player-1 Name: ");
	scanf("%s", P1Buf);
	
	printf("Please enter Player-2 Name: ");
	scanf("%s", P2Buf);
	
	P1Name = calloc(12, sizeof(char));
	P2Name = calloc(12, sizeof(char));
	
	strncpy(P1Name, P1Buf, 12);
	strncpy(P2Name, P2Buf, 12);
	
	
	printf("Please enter max score: ");
	scanf(" %i", &maxScore);
	
	if (maxScore <= 0)
		maxScore = 1;
}

int main(void)
{
	// Initialisation
	//------------------------------------------------------------------------------------------------------------------
	GetConsoleInput();
	
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pong");
	SetTargetFPS(FPS_CAP);
	//------------------------------------------------------------------------------------------------------------------
	
	paddle1 = InitPaddle(P1_DEF_POS, KEY_W ,KEY_S, P1_COLOUR);
	paddle2 = InitPaddle(P2_DEF_POS, KEY_UP ,KEY_DOWN, P2_COLOUR);
	
	ball = InitBall(BALL_DEF_POS, BALL_COLOUR);
	
	P1Score = 0;
	P2Score = 0;
	
	canMove = false;
	// Main Game Loop
	//------------------------------------------------------------------------------------------------------------------
	while (!WindowShouldClose())
	{
		// Update
		//--------------------------------------------------------------------------------------------------------------
		if (!gameWon)
		{
			if (canMove)
			{
				MovePaddle(&paddle1);
				MovePaddle(&paddle2);
				
				UpdatePosition(&ball);
				
				ResolvePaddleCollisions(paddle1, paddle2, &ball);
				
				if (ball.velocity.x > 0 && CheckPaddleScored(false))
				{
					PaddleScored(false);
				} else if (CheckPaddleScored(true))
				{
					PaddleScored(true);
				}
			} else if (IsKeyPressed(KEY_ENTER))
			{
				Start();
			}
		}
		//--------------------------------------------------------------------------------------------------------------
		
		// Rendering
		//--------------------------------------------------------------------------------------------------------------
		BeginDrawing();
		
		ClearBackground(RAYWHITE);

#ifdef DRAW_DEBUG
		DrawBoundsDebug(BLUE, BLACK);
		DrawText(TextFormat("%f", ball.velocity.y), 0, 0, 24, BLACK);
#endif
		
		DrawVerticalBorders();
		DrawScoreText();
		
		DrawPaddle(paddle1);
		DrawPaddle(paddle2);
		
		DrawBall(ball);
		
		if (gameWon)
		{
			DrawWin(P2Score >= maxScore);
		}
		
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