#pragma once

#include "shapes.h"

void drawCircle(const circle &C);

void drawAABB(const AABB &box, int color);

void drawVecLine(const vec2 &a, const vec2 &b, int color);

void drawTexture(unsigned sprite, const mat3 &t);

void drawRay(const ray &r, int color);