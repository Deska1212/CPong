#include "collision.h"
#include <math.h>;

CollisionBox InitCollisionBox(float width, float height, Vector2 center)
{
	// Initialised default/starting values for box
	CollisionBox newCollisionBox;
	newCollisionBox.minX = center.x - (width / 2);
	newCollisionBox.minY = center.y - (height / 2);
	newCollisionBox.maxX = center.x + (width / 2);
	newCollisionBox.maxY = center.y + (height / 2);

	return newCollisionBox;
}

void UpdateCollisionBox(CollisionBox* box, float width, float height, Vector2 center)
{
	// Updates the collision boxes position values
	box->minX = center.x - (width / 2);
	box->minY = center.y - (height / 2);
	box->maxX = center.x + (width / 2);
	box->maxY = center.y + (height / 2);

}

bool CollidingWith(const CollisionBox* a, const CollisionBox* b)
{
	// Check if collision box is colliding with another

	// Check horizontal collisions
	if (a->minX > b->maxX)
	{
		// A's left edge is completely off the the right of B's right edge
		return false;
	}

	if (a->maxX < b->minX)
	{
		// A's right edge is completely off to the left of B's left edge
		return false;
	}

	// Check vertical collisions
	if (a->minY > b->maxY)
	{
		// A is entriely below B
		return false;
	}

	if (a->maxY < b->minY)
	{
		// A is entirely above B
		return false;
	}

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