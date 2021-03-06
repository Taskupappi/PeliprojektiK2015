#ifndef TANK_HULL_H
#define TANK_HULL_H

#include "Tank_part.h"


class Tank_hull :
	public Tank_part
{
public:

	Tank_hull(std::string name, int af, int al, int ari, int are, float ac, float splf, float splb, float w, float tra);
	Tank_hull();

	~Tank_hull(void);
	void cal_acceleration();


protected:
	std::string name;
	int armor_front;
	int armor_left;
	int armor_right;
	int armor_rear;
	float acceleration;
	float speed_limit_forwards;
	float speed_limit_backwards;
	float weight;
	float traverse_speed;


};
#endif