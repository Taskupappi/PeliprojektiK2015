#ifndef PLAYER_H
#define PLAYER_H

#include "Tank.h"




class Player
{
public:
	Player();
	~Player(void);
	void update();


private:
	int health;

};




#endif;