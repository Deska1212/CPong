#ifndef BALL_H
#define BALL_H

#define BALL_RADIUS 15
#define BALL_SPEED 500
#define BALL_COLOR BLACK

#include <raylib.h>
#include "collision.h"

typedef struct Ball
{
	Vector2 position;
	Vector2 velocity;
	int velocityModifer;
} Ball;

void SetBallStartParams(Ball* pBall);
void UpdateBall(Ball* pBall);
void DrawBall(const Ball* pBall);
void CheckBallOutOfBounds(Ball* pBall);
void FlipBallXVelocity(Ball* pBall);
void FlipBallYVelocity(Ball* pBall);
void AdjustBallVelocityModifier(Ball* pBall, int change);

#endif // !BALL_H