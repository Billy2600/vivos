/* ============================================================
	DataTypes
	Contains declarations for all the custom data types and
	constants used throughout the game
	===========================================================*/
#pragma once
#include <string>

// INPUT ABSTRACTIONS
struct inputs_t
{
	bool up;
	bool down;
	bool left;
	bool right;
};

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