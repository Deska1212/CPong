#include "paddle.h"


void SetPaddleStartParams(Paddle* pPaddle)
{
	pPaddle->position.x = GetScreenWidth() / 2;
	pPaddle->position.y = GetScreenHeight() - (GetScreenHeight() * 0.1);;
	
}


void UpdatePaddle(Paddle* pPaddle)
{

}

void DrawPaddle(const Paddle* paddle)
{
	int rectCenterX = paddle->position.x - (PADDLE_WIDTH / 2);
	int rectCenterY = paddle->position.y - (PADDLE_HEIGHT / 2);

	DrawRectangle(rectCenterX, rectCenterY, PADDLE_WIDTH, PADDLE_HEIGHT, PADDLE_COLOUR);
}

