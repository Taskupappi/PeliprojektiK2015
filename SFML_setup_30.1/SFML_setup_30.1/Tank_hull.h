#ifndef TANK_HULL_H
#define TANK_HULL_H

#include "Tank_part.h"


class Tank_hull
{
public:

	Tank_hull(std::string name, int af, int al, int ari, int are, float sp);
	Tank_hull();

	~Tank_hull(void);


protected:
	std::string name;
	int armor_front;
	int armor_left;
	int armor_right;
	int armor_rear;
	float speed;

};
#endif