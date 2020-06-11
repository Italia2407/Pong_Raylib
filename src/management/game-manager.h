//
// Created by IGRec on 11 Jun 2020.
//

#include "../globals.h"
#include "../objects/paddle.h"
#include "../objects/ball.h"

#ifndef PONG_RAYLIB_GAME_MANAGER_H
#define PONG_RAYLIB_GAME_MANAGER_H

#define P1_DEF_POS (Vector2){LefterBound(), (PaddleLowerBound() + UpperBound()) / 2}
#define P2_DEF_POS (Vector2){PaddleRighterBound(), (PaddleLowerBound() + UpperBound()) / 2}
#define BALL_DEF_POS (Vector2){(BallRighterBound() + LefterBound()) / 2, (BallLowerBound() + UpperBound()) / 2}

extern Paddle paddle1;
extern Paddle paddle2;

extern Ball ball;

extern int P1Score;
extern int P2Score;

extern int maxScore;

extern bool canMove;

void Start();

bool CheckPaddleScored(bool rightPaddle);
void PaddleScored(bool RightPaddle);

#endif //PONG_RAYLIB_GAME_MANAGER_H
