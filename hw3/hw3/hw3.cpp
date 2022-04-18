/*
PIC 10A 1A, Homework 3
Purpose: Final score and grade calculator given set grading system.
Author: Harrison Cassar
Date: 4/25/2022
*/

#include <iostream>
#include <string>
#include <limits>

using namespace std;

double compute_scheme_score(double weight_midterm, double weight_finalexam, double weight_homework, double score_midterm, double score_finalexam, double score_avg_homework);
std::string convert_score_to_grade(double score);

int main()
{
	// setup buffers for taking in user inputs
	double score_midterm;
	double score_finalexam;
	int num_homeworks;
	double score_sum_homework = 0.0;
	double score_lowest_homework = std::numeric_limits<int>::max();

	// take in midterm input
	std::cout << "Please enter the midterm exam score (0 - 100): ";
	cin >> score_midterm;

	// take in final exam input
	std::cout << "Please enter the final exam score (0 - 100): ";
	cin >> score_finalexam;

	// take in number of homework assignments input
	std::cout << "Please enter the number of homework assignments (3 - 7): ";
	cin >> num_homeworks;

	// take in scores for N homework inputs
	for (int i = 0; i < num_homeworks; i++)
	{
		double score_homework;

		std::cout << "Please enter the homework " << i + 1 << " score (0 - 100): ";
		cin >> score_homework;

		// check for new lowest homework entered
		if (score_homework < score_lowest_homework)
			score_lowest_homework = score_homework;

		score_sum_homework += score_homework;
	}

	// compute average homework score (for later computation)
	double score_avg_homework = (score_sum_homework - score_lowest_homework) / (num_homeworks - 1);

	// compute final grades for each grading scheme
	double schemeA_score = compute_scheme_score(0.35, 0.4, 0.25, score_midterm, score_finalexam, score_avg_homework);
	double schemeB_score = compute_scheme_score(0.0, 0.7, 0.3, score_midterm, score_finalexam, score_avg_homework);

	// determine best final grade
	double final_score = (schemeA_score > schemeB_score) ? schemeA_score : schemeB_score;

	// convert to letter grade
	std::string letter_grade = convert_score_to_grade(final_score);

	// output to user
	std::cout << "Your final score based on Scheme A is " << schemeA_score << std::endl;
	std::cout << "Your final score based on Scheme B is " << schemeB_score << std::endl;
	std::cout << "Your final score is " << final_score << std::endl;
	std::cout << "Your course grade is " << letter_grade << std::endl;

	return 0;
}

// assists in performing final score computation for a given grading scheme
double compute_scheme_score(double weight_midterm, double weight_finalexam, double weight_homework, double score_midterm, double score_finalexam, double score_avg_homework)
{
	return (weight_midterm * score_midterm) + (weight_finalexam * score_finalexam) + (weight_homework * score_avg_homework);
}

// assists in converting score to letter grade
std::string convert_score_to_grade(double score)
{
	if (0.0 <= score && score < 60.0)
		return "F";
	else if (60.0 <= score && score < 70.0)
		return "D";
	else if (70.0 <= score && score < 80.0)
		return "C";
	else if (80.0 <= score && score < 90.0)
		return "B";
	else if (90.0 <= score && score <= 100.0)
		return "A";
	else
		return "-";
}