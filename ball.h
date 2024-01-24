#ifndef BALL_H
#define BALL_H

#define BALL_RADIUS 10
#define BALL_SPEED 20
#define BALL_COLOR BLACK

#include <raylib.h>

typedef struct Ball
{
	Vector2 position;
	Vector2 velocity;
	int velocityModifer;
} Ball;

void DrawBall(Ball* pBall);
void UpdateBall(Ball* pBall);
void CheckBallOutOfBounds(Ball* pBall);
void FlipBallXVelocity(Ball* pBall);
void FlipBallYVelocity(Ball* pBall);
void AdjustVelocityModifier(Ball* pBall, int change);

#endif // !BALL_H