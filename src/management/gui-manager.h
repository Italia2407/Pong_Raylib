//
// Created by IGRec on 11 Jun 2020.
//

#include "../globals.h"

#ifndef PONG_RAYLIB_GUI_MANAGER_H
#define PONG_RAYLIB_GUI_MANAGER_H

#define P1_COLOUR (Color){255, 141, 6, 255}
#define P2_COLOUR (Color){44, 32, 199, 255}
#define BALL_COLOUR (Color){42, 42, 42, 255}

extern const char* P1Name;
extern const char* P2Name;

void DrawVerticalBorders();
void DrawScoreText();

void DrawWin(bool Player2);

#endif //PONG_RAYLIB_SCORE_MANAGER_H
