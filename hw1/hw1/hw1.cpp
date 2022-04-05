/*
PIC 10A 1A, Homework 1
Purpose: Converter of units for user input from miles to kilometers and feet.
Author: Harrison Cassar
Date: 4/9/2022
*/

#include <iostream>

#define KM_PER_MILE 1.609
#define FT_PER_MILE 5280

using namespace std;

int main()
{
	double miles;

	// output msg
	std::cout << "Please input the amount of miles you want to convert:" << std::endl;

	// take in input
	std::cin >> miles;

	// perform computation
	double km = miles * KM_PER_MILE;
	double ft = miles * FT_PER_MILE;

	// output computation
	std::cout << "This converts to \"" << km << " kilometers\" or \"" << ft << " feet\"." << std::endl;

	return 0;
}