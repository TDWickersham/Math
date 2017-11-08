#include "draw.h"
#include "sfwdraw.h"

void drawCircle(const circle & C)
{
	sfw::drawCircle(C.position.x, C.position.y, C.radius);
}

void drawAABB(const AABB & box, int color)
{
	vec2 TR = box.position + box.extents;
	vec2 BL = box.position - box.extents;
	vec2 TL = { box.position.x - box.extents.x, box.position.y + box.extents.y };
	vec2 BR = { TR.x, BL.y };

	drawVecLine(TR, TL, color);
	drawVecLine(TL, BL, color);
	drawVecLine(BL, BR, color);
	drawVecLine(BR, TR, color);
}

void drawVecLine(const vec2 & a, const vec2 & b, int color)
{
	sfw::drawLine(a.x, a.y, b.x, b.y, color);
}

void drawTexture(unsigned sprite, const mat3 & t)
{
	sfw::drawTextureMatrix3(sprite, 0, WHITE, t.m);
}

void drawRay(const ray & r, int color)
{
	drawVecLine(r.position, r.position + r.direction * r.length, color);
}
