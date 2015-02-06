#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>
#include <SFML/Main.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <cmath>
#include <math.h>


//Classit

#include "TileMap.h"
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
	sprite_green_background.setPosition(0, 0);
	//---------------------------------------------------//


	//--------------------View_options-------------------------------//

	sf::View view;
	view.reset(sf::FloatRect(0, 0, screen_dimensions.x, screen_dimensions.y));
	view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
	//----------------------------------------------------------------//


	//----------------Tank_rotation_and_movement-----------------------------------------------------//
	float rot_turret = 0;
	float rot_hull = 0;
	float turret_rot_speed = 1.2;
	float hull_rot_speed = 0.8;

	float o_clock = 1 / 60;

	float hull_movement_acceleration = 0.2;
	float hull_movement_speed_forwards = 0;
	float hull_movement_speed_forwards_max = 2.1;

	float hull_movement_speed_backwards = 0;
	float hull_movement_speed_backwards_max = 0.7;

	float speed = 5;
	float angle = 60 * M_PI / 2;

	float move_x = speed * cos(angle);
	float move_y = speed * sin(angle);



	//-----------------------------------------------------------------------------------------------//

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
	sprite_tank_hull.setPosition(screen_dimensions.x / 2, screen_dimensions.y / 2);
	sprite_tank_hull.setOrigin(400, 400);

	//Tank is now set relatively to the screen
	sprite_tank_turret.setPosition(screen_dimensions.x / 2, screen_dimensions.y / 2);
	sprite_tank_turret.setOrigin(400, 400);

	sprite_tank_hull.setScale(0.2, 0.2);
	sprite_tank_turret.setScale(0.2, 0.2);

	texture_tank_turret.setSmooth(true);
	texture_tank_hull.setSmooth(true);



	//-----------------------------------------------------------------------------------------------//

	//Tilemap

	const int level[] =
	{
		0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
		1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
		0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
		0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
		0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
		2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
		0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
	};

	TileMap map;
	if (!map.load("tileset.png", sf::Vector2u(128, 128), level, 16, 8))
		return -1;


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
			sprite_tank_turret.rotate(-turret_rot_speed);

		}


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			sprite_tank_turret.rotate(turret_rot_speed);
		}

		//---------------------------------Hull--------------------------------------//


		bool key_is_pressed = true;


		while (key_is_pressed == true)
		{
			sf::Time t1 = sf::seconds(0.1f);
			float _elapsed = t1.asSeconds();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				sprite_tank_turret.rotate(-hull_rot_speed);
				sprite_tank_hull.rotate(-hull_rot_speed);
			}



			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				sprite_tank_turret.rotate(hull_rot_speed);
				sprite_tank_hull.rotate(hull_rot_speed);
			}




			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{


				hull_movement_speed_forwards += _elapsed * hull_movement_acceleration;


				if (hull_movement_speed_forwards > hull_movement_speed_forwards_max)
				{
					hull_movement_speed_forwards = hull_movement_speed_forwards_max;
				}


				//Tank hull moves now to the direction it faces.
				sprite_tank_hull.move(sin(sprite_tank_hull.getRotation()*3.14159265 / 180) * hull_movement_speed_forwards, cos(sprite_tank_hull.getRotation()*3.14159265 / 180)*-hull_movement_speed_forwards);
				sprite_tank_turret.setPosition(sprite_tank_hull.getPosition());
			}


			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{


				hull_movement_speed_backwards += _elapsed * hull_movement_acceleration;

				if (hull_movement_speed_backwards > hull_movement_speed_backwards_max)
				{
					hull_movement_speed_backwards = hull_movement_speed_backwards_max;
				}


				//Tank hull moves now to the direction it faces.
				sprite_tank_hull.move(sin(sprite_tank_hull.getRotation()*3.14159265 / 180) * -hull_movement_speed_backwards, cos(sprite_tank_hull.getRotation()*3.14159265 / 180)*hull_movement_speed_backwards);;
				sprite_tank_turret.setPosition(sprite_tank_hull.getPosition());
				view.setCenter(sprite_tank_hull.getPosition());
			}

			//_elapsed = 0;
			//hull_movement_speed_forwards = 0;
			//hull_movement_speed_backwards = 0;

			key_is_pressed = false;
		
		}
			//----------------------------------------------------------End of Controls-----------------------------------------//

			//shape.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);

			window.clear();
			window.draw(sprite_green_background);
			window.draw(map);
			window.draw(sprite_tank_hull);
			window.draw(sprite_tank_turret);
			window.display();
		

		
	}
	return 0;
}