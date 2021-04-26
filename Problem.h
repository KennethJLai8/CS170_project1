#pragma once
#include "Node.h"
#include <vector>

class Problem
{
private:
	Node* initial_state;
	int goalState[3][3] = { {1,2,3},{4,5,6}, {7,8,0} };
	int numNodesExpanded;
	int maxFrontierSize;
	vector <Node*> frontier;
	vector <Node*> explored;
	Node* solution;

public:
	//test
	void addFrontier(Node*);
	void popFrontier();
	void UniformSolve();
	void AMisplacedTileSolve();
	int misplacedTileCount(Node*);
	void AEuclidSolve();
	float EuclidCost(Node*);
	int findNum(Node*, int);
	//real
	Problem(string);
	Node* moveLeft(Node*);
	Node* moveRight(Node*);
	Node* moveUp(Node*);
	Node* moveDown(Node*);
	void printSolution(Node*);
};