#include "mmdcActPlayer.h"


mmdcActPlayer::mmdcActPlayer(float x, float y)
	: mmdcActor(x,y)
{
	// Initialize components

	// Sprite
	cmpSprite = std::shared_ptr<drawable_t>(new drawable_t(x,y));
	//cmpSprite->fillColor = color_t(0, 255, 0, 255);
	cmpSprite->texPosition = rect_t<int>(0, 0, 48, 48);
	cmpSprite->texFilename = "winchester.png";

	// Hitbox
	cmpHitbox = std::shared_ptr<rect_t<float>>(new rect_t<float>(x,y,48,40));

	// Physics
	cmpPhysics = std::shared_ptr<physics_t>(new physics_t());
	cmpPhysics->acc = 0.5f;
	cmpPhysics->maxVel = vec2_t<float>(10,10);
}

void mmdcActPlayer::OnInput(inputs_t inputs)
{
	// Add to velocity based on key press
	if (inputs.up)
		cmpPhysics->vel.y += cmpPhysics->acc;
	if (inputs.down)
		cmpPhysics->vel.y -= cmpPhysics->acc;
	if (inputs.right)
		cmpPhysics->vel.x += cmpPhysics->acc;
	if (inputs.left)
		cmpPhysics->vel.x -= cmpPhysics->acc;

	// Slow player down, eventually to stopped position, on key release
	if (!inputs.up && cmpPhysics->vel.y > 0)
		cmpPhysics->vel.y -= cmpPhysics->acc;
	if (!inputs.down && cmpPhysics->vel.y < 0)
		cmpPhysics->vel.y += cmpPhysics->acc;
	if (!inputs.right && cmpPhysics->vel.x > 0)
		cmpPhysics->vel.x -= cmpPhysics->acc;
	if (!inputs.left && cmpPhysics->vel.x < 0)
		cmpPhysics->vel.x += cmpPhysics->acc;
}

void mmdcActPlayer::OnCollision(std::shared_ptr<mmdcActor>)
{
	
}

void mmdcActPlayer::Think(int dt)
{
	// Move hitbox based on velocity
	cmpHitbox->x += cmpPhysics->vel.x;
	cmpHitbox->y += cmpPhysics->vel.y;

	// Move sprite to position
	cmpSprite->pos = vec2_t<float>(cmpHitbox->x, cmpHitbox->y);
}
