#pragma once

#include "shapes.h"
#include "transform.h"
#include "Collision.h"

class collider
{
public:
	AABB box;

	AABB getGlobalBox(const Transform &t) const
	{
		return t.getGlobalTransform() * box;
	}

	collider(const AABB &a_box = { {0,0}, {.5,.5} }) : box(a_box)
	{

	}
	
	void collider::debugDraw(const Transform &At, int color, const mat3 &cam = mat3::identity());
};

Collision collides(const Transform &At, const collider &Ac, const Transform &Bt, const collider &Bc);