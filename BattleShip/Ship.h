#include "GameWorld.h"
#ifndef CLASS_SHIP
#define CLASS_SHIP
class Ship 
{
private:
	int len;
	char direction;
	GameWorld * MyWorld;
public:
	Ship(int, char,  GameWorld *);
	bool Place();
};


#endif 