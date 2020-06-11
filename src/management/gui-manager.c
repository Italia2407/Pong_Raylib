//
// Created by IGRec on 11 Jun 2020.
//

#include "gui-manager.h"
#include "game-manager.h"

#define BORDER_COLOUR (Color){11, 108, 182, 255}
#define TEXT_COLOUR RAYWHITE

#define SCORE1_RECT (Rectangle){18, 18, 144, 24}
#define SCORE2_RECT (Rectangle){SCREEN_WIDTH - 144 - 18, 18, 144, 24}

#define NAME1_RECT (Rectangle){18, SCREEN_HEIGHT - 24 + 1, 180, 24}
#define NAME2_RECT (Rectangle){SCREEN_WIDTH - 180 - 18, SCREEN_HEIGHT - 24 + 1, 180, 24}

const char* P1Name;
const char* P2Name;

void DrawVerticalBorders()
{
	DrawRectangle(0, 0, SCREEN_WIDTH, UpperBound(), BORDER_COLOUR);
	DrawRectangle(0, LowerBound(), SCREEN_WIDTH, SCREEN_HEIGHT - LowerBound(), BORDER_COLOUR);
}

void DrawScoreText()
{
	DrawTextRec(GetFontDefault(), TextFormat("Score: %i", P1Score), SCORE1_RECT, 24.0f, 2.0f, true, TEXT_COLOUR);
	DrawTextRec(GetFontDefault(), TextFormat("Score: %i", P2Score), SCORE2_RECT, 24.0f, 2.0f, true, TEXT_COLOUR);
	
	DrawTextRec(GetFontDefault(), P1Name, NAME1_RECT, 24.0f, 2.0f, true, TEXT_COLOUR);
	DrawTextRec(GetFontDefault(), P2Name, NAME2_RECT, 24.0f, 2.0f, true, TEXT_COLOUR);
}