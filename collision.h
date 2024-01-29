#ifndef COLLISION_H
#define COLLISION_H

#include <raylib.h>

typedef struct
{
	float minX;
	float minY;
	float maxX;
	float maxY;
} CollisionBox;


bool CollidingWith(const CollisionBox& other);
void DebugDraw(const CollisionBox& box);

#endif