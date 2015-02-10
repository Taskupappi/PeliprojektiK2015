#include "Tank_hull.h"

Tank_hull::Tank_hull(std::string n, int af, int al,
	int ari, int are, float acw, float acb, float splf,
	float splb, float w, float tra, sf::Texture tt,
	int hp)
{
	name = n;
	armor_front = af;
	armor_left = al;
	armor_right = ari;
	armor_rear = are;
	acceleration_forwards = acw;
	acceleration_backwards = acb;
	speed_limit_forwards = splf;
	speed_limit_backwards = splb;
	weight = w;
	traverse_speed = tra;
	tank_hull_texture = tt;
	hit_points = hp;


	tank_hull_texture.loadFromFile("Graphics//tank_hull.png");
	tank_hull_texture.setSmooth(true);
	tank_hull_sprite.setTexture(tank_hull_texture);
}

Tank_hull::Tank_hull()
{
	name = "PzII hull";
	armor_front = 15;
	armor_left = 15;
	armor_rear = 15;
	armor_right = 15;
	acceleration = 0.2;
	speed_limit_forwards = 2.1;
	speed_limit_backwards = 0.8;

}

Tank_hull::~Tank_hull(void)
{



}

void Tank_hull::cal_acceleration()
{

}

void Tank_hull::move()
{

	bool key_is_pressed = true;


	while (key_is_pressed == true)
	{
		sf::Time t1 = sf::seconds(0.1f);
		float _elapsed = t1.asSeconds();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			tank_turret_sprite.rotate(-traverse_speed);
			tank_hull_sprite.rotate(-traverse_speed);
		}



		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			tank_turret_sprite.rotate(traverse_speed);
			tank_hull_sprite.rotate(traverse_speed);
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
			view.setCenter(sprite_tank_hull.getPosition());
		}


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{


			hull_movement_speed_backwards += _elapsed * hull_movement_acceleration;

			if (hull_movement_speed_backwards > hull_movement_speed_backwards_max)
			{
				hull_movement_speed_backwards = hull_movement_speed_backwards_max;
			}


			//Tank hull moves now to the direction it faces.
			tank_hull_sprite.move(sin(sprite_tank_hull.getRotation()*3.14159265 / 180) * -hull_movement_speed_backwards, cos(sprite_tank_hull.getRotation()*3.14159265 / 180)*hull_movement_speed_backwards);;
			tank_turret_sprite.setPosition(sprite_tank_hull.getPosition());
			view.setCenter(sprite_tank_hull.getPosition());
		}

		//_elapsed = 0;
		//hull_movement_speed_forwards = 0;
		//hull_movement_speed_backwards = 0;

		key_is_pressed = false;

	}
}