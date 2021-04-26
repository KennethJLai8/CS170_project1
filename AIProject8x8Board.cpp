// AIProject8x8Board.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <iostream>
#include "Problem.h"

int main()
{
	int input, input2, algo_choice;
	string input3, input4, input5, concat;
	int premadeChoice;
	string premade_easy = " 1 2 0 4 5 3 7 8 6 ";
	string premade_medium = "0 1 2 4 5 3 7 8 6 ";
	string premade_hard = " 8 7 1 6 0 2 5 4 3 ";
	string premade_impossible = " 1 2 3 4 5 6 8 7 0 ";
	Problem* choice = NULL;


	std::cout << "Welcome to <ID> and <ID>'s 8 puzzle solver. Press 1 to " << std::endl;
	std::cout << "select from one of our premade puzzles or enter 2 to enter your " << std::endl;
	std::cout << "own puzzle";
	std::cin >> input;

	if (input == 1)
	{
		std::cout << "Select the level of difficulty of the premade puzzle: " << std::endl;
		std::cout << "Enter 1 for easy, 2 for medium, 3 for hard or 4 for impossible" << std::endl;
		std::cin >> input2;

		if (input2 == 1)
		{
			choice = new Problem(premade_easy);
		}
		else if (input2 == 2)
		{
			choice = new Problem(premade_medium);
		}
		if (input2 == 3)
		{
			choice = new Problem(premade_hard);
		}
		if (input2 == 4)
		{
			choice = new Problem(premade_impossible);
		}
	}
	else if (input == 2)
	{
		std::cout << "Enter the first row with spaces separating each number. Use a zero to represent the blank space." << std::endl;
		cin.get();
		std::getline(cin,input3);

		std::cout << "Enter the second row with spaces separating each number. Use a zero to represent the blank space." << std::endl;
		std::getline(cin, input4);

		std::cout << "Enter the third row with spaces separating each number. Use a zero to represent the blank space." << std::endl;
		std::getline(cin, input5);

		concat = input3 + " " + input4 + " " + input5;

		choice = new Problem(concat);
	}
	else
	{
		std::cout << "Invalid choice, program terminating." << endl;
			choice = NULL;
		return 0;
	}

	std::cout << "Select the searching algorithm that you would like to use. Enter 1 for Uniform Cost" << std::endl;
	std::cout << "Search. Enter 2 for A* Search with Misplaced Tile hueristic. Enter 3 for A* Search with" << std::endl;
	std::cout << "Euclidean Distance Hueristic." << std::endl;
	std::cin >> algo_choice;

	if (algo_choice == 1)
	{
		choice->UniformSolve();
	}
	else if (algo_choice == 2)
	{
		choice->AMisplacedTileSolve();
	}
	else if (algo_choice == 3)
	{
		choice->AEuclidSolve();
	}

	return 0;
}
//#include <iostream>
/*
#include "Node.h"
#include "Problem.h"

using namespace std;
int main()
{
	string input;
	cout << "Hello input 9 numbers with 0 being the blank" << endl;
	Problem* init1 = new Problem("8 7 1 6 0 2 5 4 3" );
	//Problem* init1 = new Problem("0 1 2 4 5 3 7 8 6");
	cout << endl;
	Problem* init3 = new Problem("8 7 1 6 0 2 5 4 3");
	vector<int> nodesExpanded;
	vector<int> maxqueues;
	//Node* start = new Node("1 2 3 4 8 0 7 6 5");
	//Node* check = init->moveDown(start);
	//check->print();
	init1->AEuclidSolve();
	nodesExpanded.push_back(init1->getExpandedTotal());
	maxqueues.push_back(init1->getMaxQueue());
	//init2->AMisplacedTileSolve();
	//nodesExpanded.push_back(init2->getExpandedTotal());
	//maxqueues.push_back(init2->getMaxQueue());
	///*init3->UniformSolve();
	//nodesExpanded.push_back(init3->getExpandedTotal());
	//maxqueues.push_back(init3->getMaxQueue());
	//*/
	//cout << endl;
	//cout << "Euclid nodes expanded: " << nodesExpanded[0] << ", Max queue size: " << maxqueues[0] << endl << endl;
	//cout << "MisplacedTiles expanded: " << nodesExpanded[1] << ", Max queue size: " << maxqueues[1] << endl << endl;
	//cin.get();
	////cout << "Uniform search expanded: " << nodesExpanded[2] << ", Max queue size: " << maxqueues[2] << endl << endl;

	//return 0;
	
//}*/
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
