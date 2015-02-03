#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>
#include <SFML/Main.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <cmath>
#include <math.h>

//#include "Tank_hull.h"
//Terveiset kotikoneelta. GitHub toimii.

#define M_PI 3.14159265358979323846 /* pi */

//#include <SFML/Audio.hhp>

int main()
{
	//-----------------------------Tank Creation-----------------------------------------------//
	//Tank_hull Tank_hull1();


	//-----------------------------------------------------------------------------//

	

	//--------------------------Screen_setup---------------------------------------//
	sf::Vector2i screen_dimensions(1280, 720);
	sf::RenderWindow window;
	window.create(sf::VideoMode(screen_dimensions.x, screen_dimensions.y), "Tank Hunter Arcade");
	window.setFramerateLimit(60);


	//-------------------------------------------------------------//


	//-----------------------------Something--------------------------------//
	//window.setKeyRepeatEnabled(false);
	//srand(time(0));
	//---------------------------------------------------------------//


	//----------Background-----------------------------------//
	sf::Texture texture_green_background;
	texture_green_background.loadFromFile("green_background.png");
	sf::Sprite sprite_green_background;
	sprite_green_background.setTexture(texture_green_background);
	sprite_green_background.setPosition(450, 200);
	//---------------------------------------------------//


	//--------------------View_options-------------------------------//

	sf::View view;
	view.reset(sf::FloatRect(0, 0, screen_dimensions.x, screen_dimensions.y));
	view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
	//----------------------------------------------------------------//



	//--------------------Tank----------------------------//
	sf::Texture texture_tank_hull;
	texture_tank_hull.loadFromFile("tank_hull.png");
	

	sf::Texture texture_tank_turret;
	texture_tank_turret.loadFromFile("tank_tower.png");
	

	sf::Sprite sprite_tank_hull;
	sprite_tank_hull.setTexture(texture_tank_hull);

	sf::Sprite sprite_tank_turret;
	sprite_tank_turret.setTexture(texture_tank_turret);

	//Tank is now set relatively to the screen
	sprite_tank_hull.setPosition(screen_dimensions.x/2, screen_dimensions.y/2);
	sprite_tank_hull.setOrigin(400, 400);

	//Tank is now set relatively to the screen
	sprite_tank_turret.setPosition(screen_dimensions.x/2, screen_dimensions.y/2);
	sprite_tank_turret.setOrigin(400, 400);

	sprite_tank_hull.setScale(0.2, 0.2);
	sprite_tank_turret.setScale(0.2, 0.2);

	texture_tank_turret.setSmooth(true);
	texture_tank_hull.setSmooth(true);
	//----------------Tank_rotation_and_movement-----------------------------------------------------//
	int rot_turret = 0;
	int rot_hull = 0;

	float speed = 5;
	float angle = 60 * M_PI / 2;

	float move_x = speed * cos(angle);
	float move_y = speed * sin(angle);
	//Sprites[0].move(std::cos(3.14159265 * Sprites[0].getRotation() / 180.f) * (float)Player.getSpeed() * ElapsedTime, std::sin(3.14159265 * Sprites[0].getRotation() / 180.f) * (float)Player.getSpeed() * ElapsedTime);



	//-----------------------------------------------------------------------------------------------//



	//------------------------------------Game_loop-------------------------------------------------//
	while (window.isOpen())
	{
		sf::Clock clock;
		sf::Time elapsed = clock.getElapsedTime();


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
				}

			}

		}
		//---------------------------------------------------------------------------------//


		//----------------------------Controls-----------------------------------------//



		//---------------------------------Turret--------------------------------------//

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{


			rot_turret--;

			if (rot_turret > 360)
			{
				rot_turret = 0;
			}
			sprite_tank_turret.setRotation(rot_turret);

		}

		/*
		double move_x = speed * cos(angle);
		double move_y = speed * sin(angle);
		*/

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{

			rot_turret++;

			if (rot_turret > 360)
			{
				rot_turret = 0;
			}
			sprite_tank_turret.setRotation(rot_turret);
		}

		//---------------------------------Hull--------------------------------------//

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				rot_turret++;
			}



			rot_turret--;

			if (rot_turret > 360)
			{
				rot_turret = 0;
			}
			sprite_tank_turret.setRotation(rot_turret);


			rot_hull--;

			if (rot_hull > 360)
			{
				rot_hull = 0;
			}
			sprite_tank_hull.setRotation(rot_hull);

		}



		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				rot_turret--;

			}

			rot_turret++;

			if (rot_turret > 360)
			{
				rot_turret = 0;
			}
			sprite_tank_turret.setRotation(rot_turret);



			rot_hull++;

			if (rot_hull > 360)
			{
				rot_hull = 0;
			}
			sprite_tank_hull.setRotation(rot_hull);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			//Tank hull moves now to the direction it faces.
			sprite_tank_hull.move(sin(sprite_tank_hull.getRotation()*3.14159265 / 180) * 3, cos(sprite_tank_hull.getRotation()*3.14159265 / 180)*-3);;
			sprite_tank_turret.setPosition(sprite_tank_hull.getPosition());

		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			//Tank hull moves now to the direction it faces.
			sprite_tank_hull.move(sin(sprite_tank_hull.getRotation()*3.14159265 / 180) * -3, cos(sprite_tank_hull.getRotation()*3.14159265 / 180)*3);;
			sprite_tank_turret.setPosition(sprite_tank_hull.getPosition());
		}

		//----------------------------------------------------------End of Controls-----------------------------------------//

		//shape.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);

		window.clear();
		window.draw(sprite_green_background);
		window.draw(sprite_tank_hull);
		window.draw(sprite_tank_turret);
		window.display();
	}

	return 0;
}
