#include "paddle.h"

#include <stdio.h>


void SetPaddleStartParams(Paddle* pPaddle)
{
	pPaddle->position.x = GetScreenWidth() / 2;
	pPaddle->position.y = GetScreenHeight() - (GetScreenHeight() * 0.1);;
	
}


void UpdatePaddle(Paddle* pPaddle)
{
	// Check for player input
	if (IsKeyDown(KEY_D) && PaddleCanMoveRight(pPaddle))
	{
		pPaddle->position.x += PADDLE_SPEED * GetFrameTime();
	}
	else if(IsKeyDown(KEY_A) && PaddleCanMoveLeft(pPaddle))
	{
		pPaddle->position.x -= PADDLE_SPEED * GetFrameTime();
	}
}

void DrawPaddle(const Paddle* paddle)
{
	int rectCenterX = paddle->position.x - (PADDLE_WIDTH / 2);
	int rectCenterY = paddle->position.y - (PADDLE_HEIGHT / 2);

	DrawRectangle(rectCenterX, rectCenterY, PADDLE_WIDTH, PADDLE_HEIGHT, PADDLE_COLOUR);
}

bool PaddleCanMoveLeft(const Paddle* pPaddle)
{
	// Check paddle against the horizontal bounds of the screen
	if (pPaddle->position.x <= PADDLE_WIDTH / 2)
	{
		// Hitting left side of screen
		return false;
	}

	return true;
}

bool PaddleCanMoveRight(const Paddle* pPaddle)
{
	if (pPaddle->position.x >= GetScreenWidth() - (PADDLE_WIDTH / 2))
	{
		// Hitting right side of screen
		return false;
	}

	return true;
}

