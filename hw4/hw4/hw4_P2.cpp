/*
	PIC 10A 1A, Homework 4, Problem 2
	Purpose: Random walk robot simulator.
	Author: Harrison Cassar
	Date: 5/7/2022
*/

#define DEBUGGING false

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
	// seed rand
	srand(time(0));

	// init state
	int x = 0;
	int y = 0;

	for (;;)
	{
		// init buffer for direction output
		string direction;

		// determine step direction
		int dir = rand() % 4;

		// perform state update
		switch (dir)
		{
		case 0: // up
			y++;
			direction = "Up";
			break;
		case 1: // down
			y--;
			direction = "Down";
			break;
		case 2: // left
			x--;
			direction = "Left";
			break;
		case 3: // right
			x++;
			direction = "Right";
			break;
		}

		// output state update
		cout << left << setw(10) << direction << "(" << x << "," << y << ")" << endl;

		// check for goal states (at origin or next to boundary)
		if (x == 0 && y == 0)
		{
			cout << "Back to the origin!" << endl;
			return 0;
		}
		else if (x == -5 || x == 5 || y == -5 || y == 5)
		{
			cout << "Hit the boundary!" << endl;
			return 0;
		}
	}
}