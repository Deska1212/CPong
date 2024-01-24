#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

#include "ball.h"



void DrawBall(Ball* pBall);
void UpdateBall(Ball* pBall);
void CheckBallOutOfBounds(Ball* pBall);
void FlipBallXVelocity(Ball* pBall);
void FlipBallYVelocity(Ball* pBall);


int main(int argc, char **argv)
{
	InitWindow(600, 800, "CPong");
	SetTargetFPS(60);

	

	Ball ball;
	ball.position.x = GetScreenWidth() / 2;
	ball.position.y = GetScreenHeight() / 2;
	ball.velocity.x = 20;
	ball.velocity.y = 100;
	

	
	// Initialise Game
	

	while (!WindowShouldClose())
	{
		// Update

		UpdateBall(&ball);

		if (IsKeyPressed(KEY_E))
		{
			AdjustVelocityModifier(&ball, 1);
			printf("Setting velocity modifier to: %d\n", ball.velocityModifer);
		}

		if (IsKeyPressed(KEY_Q) && ball.velocityModifer > 1)
		{
			AdjustVelocityModifier(&ball, -1);
			printf("Setting velocity modifier to: %d\n", ball.velocityModifer);
		}

		// Draw
		BeginDrawing();
		ClearBackground(WHITE);

		DrawBall(&ball);


		EndDrawing();
	}

	CloseWindow();


	printf("Exiting Game...");

	return 0;
}






