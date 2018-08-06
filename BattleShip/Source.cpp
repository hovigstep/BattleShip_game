#include <iostream>
#include <stdio.h>
#include "GameWorld.h"
#include "Ship.h"
using std::cout;
using std::cin;
using std::endl;

void main()
{
	GameWorld MyWorld(10,10);
	MyWorld.init();
	cout << "Showing Empty Grid" << endl;
	cout << "Placing Ships..., Please Wait" << endl;
	Ship Ship1(3, 'V', &MyWorld);
	while(true)
	{
		if (Ship1.Place())
		{
			break;
		}
	}
	
	Ship Ship2(2, 'H',&MyWorld);
	while (true)
	{
		if (Ship2.Place())
		{
			break;
		}
	}
	Ship Ship3(1, 'H', &MyWorld);
	while (true)
	{
		if (Ship3.Place())
		{
			break;
		}
	}
	cout << "Now Displaying the completed grid with ships..." << endl<<endl;
	cout << endl;
	MyWorld.DisplayRunTime();
	int AttemptCounter;
	AttemptCounter = 0;
	int ShootingRow, ShootingCol;
	while (MyWorld.ShipExists())
	{
	cout << "Please Enter row and col to shoot" << endl;
		cin >> ShootingRow >> ShootingCol;
		AttemptCounter++;
		if (*(MyWorld.WorldPtr + (ShootingRow * MyWorld.Cols) + ShootingCol) == 'S') {
			*(MyWorld.WorldPtr + (ShootingRow * MyWorld.Cols) + ShootingCol) = 'H';
		}
		else
		{
			*(MyWorld.WorldPtr + (ShootingRow * MyWorld.Cols) + ShootingCol) = 'M';
		}
		cout << endl;
		MyWorld.DisplayRunTime();
	}
	cout << "You won with " << AttemptCounter << " Number of attempts" << endl;



}