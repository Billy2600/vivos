#include "mmdcRender.h"

sf::Color mmdcRender::ConvertColor(color_t oldColor) const
{
	return sf::Color(oldColor.r, oldColor.g, oldColor.b, oldColor.a);
}

mmdcRender::mmdcRender()
{
}

void mmdcRender::Draw(std::vector<drawable_t> objects, sf::RenderWindow &window) const
{
	// Loop through and draw the objects given
	for(unsigned int i=0; i < objects.size(); i++)
	{
		// Convert to sfml object
		sf::Sprite sprite;
		sf::Texture texture;
		texture.loadFromFile("dopefish.png");
		sprite.setTexture(texture);
		sprite.setColor(ConvertColor(objects[i].fillColor));
		sprite.setPosition(objects[i].pos.x, objects[i].pos.y);
		sprite.setTextureRect(
			sf::IntRect(objects[i].texPosition.x,
			objects[i].texPosition.y,
			objects[i].texPosition.w,
			objects[i].texPosition.h)
			);
		sprite.setOrigin((float)objects[i].origin.x, (float)objects[i].origin.y);

		window.draw(sprite);
	}
}
