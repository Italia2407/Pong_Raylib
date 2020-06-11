//
// Created by IGRec on 11 Jun 2020.
//

#include "gui-manager.h"

void DrawVerticalBorders(Color colour)
{
	DrawRectangle(0, 0, SCREEN_WIDTH, UpperBound(), colour);
	DrawRectangle(0, LowerBound(), SCREEN_WIDTH, SCREEN_HEIGHT - LowerBound(), colour);
}

void DrawScoreText()
{

}