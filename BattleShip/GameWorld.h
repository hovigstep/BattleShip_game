
#ifndef CLASS_GAMEWORLD
#define CLASS_GAMEWORLD
class GameWorld
{
public:
	char *WorldPtr;
	int Rows;
	int Cols;

public:
	GameWorld(int = 10, int = 10);
	~GameWorld();
	//set and get here 
	void init() ;
	void Display();
	void DisplayRunTime();
	bool ShipExists();
};

#endif 