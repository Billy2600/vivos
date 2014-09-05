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

void mmdcRender::Draw(std::vector<drawable_t> objects, sf::RenderWindow &window)
{
	// Loop through and draw the objects given
	for(unsigned int i=0; i < objects.size(); i++)
	{
		// Draw object as sprite
		if (objects[i].texFilename != "")
		{
			sf::Sprite sprite;
			if (manager.LoadTexture(objects[i].texFilename) != NULL)
				sprite.setTexture(*manager.LoadTexture(objects[i].texFilename));
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
		// Draw object as shape
		else
		{
			sf::RectangleShape shape;
			shape.setFillColor(ConvertColor(objects[i].fillColor));
			shape.setPosition(sf::Vector2f((float)objects[i].pos.x, -(float)objects[i].pos.y));
			shape.setRotation(objects[i].angle);
			shape.setSize(sf::Vector2f((float)objects[i].texPosition.w, (float)objects[i].texPosition.h));
			window.draw(shape);
		}

		// Draw text, if applicable
		// Shapes and sprites can also have text
		if(objects[i].string != "")
		{
			sf::Text text;
			text.setFont(*manager.LoadFont(objects[i].strFont));
			text.setString(objects[i].string);
			text.setPosition(objects[i].pos.x, objects[i].pos.y);
			text.setColor(ConvertColor(objects[i].fillColor));
			text.setCharacterSize(objects[i].strSize);
			window.draw(text);
		}
	}
}
