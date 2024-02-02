#ifndef COLLISION_H
#define COLLISION_H
#define COLLISION_DIRTY_TIME 0.05

#include <raylib.h>

typedef struct
{
	float minX;
	float minY;
	float maxX;
	float maxY;
	float lastCollisionTime;
	bool collisionDirty;
	bool doesAdjustPositionOnCollision;
} CollisionBox;

CollisionBox InitCollisionBox(float width, float height, Vector2 center);
void UpdateCollisionBox(CollisionBox* box, float width, float height, Vector2 newCenter);
bool CollidingWith(const CollisionBox* a, const CollisionBox* b);
void DebugDraw(const CollisionBox* box);
void OnCollision(CollisionBox* box, CollisionBox* other);
void ResetCollisionDirty(CollisionBox* box);
Vector2 CalculateNonCollidingPosition(CollisionBox* boxToMove, CollisionBox* boxToCheckAgainst);


#endif