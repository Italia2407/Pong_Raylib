//
// Created by IGRec on 11 Jun 2020.
//

#include "game-manager.h"

Paddle paddle1;
Paddle paddle2;

Ball ball;

int P1Score;
int P2Score;

int maxScore;

bool canMove;
bool gameWon = false;

void Start()
{
	canMove = true;
	StartBallMovement(&ball);
}

bool CheckPaddleScored(bool rightPaddle)
{
	if (!rightPaddle)
	{
		return ball.position.x >= BallRighterBound();
	} else
	{
		return ball.position.x <= LefterBound();
	}
}

void PaddleScored(bool rightPaddle)
{
	if (!rightPaddle)
	{
		P1Score++;
		gameWon = P1Score >= maxScore;
	} else
	{
		P2Score++;
		gameWon = P2Score >= maxScore;
	}
	
	canMove = false;
	
	if (!gameWon)
	{
		PaddleResetPosition(&paddle1, P1_DEF_POS);
		PaddleResetPosition(&paddle2, P2_DEF_POS);
		BallResetPosition(&ball, BALL_DEF_POS);
	}
}