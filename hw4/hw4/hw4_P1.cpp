/*
	PIC 10A 1A, Homework 4, Problem 1
	Purpose: Monte Carlo Experiments simulator for estimating area of an ellipse.
	Author: Harrison Cassar
	Date: 5/7/2022
*/

#define _USE_MATH_DEFINES

#define DEBUGGING false

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

const double ELLIPSE_EXACT_AREA = (sqrt(2) / 2.0) * M_PI;
const double SQUARE_EXACT_AREA = 2.0 * 2.0;

int main()
{
	// seed rand
	srand(time(0));

	// format output
	cout << fixed << setprecision(5);

	// peform trials with increasing dart counts
	for (int trial = 1; trial <= 6; trial++)
	{
		// determine number of darts
		int N = pow(10, trial);

		// init buffers
		int num_square = 0;
		int num_ellipse = 0;

		// perform random dart "throwing"
		for (int i = 0; i < N; i++)
		{
			// "throw" dart (determine x,y)
			double x = -1.0 + ((2.0 * rand()) / RAND_MAX);
			double y = -1.0 + ((2.0 * rand()) / RAND_MAX);

			if (DEBUGGING)
				cout << "(x, y) : " << x << ", " << y << endl;

			// determine if lying in ellipse or square area
			if ((pow(x, 2) + 2 * pow(y, 2)) <= 1.0)
				num_ellipse++;
			else
				num_square++;
		}

		if (DEBUGGING)
			cout << "num_ellipse: " << num_ellipse << ", num_square: " << num_square << endl;

		// estimate ellipse area
		double area_ratio = num_ellipse / static_cast<double>(N);
		double area_estimate = SQUARE_EXACT_AREA * area_ratio;

		// compute error
		double error = abs(area_estimate - ELLIPSE_EXACT_AREA);

		// output trial to client
		cout << "# darts: " << left << setw(10) << N << "estimated area = " << left << setw(10) << area_estimate << "error = " << error << endl;
	}
}