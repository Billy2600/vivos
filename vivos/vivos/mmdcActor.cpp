#include "mmdcActor.h"

void mmdcActor::Move(float x, float y)
{
	// Move to new position
	if (x != 0) cmpHitbox->x = x;
	if (y != 0) cmpHitbox->y = y;

	// Move sprite to position
	if (cmpSprite != NULL)
		cmpSprite->pos = vec2_t<float>(cmpHitbox->x, cmpHitbox->y);
}