/* ============================================================
	DataTypes
	Contains declarations for all the custom data types and
	constants used throughout the game
	===========================================================*/
#pragma once
#include <string>

// INPUT ABSTRACTIONS
#define INPUT_NONE 0
#define INPUT_UP	1
#define INPUT_DOWN	2
#define INPUT_LEFT	3
#define INPUT_RIGHT 4

// VECTOR2
// X and Y position
template <class T>
class vec2_t
{
public:
	T x;
	T y;

	vec2_t() { vec2_t(0, 0); }

	vec2_t(T x, T y)
	{
		this->x = x;
		this->y = y;
	}
};

// RECT
// Rectangle/box
template <class T>
class rect_t
{
public:
	T x;
	T y;
	T w;
	T h;

	rect_t(T x, T y, T w, T h)
	{
		this->x = x;
		this->y = y;
		this->w = w;
		this->h = h;
	}
};

// SPRITE
// Graphic image to be shown on screen
struct sprite_t
{
	std::string texFilename; // texture filename
	rect_t<int> texPosition; // position of sprite on texture (in pixels)
	vec2_t<int> origin; // Origin of sprite (in pixels)
	vec2_t<int> worldPos; // Position in world (in pixels)
};