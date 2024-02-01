#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

#include "ball.h"
#include "paddle.h"
#include "collision.h"


int main(int argc, char **argv)
{
	InitWindow(600, 800, "CPong");
	SetTargetFPS(999);

	

	Ball ball;
	SetBallStartParams(&ball);

	Paddle paddle;
	SetPaddleStartParams(&paddle);


	CollisionBox ballCollisionBox = InitCollisionBox(BALL_RADIUS * 2, BALL_RADIUS * 2, ball.position);
	CollisionBox paddleCollisionBox = InitCollisionBox(PADDLE_WIDTH, PADDLE_HEIGHT, paddle.position);
	


	

	
	// Initialise Game
	

	while (!WindowShouldClose())
	{

		// Update

		PollInputEvents();

		// Update game state
		UpdateBall(&ball);
		UpdatePaddle(&paddle);

		// Update collision boxes
		UpdateCollisionBox(&paddleCollisionBox, PADDLE_WIDTH, PADDLE_HEIGHT, paddle.position);

		UpdateCollisionBox(&ballCollisionBox, BALL_RADIUS * 2, BALL_RADIUS * 2, ball.position);
		
		bool coll = CollidingWith(&ballCollisionBox, &paddleCollisionBox);
		printf("Ball colliding with paddle?: %d \n", coll);

		// Check ball is colliding with paddle
		if (CollidingWith(&ballCollisionBox, &paddleCollisionBox))
		{
			FlipBallYVelocity(&ball);
		}

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

		// Debug Draw
		DebugDraw(&paddleCollisionBox);
		DebugDraw(&ballCollisionBox);

		EndDrawing();
	}

	CloseWindow();


	printf("Exiting Game...");

	return 0;
}






