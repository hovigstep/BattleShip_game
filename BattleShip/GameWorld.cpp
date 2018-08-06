#include <iostream>
#include <stdio.h>
#include "GameWorld.h"
using std::cout;
using std::cin;
using std::endl;

GameWorld::GameWorld(int RowsValue, int ColsValue )
{
	if (RowsValue <= 0 || RowsValue > 16 || ColsValue <= 0 || ColsValue >16)
	{
		return;
	}
	Rows = RowsValue;
	Cols = ColsValue;
	WorldPtr = new char [Rows*Cols];
}
GameWorld::~GameWorld()
{
	delete [] WorldPtr;
}
void GameWorld::init()
{

	for (int i = 0; i < Rows*Cols; i++)
	{
		
		*(WorldPtr + i) = 'E';
	}	
}
void GameWorld::DisplayRunTime()
{
	cout << "     ";
	for (int j = 0; j < Cols; j++)
	{
		cout << "Col " << j << " ";
	}
	cout << endl << endl;
	for (int i = 0; i < Rows; i++)
	{
		cout << "Row " << i << " ";
		for (int j = 0; j < Cols; j++)
		{
			if (*(WorldPtr + (i*Rows + j))!='E' &&
				*(WorldPtr + (i*Rows + j))!='S'){
				cout << " " << *(WorldPtr + (i*Rows + j)) << "    ";
			}
			else
			{
				cout << " " << " " << "    ";
			}
		}
		cout << endl;
	}

}
void GameWorld::Display()
{
	cout << "     ";
	for (int j = 0; j < Cols;j++)
	{
		cout << "Col " << j << " ";
	}
	cout << endl<<endl;
	for (int i = 0; i < Rows; i++)
	{
		cout << "Row " << i << " ";
		for (int j = 0; j < Cols; j++)
		{
			cout << " " << *(WorldPtr + (i*Rows + j)) << "    ";
			//cout << 'E' << "    ";
		}
		cout << endl;
	}
}
bool GameWorld::ShipExists()
{
	for (int i = 0; i < Rows*Cols; i++)
	{

		if (*(WorldPtr + i) == 'S')
			return true;

	}
	return false;

}