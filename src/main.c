#include "globals.h"
#include "objects/paddle.h"

#define SCREEN_WIDTH (1280)
#define SCREEN_HEIGHT (720)
#define FPS_CAP (60)

#define P1_DEFAULT_POS (Vector2){0.0f, 0.0f}
#define P2_DEFAULT_POS (Vector2){72.0f, 0.0f}

int main(void)
{
	// Initialisation
	//------------------------------------------------------------------------------------------------------------------
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pong");
	SetTargetFPS(FPS_CAP);
	//------------------------------------------------------------------------------------------------------------------
	
	Paddle paddle1 = InitPaddle(P1_DEFAULT_POS, KEY_W ,KEY_S, ORANGE);
	Paddle paddle2 = InitPaddle(P2_DEFAULT_POS, KEY_UP ,KEY_DOWN, PURPLE);
	// Main Game Loop
	//------------------------------------------------------------------------------------------------------------------
	while (!WindowShouldClose())
	{
		// Update
		//--------------------------------------------------------------------------------------------------------------
		MovePaddle(&paddle1);
		MovePaddle(&paddle2);
		//--------------------------------------------------------------------------------------------------------------
		
		
		// Rendering
		//--------------------------------------------------------------------------------------------------------------
		BeginDrawing();
		
		ClearBackground(RAYWHITE);
		
		DrawPaddle(paddle1);
		DrawPaddle(paddle2);
		
		EndDrawing();
		//--------------------------------------------------------------------------------------------------------------
	}
	//------------------------------------------------------------------------------------------------------------------
    return 0;
}