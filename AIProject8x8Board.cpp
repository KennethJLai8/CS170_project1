// AIProject8x8Board.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Node.h"
#include "Problem.h"

using namespace std;
int main()
{
	string input;
	cout << "Hello input 9 numbers with 0 being the blank" << endl;
	Problem* init = new Problem(" 8 7 1 6 0 2 5 4 3");
	//Node* start = new Node("1 2 3 4 8 0 7 6 5");
	//Node* check = init->moveDown(start);
	//check->print();
	init->AEuclidSolve();
	init->misplacedTileCount();
	

	return 0;
	
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
