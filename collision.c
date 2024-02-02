#include "collision.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

CollisionBox InitCollisionBox(const float width, const float height, const Vector2 center)
{
	// Initialised default/starting values for box
	CollisionBox box;
	box.minX = center.x - (width / 2);
	box.minY = center.y - (height / 2);
	box.maxX = center.x + (width / 2);
	box.maxY = center.y + (height / 2);
	box.lastCollisionTime = 0;
	box.collisionDirty = false;

	return box;
}

void UpdateCollisionBox(CollisionBox* box, const float width, const float height, const Vector2 center)
{
	// Updates the collision boxes position values
	box->minX = center.x - (width / 2);
	box->minY = center.y - (height / 2);
	box->maxX = center.x + (width / 2);
	box->maxY = center.y + (height / 2);

	if (GetTime() > box->lastCollisionTime + COLLISION_DIRTY_TIME)
	{
		ResetCollisionDirty(&box);
	}

}

bool CollidingWith(CollisionBox* a, CollisionBox* b)
{
	printf("Colliding... %d\n", a->collisionDirty);

	// Check if either boxes are flagged collision dirty (We have recently had a collision)
	// if they are return early
	if (a->collisionDirty || b->collisionDirty)
	{
		return false;
	}


	// Check if collision box is colliding with another

	// Check horizontal collisions
	bool isCollidingHorizontal = a->minX < b->maxX && a->maxX > b->minX;
	bool isCollidingVertical = a->minY < b->maxY && a->maxY > b->minY;

	// If there is no collision either horizontally or vertically, return
	if (!isCollidingHorizontal || !isCollidingVertical)
	{
		return false;
	}
	// We are colliding
	OnCollision(&a, &b);
	OnCollision(&b, &a);
	return true;
}

void DebugDraw(const CollisionBox* box)
{
	int w = fabs(box->maxX - box->minX);
	int h = fabs(box->maxY - box->minY);
	Rectangle rect;
	rect.width = w;
	rect.height = h;
	rect.x = box->minX;
	rect.y = box->minY;

	DrawRectangleLines(rect.x, rect.y, w, h, RED);
}

void OnCollision(CollisionBox* box, CollisionBox* other)
{
	box->collisionDirty = true;
	box->lastCollisionTime = GetTime();
}

void ResetCollisionDirty(CollisionBox* box)
{
	box->collisionDirty = false;
}

Vector2 CaclulateNonCollidingPosition(CollisionBox* boxToMove, CollisionBox* boxToCheckAgainst)
{
	
}