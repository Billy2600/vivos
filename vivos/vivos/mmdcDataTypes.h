/* ============================================================
	DataTypes
	Contains declarations for all the custom data types and
	constants used throughout the game
	===========================================================*/
#pragma once
#include <string>

// TYPEDEFS
// Various forms of int, for ease of typing and possibly cross compiling in the future
#ifndef VS2013 // VS2013 doesn't like this one
typedef __int8 int8_t; // _t suffix for consistency's sake
#endif
typedef unsigned __int8 uint8_t;
typedef __int16 int16_t;
typedef __int32 int32_t;

// INPUT ABSTRACTIONS
struct inputs_t
{
	bool accept;
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

	vec2_t(T x=0, T y=0)
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

	rect_t(T x=0, T y=0, T w=0, T h=0)
	{
		this->x = x;
		this->y = y;
		this->w = w;
		this->h = h;
	}
};

// RGBA COLOR
struct color_t
{
	uint8_t r; // Red
	uint8_t g; // Green
	uint8_t b; // Blue
	uint8_t a; // Alpha

	color_t(uint8_t r=0xFF, uint8_t g=0xFF, uint8_t b=0xFF, uint8_t a=0xFF)
	{
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}
};

// DRAWABLE OBJECT
struct drawable_t
{
	vec2_t<float> pos; // Position
	std::string texFilename; // texture filename
	rect_t<int> texPosition; // position of sprite on texture (in pixels), also determines the size of the sprite
	vec2_t<int> origin; // Origin of sprite (in pixels)
	color_t fillColor; // Fill color

	// Constructor
	drawable_t(float x=0, float y=0)
	{
		this->pos.x = x;
		this->pos.y = y;
		this->texFilename = "";
	}
};