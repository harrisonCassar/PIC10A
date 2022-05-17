/*
	PIC 10A 1A, Homework 5
	Purpose: Basic user-interactive application to demonstrate different paramter passing methods.
	Author: Harrison Cassar
	Date: 5/19/2022
*/

#include <iostream>

void displayMenu();
int largest(int a, int b, int c);
void mySort(int& a, int& b, int& c);
void myPermutation(int& a, int& b, int& c);

using namespace std;

int main()
{
	// init buffer variables
	int a, b, c;

	// prompt user
	cout << "Enter your three integer numbers:" << endl;

	// accept input
	cin >> a >> b >> c;

	for (;;)
	{
		// display menu
		displayMenu();
		
		// take in user choice
		char choice;
		cin >> choice;

		// newline to separate function call from user input
		cout << endl;

		switch (choice)
		{
			case 'Q':
			case 'q':
			{
				// output msg
				cout << "Exit the menu" << endl;

				// exit
				return 0;
			}
			case '1':
			{
				// call function
				int ret = largest(a, b, c);

				// output result
				cout << "The largest number among the three is: " << ret << endl << endl;

				break;
			}
			case '2':
			{
				// call function
				myPermutation(a, b, c);

				// output result
				cout << "After one permutation: " << a << " " << b << " " << c << endl << endl;

				break;
			}
			case '3':
			{
				// call function
				mySort(a, b, c);

				// output result
				cout << "After sorting: " << a << " " << b << " " << c << endl << endl;

				break;
			}
		}
	}
}

void displayMenu()
{
	cout << "================== MENU ==================" << endl;
	cout << "1. Output the largest" << endl;
	cout << "2. Get the next permutation" << endl;
	cout << "3. Sort in ascending order" << endl;
	cout << "Enter your choice (1 - 3), Q to quit: ";
}

int largest(int a, int b, int c)
{
	// determine largest of 3 values
	return a > b ? (a > c ? a : c) : (b > c ? b : c);
}

void mySort(int& a, int& b, int& c)
{
	// init buffers
	int a_new, b_new, c_new;

	// determine new placements
	if (a < b)
	{
		if (a < c)
		{
			a_new = a;

			if (b < c)
			{
				b_new = b;
				c_new = c;
			}
			else // b >= c
			{
				b_new = c;
				c_new = b;
			}
		}
		else // a >= c
		{
			a_new = c;
			b_new = a;
			c_new = b;
		}
	}
	else // a >= b
	{
		if (a < c)
		{
			a_new = b;
			b_new = a;
			c_new = c;
		}
		else // a >= c
		{
			c_new = a;

			if (b < c)
			{
				a_new = b;
				b_new = c;
			}
			else // b >= c
			{
				a_new = c;
				b_new = b;
			}
		}
	}

	// perform swap
	a = a_new;
	b = b_new;
	c = c_new;
}

void myPermutation(int& a, int& b, int& c)
{
	// buffer value
	int tmp = c;

	// perform swap
	c = b;
	b = a;
	a = tmp;
}