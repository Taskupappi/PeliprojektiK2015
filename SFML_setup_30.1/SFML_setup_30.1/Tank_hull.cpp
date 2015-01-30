#include "Tank_hull.h"

Tank_hull::Tank_hull(std::string n, int af, int al, int ari, int are, float sp)
{
	name = n;
	armor_front = af;
	armor_left = al;
	armor_right = ari;
	armor_rear = are;
	speed = sp;
}

Tank_hull::Tank_hull()
{
	name = "PzII hull";
	armor_front = 15;
	armor_left = 15;
	armor_rear = 15;
	armor_right = 15;
	speed = 15;
}

Tank_hull::~Tank_hull(void)
{



}