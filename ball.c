#include "ball.h"

void SetBallStartParams(Ball* pBall)
{
	pBall->position.x = GetScreenWidth() / 2;
	pBall->position.y = GetScreenHeight() / 2;
	pBall->velocity.x = 25;
	pBall->velocity.y = 75;
	pBall->velocityModifer = 1;
}

void DrawBall(const Ball* pBall)
{
	DrawCircle(pBall->position.x, pBall->position.y, BALL_RADIUS, BALL_COLOR);
}

void UpdateBall(Ball* pBall)
{
	// Update position from velocityq
	pBall->position.x += pBall->velocity.x * GetFrameTime() * pBall->velocityModifer;
	pBall->position.y += pBall->velocity.y * GetFrameTime() * pBall->velocityModifer;

	CheckBallOutOfBounds(pBall);
}

void CheckBallOutOfBounds(Ball* pBall)
{
	if (pBall->position.x <= 0 || pBall->position.x >= GetScreenWidth())
	{
		// Hit wall left or right
		FlipBallXVelocity(pBall);
	}

	if (pBall->position.y <= 0 || pBall->position.y >= GetScreenHeight())
	{
		// Hit right
		FlipBallYVelocity(pBall);
	}
}

void FlipBallXVelocity(Ball* pBall)
{
	pBall->velocity.x *= -1;
}

void FlipBallYVelocity(Ball* pBall)
{
	pBall->velocity.y *= -1;
}

void AdjustBallVelocityModifier(Ball* pBall, int change)
{
	pBall->velocityModifer += change;
}