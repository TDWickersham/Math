#include "collider.h"
#include "draw.h"

void collider::debugDraw(const Transform & At, int color, const mat3 & cam)
{
	drawAABB(cam * getGlobalBox(At), color);
}

Collision collides(const Transform & At, const collider & Ac, const Transform & Bt, const collider & Bc)
{
	return intersect_AABB(Ac.getGlobalBox(At), Bc.getGlobalBox(Bt));
}
