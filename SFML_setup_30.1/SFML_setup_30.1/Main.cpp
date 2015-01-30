#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 1200), "SFML works!");
	window.setFramerateLimit(60);

	sf::CircleShape shape(20.f);
	shape.setFillColor(sf::Color::Green);

	sf::Texture texture;
	texture.loadFromFile("tank_hull.png");
	texture.setSmooth(true);
	sf::Texture texture2;
	texture2.loadFromFile("tank_tower.png");
	texture2.setSmooth(true);

	sf::Sprite sprite;
	sprite.setTexture(texture);
	sf::Sprite sprite2;
	sprite2.setTexture(texture2);
	sprite2.setColor(sf::Color(255, 255, 255, 128));

	sprite.setPosition(450, 450);
	sprite2.setPosition(450, 450);
	sprite2.setOrigin(400, 400);
	sprite.setOrigin(400, 400);

	sprite.setScale(0.5, 0.5);
	sprite2.setScale(0.5, 0.5);


	int rot = 0;
	int rot2 = 0;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Escape:
					window.close();
					break;
				case sf::Keyboard::Return:
					shape.setRadius(shape.getRadius() + 10);
					break;
				}

			}

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			rot--;
			if (rot > 360)
				rot = 0;
			sprite2.setRotation(rot);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			rot++;
			if (rot > 360)
				rot = 0;
			sprite2.setRotation(rot);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			rot2--;
			if (rot2 > 360)
				rot2 = 0;
			sprite.setRotation(rot2);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			rot2++;
			if (rot2 > 360)
				rot2 = 0;
			sprite.setRotation(rot2);
		}

		shape.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);

		window.clear();
		window.draw(sprite);
		window.draw(sprite2);
		window.draw(shape);
		window.display();
	}

	return 0;
}