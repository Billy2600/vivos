/* ============================================================
	Render
	Renders things to the screen, based on data given from the
	game logic.
	===========================================================*/
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "mmdcDataTypes.h"

class mmdcRender
{
private:
	// Convert interal data types to SFML types
	sf::Color ConvertColor(color_t) const;

public:
	mmdcRender();

	// Draw to screen
	// Must be given vector of drawable objects, and the window handler
	void Draw(std::vector<drawable_t>, sf::RenderWindow &) const;
};

