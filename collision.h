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

CollisionBox InitCollisionBox(float width, float height, Vector2 center);
void UpdateCollisionBox(CollisionBox* box, float width, float height, Vector2 newCenter);
bool CollidingWith(const CollisionBox* a, const CollisionBox* b);
void DebugDraw(const CollisionBox* box);

#endif