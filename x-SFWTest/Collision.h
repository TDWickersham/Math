#pragma once

#include "mathutils.h"
#include "Vec2.h"
#include "shapes.h"
#include <cmath>

struct Collision
{
	float penetrationDepth;
	float handedness;
	vec2 axis;
};

struct swept
{
	float entry, exit;
	float handedness;
	vec2 axis;
};

Collision intersect_1D(float Amin, float Amax, float Bmin, float Bmax);
swept intersect_swept_1D(float Amin, float Amax, float Avel, float Bmin, float Bmax, float Bvel);

Collision intersect_AABB(const AABB &A, const AABB &B);

Collision intersect_circle(const circle &A, const circle &B);

Collision intersect_circle_AABB(const circle &A, const AABB &B);

swept intersect_ray_AABB(const ray &R, const AABB &B);

void static_resolution(vec2 &pos, vec2 &vel, const Collision &hit, float elasticity = 1.0f);

void dynamic_resolution(vec2 &Apos, vec2 &Avel, float Amass, vec2 &Bpos, vec2 &Bvel, float Bmass, const Collision &hit, float elasticity = 1.0f);