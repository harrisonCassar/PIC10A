/*
PIC 10A 1A, Homework 2, Problem 1
Purpose: Verifier of trig product identity.
Author: Harrison Cassar
Date: 4/18/2022
*/

#include <iostream>
#include <math.h>

const double PI = 3.1415926535897932;

using namespace std;

int main()
{
	double A;
	double B;

	// take in input for A
	std::cout << "What is the degree of angle A?" << std::endl;
	std::cin >> A;

	// take in input for B
	std::cout << "What is the degree of angle B?" << std::endl;
	std::cin >> B;

	// perform computation
	double alpha = A * (PI / 180.0);
	double beta = B * (PI / 180.0);

	double lhs = sin(alpha) * cos(beta);
	double rhs = (0.5) * (sin(alpha + beta) + sin(alpha - beta));

	// output computations
	std::cout << "The left-hand-side of the trig identity evaluates to " << lhs << "." << std::endl;
	std::cout << "The right-hand-side of the trig identity evaluates to " << rhs << "." << std::endl;

	return 0;
}