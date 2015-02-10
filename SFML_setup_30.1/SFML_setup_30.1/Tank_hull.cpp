#include "Tank_hull.h"

Tank_hull::Tank_hull(std::string n, int af, int al,
	int ari, int are, float ac, float splf,
	float splb, float w, float tra, sf::Texture tt,
	int hp)
{
	name = n;
	armor_front = af;
	armor_left = al;
	armor_right = ari;
	armor_rear = are;
	acceleration = ac;
	speed_limit_forwards = splf;
	speed_limit_backwards = splb;
	weight = w;
	traverse_speed = tra;
	tank_hull_texture = tt;
	hit_points = hp;
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