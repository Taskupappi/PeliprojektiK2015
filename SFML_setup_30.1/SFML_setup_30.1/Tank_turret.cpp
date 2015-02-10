#include "Tank_turret.h"




Tank_turret::Tank_turret(std::string n, int af, int al,
	int ari, int are, float rot, int am,
	float acc, float aimt, int hp) //, sf::Texture tt)
{
	name = n;
	armor_front = af;
	armor_left = al;
	armor_rear = ari;
	armor_right = are;
	rotation_speed = rot;
	ammo_count = am;
	accuracy = acc;
	aim_time = aimt;
	hit_points = hp;
	//tank_turret_texture = tt;


	tank_turret_texture.loadFromFile("Graphics//tank_tower.png");
	tank_turret_texture.setSmooth(true);
	tank_turret_sprite.setTexture(tank_turret_sprite);
}

Tank_turret::Tank_turret()
{
	name = "panzer part";
	armor_front = 15;
	armor_left = 15;
	armor_rear = 15;
	armor_right = 15;
	rotation_speed = 1;
	ammo_count = 45;
	accuracy = 0.34;
	aim_time = 2;

}

Tank_turret::~Tank_turret(void)
{


}


void Tank_turret::rotate(float angle)
{

	sf::Sprite->rotate();  // (-rotation_speed);


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		sprite_tank_turret.rotate(-turret_rot_speed);

	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		sprite_tank_turret.rotate(turret_rot_speed);
	}
}