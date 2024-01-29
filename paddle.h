#ifndef PADDLE_H
#define PADDLE_H

#include <raylib.h>

#define PADDLE_WIDTH 100
#define	PADDLE_HEIGHT 20
#define PADDLE_SPEED 200
#define PADDLE_COLOUR BLACK

typedef struct
{
	Vector2 position;
} Paddle;


void SetPaddleStartParams(Paddle* pPaddle);
void UpdatePaddle(Paddle* pPaddle);
void DrawPaddle(const Paddle* pPaddle);
bool PaddleCanMoveLeft(const Paddle* pPaddle);
bool PaddleCanMoveRight(const Paddle* pPaddle);




#endif // !PADDLE_H
