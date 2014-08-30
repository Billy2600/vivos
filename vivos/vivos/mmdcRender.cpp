#include "mmdcRender.h"

sf::Color mmdcRender::ConvertColor(color_t oldColor) const
{
	return sf::Color(oldColor.r, oldColor.g, oldColor.b, oldColor.a);
}

sf::Vector2f mmdcRender::ConvertVecf(vec2_t<float> inVec) const
{
	return sf::Vector2f(inVec.x, inVec.y);
}

sf::IntRect mmdcRender::ConvertRecti(rect_t<int> inRect) const
{
	return sf::IntRect(inRect.x,inRect.y,inRect.w,inRect.h);
}



mmdcRender::mmdcRender()
{
}

void mmdcRender::Draw(std::vector<drawable_t> objects, sf::RenderWindow &window) const
{
	// Loop through and draw the objects given
	for(unsigned int i=0; i < objects.size(); i++)
	{
		// Draw image
		if (objects[i].texFilename != "")
		{
			// Convert to sfml object
			sf::Sprite sprite;
			sf::Texture texture;
			// Load texture
			texture.loadFromFile(ASSETS_FOLDER + objects[i].texFilename);
			sprite.setTexture(texture);
			sprite.setColor(ConvertColor(objects[i].fillColor));
			sprite.setPosition(objects[i].pos.x, -objects[i].pos.y);
			sprite.setTextureRect(
				sf::IntRect(objects[i].texPosition.x,
				objects[i].texPosition.y,
				objects[i].texPosition.w,
				objects[i].texPosition.h)
				);
			sprite.setOrigin((float)objects[i].origin.x, (float)objects[i].origin.y);
			sprite.setRotation(objects[i].angle);
			window.draw(sprite);
		}

		// Draw text, if applicable
		if(objects[i].string != "")
		{
			sf::Text text;
			sf::Font font;
			font.loadFromFile(ASSETS_FOLDER + objects[i].strFont);
			text.setFont(font);
			text.setString(objects[i].string);
			text.setPosition(objects[i].pos.x, objects[i].pos.y);
			text.setColor(ConvertColor(objects[i].fillColor));
			text.setCharacterSize(objects[i].strSize);
			window.draw(text);
		}
	}
}
