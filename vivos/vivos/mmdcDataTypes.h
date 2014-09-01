/* ============================================================
	DataTypes
	Contains declarations for all the custom data types, enums
	defines, and constants used throughout the game
	===========================================================*/
#pragma once
#include <string>

// DEFINES

// Assets folder
#ifdef WIN32
#define ASSETS_FOLDER "assets\\" // Windows has to do its directories all stupid
#else
#define ASSETS_FOLDER "assets/"
#endif

// TYPEDEFS

// Various forms of int, for ease of typing and possibly cross compiling in the future
#ifndef VS2013 // VS2013 doesn't like this one
typedef __int8 int8_t; // _t suffix for consistency's sake
#endif
typedef unsigned __int8 uint8_t;
typedef __int16 int16_t;
typedef __int32 int32_t;

// ENUMS

// Possible states
enum states_t { ST_TITLE, ST_GAMEPLAY };

// Cardinal directions
enum cardinal_t { N, NE, E, SE, S, SW, W, NW };

// STRUCTS

// Input abstractions
struct inputs_t
{
	// Buttons
	bool accept;

	// Left 'stick'
	bool up;
	bool down;
	bool left;
	bool right;

	// Right 'stick'
	bool rUp;
	bool rDown;
	bool rLeft;
	bool rRight;
};

// Vector2
// X and Y position
template <class T>
struct vec2_t
{
	T x;
	T y;

	vec2_t(T x=0, T y=0)
	{
		this->x = x;
		this->y = y;
	}
};

// Rect
// Rectangle/box
template <class T>
struct rect_t
{
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

	// Collision detection
	// Based on code from lazyfoo.net
	static bool Collision(rect_t<T> A, rect_t<T> B)
	{
		// the sides of the rectangles
		T leftA, leftB;
		T rightA, rightB;
		T topA, topB;
		T bottomA, bottomB;

		// Calculate sides of rectA
		leftA = A.x;
		rightA = A.x + A.w;
		topA = A.y;
		bottomA = A.y + A.h;
		// Calculate sides of rectB
		leftB = B.x;
		rightB = B.x + B.w;
		topB = B.y;
		bottomB = B.y + B.h;

		// If any of the sides from A are outside B
		if(bottomA <= topB)
			return false;
		if(topA >= bottomB)
			return false;
		if(rightA <= leftB)
			return false;
		if(leftA >= rightB)
			return false;

		// if none of the sides from A are outside B
		return true;
	}
};

// RGBA color
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

// Drawable object
// Used to pass info to render class
struct drawable_t
{
	vec2_t<float> pos; // Position
	std::string texFilename; // texture filename
	rect_t<int> texPosition; // position of sprite on texture (in pixels), also determines the size of the sprite
	vec2_t<int> origin; // Origin of sprite (in pixels)
	color_t fillColor; // Fill color
	float angle; // Angle (in degrees)

	std::string string; // Text string, must have at least one character for text to show
	std::string strFont; // Filename of font
	unsigned int strSize; // Text size

	// Constructor
	drawable_t(float x=0, float y=0)
	{
		this->pos.x = x;
		this->pos.y = y;
		this->texFilename = "";
		this->angle = 0;
		this->string = "";
		this->strFont = "";
		this->strSize = 18;
	}
};

// Asset info
// Used by asset manager to cache assets
struct assetinfo_t
{
	std::string filename; // Filename of asset
	unsigned int index; // Index in corrisponding asset manager 
};