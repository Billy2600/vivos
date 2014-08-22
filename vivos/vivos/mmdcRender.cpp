#include "mmdcRender.h"

sf::Color mmdcRender::ConvertColor(color_t oldColor) const
{
	return sf::Color(oldColor.r, oldColor.g, oldColor.b, oldColor.a);
}

mmdcRender::mmdcRender()
{
}

void mmdcRender::Draw(drawable_t objects, sf::RenderWindow &window) const
{
	// Loop through and draw the objects given
	/*for(int i=0; i < sizeof(objects); i++)
	{*/
		// Convert to sfml object
		sf::Sprite sprite;
		sf::Texture texture;
		texture.loadFromFile("dopefish.png");
		sprite.setTexture(texture);
		sprite.setColor(ConvertColor(objects.fillColor));
		sprite.setPosition(objects.pos.x, objects.pos.y);
		sprite.setTextureRect(
			sf::IntRect(objects.texPosition.x,
			objects.texPosition.y,
			objects.texPosition.w,
			objects.texPosition.h)
			);
		sprite.setOrigin((float)objects.origin.x, (float)objects.origin.y);

		window.draw(sprite);
	/*}*/
}
