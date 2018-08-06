#include "Ship.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>

using std::cout;
using std::cin;
using std::endl;

Ship::Ship(int LenValue, char DirValue, GameWorld * GameWorldValue)
{
	len = LenValue;
	direction = DirValue;
	MyWorld = GameWorldValue;
}
bool Ship::Place()
{
	//creating Random Numbers for Row and Col
	int RandomRow, RandomCol;
	int MaxRangeRow, MinRangeRow;
	int MaxRangeCol, MinRangeCol;
	MinRangeRow = 0;
	MinRangeCol = 0;
	MaxRangeRow = MyWorld->Rows;
	MaxRangeCol = MyWorld->Cols;
	srand(time(0));
	int diffRow = (MaxRangeRow - MinRangeRow) + 1;
	RandomRow = (rand() % diffRow) + MinRangeRow;
	int diffCol = (MaxRangeCol - MinRangeCol) + 1;
	RandomCol = (rand() % diffCol) + MinRangeCol;
	//cout << RandomRow << " " << RandomCol;
	//Check the boundries 
	if (direction == 'V')
	{
		if (RandomRow + len > MyWorld->Rows - 1)
		{
			//msg too long to be placed 
			return false;
		}
		// Check for stacking ships
		int RowCounter;
		int index;
		RowCounter = 0;
		for (int i = 1; i <= len; i++)
		{

			index = RowCounter + (MyWorld->Cols * RandomRow) + RandomCol;
			if (*(MyWorld->WorldPtr + index) == 'S')
			{
				//msg Stacking
				return false;
			}
			RowCounter = RowCounter + MyWorld->Cols;
		}
	}
	else  // Direction = Horizental 
	{
		if (RandomCol + len > MyWorld->Cols - 1)
		{
			//msg too long to be placed 
			return false;
		}
		// Check for stacking ships
		
		int index;
		
		for (int i = 0; i < len; i++)
		{

			index = i + (MyWorld->Cols * RandomRow) + RandomCol;
			if (*(MyWorld->WorldPtr + index) == 'S')
			{
				//msg Stacking
				return false;
			}
			
		}
	}
	//Ship is Place-able , place it 
	if (direction == 'V')
	{
		int RowCounter;
		int index;
		RowCounter = 0;
		for (int i = 1; i <= len; i++)
		{

			index = RowCounter + (MyWorld->Cols * RandomRow) + RandomCol;
			*(MyWorld->WorldPtr + index) = 'S';
			RowCounter = RowCounter + MyWorld->Cols;
		}

	}
	else // Place Horizental 
	{
		int index;

		for (int i = 0; i < len; i++)
		{

			index = i + (MyWorld->Cols * RandomRow) + RandomCol;
			*(MyWorld->WorldPtr + index) = 'S';

		}

	}

	return true;
}