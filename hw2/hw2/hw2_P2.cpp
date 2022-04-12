/*
PIC 10A 1A, Homework 2, Problem 2
Purpose: Product calculator of digits of user input.
Author: Harrison Cassar
Date: 4/18/2022
*/

#include <iostream>

using namespace std;

int main()
{
	int num;
	int product = 1;

	// take in user input
	std::cout << "Input an integer between 100 and 999:" << std::endl;
	std::cin >> num;

	// process input/compute sum
	if (num == 0)
		product = 0;

	while (num != 0)
	{
		product *= num % 10;
		num /= 10;
	}

	// output result
	std::cout << "The product of digits is " << product << "." << std::endl;

	return 0;
}