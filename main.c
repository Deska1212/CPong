#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

#include "ball.h"
#include "paddle.h"


int main(int argc, char **argv)
{
	InitWindow(600, 800, "CPong");
	SetTargetFPS(60);

	

	Ball ball;
	SetBallStartParams(&ball);

	Paddle paddle;
	SetPaddleStartParams(&paddle);


	

	
	// Initialise Game
	

	while (!WindowShouldClose())
	{
		// Update

		UpdateBall(&ball);
		UpdatePaddle(&paddle);

		if (IsKeyPressed(KEY_E))
		{
			AdjustBallVelocityModifier(&ball, 1);
			printf("Setting velocity modifier to: %d\n", ball.velocityModifer);
		}

		if (IsKeyPressed(KEY_Q) && ball.velocityModifer > 1)
		{
			AdjustBallVelocityModifier(&ball, -1);
			printf("Setting velocity modifier to: %d\n", ball.velocityModifer);
		}

		// Draw
		BeginDrawing();
		ClearBackground(WHITE);

		DrawBall(&ball);
		DrawPaddle(&paddle);


		EndDrawing();
	}

	CloseWindow();


	printf("Exiting Game...");

	return 0;
}






