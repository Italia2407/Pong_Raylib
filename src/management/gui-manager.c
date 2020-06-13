//
// Created by IGRec on 11 Jun 2020.
//

#include "gui-manager.h"
#include "game-manager.h"

#define BORDER_COLOUR (Color){219, 5, 126, 255}
#define TEXT_COLOUR RAYWHITE
#define WIN_COLOUR BLACK

const char* P1Name;
const char* P2Name;

void DrawVerticalBorders()
{
	DrawRectangle(0, 0, SCREEN_WIDTH, UpperBound(), BORDER_COLOUR);
	DrawRectangle(0, LowerBound(), SCREEN_WIDTH, SCREEN_HEIGHT - LowerBound(), BORDER_COLOUR);
}

void DrawScoreText()
{
	DrawText(TextFormat("Score: %i", P1Score), 18, 18, 24.0f, TEXT_COLOUR);
	DrawText(TextFormat("Score: %i", P2Score), SCREEN_WIDTH - 121 - 18, 18, 24.0f, TEXT_COLOUR);
	
	DrawText(P1Name, 18, SCREEN_HEIGHT - 20, 18.0f, TEXT_COLOUR);
	DrawText(P2Name, SCREEN_WIDTH - 160 - 18, SCREEN_HEIGHT - 20, 18.0f, TEXT_COLOUR);
}

void DrawWin(bool Player2)
{
	if (!Player2)
		DrawText(TextFormat("%s: WINS!!!", P1Name), (SCREEN_WIDTH/2) - 450, (SCREEN_HEIGHT/2) - 20, 72.0f, WIN_COLOUR);
	else
		DrawText(TextFormat("%s: WINS!!!", P2Name), (SCREEN_WIDTH/2) - 450, (SCREEN_HEIGHT/2) - 20, 72.0f, WIN_COLOUR);
}