#include "Problem.h"
#include <iostream>

Problem::Problem(string start) {
	initial_state = new Node(start);
	frontier.push_back(initial_state);
	numNodesExpanded = 0;
	maxFrontierSize = 0;
	solution = NULL;
}

void Problem::addFrontier(Node* newState) {
	Node* curstate = NULL;
	bool differentState = false;
	//cout << "CURRENT NEW STATE COST: " << newState->getCost() << endl;
	for (int i = 0; i < frontier.size(); i++)
	{

		//cout << "NEW STATE COST: " << newState->getCost() << " VS. I COST " << frontier[i]->getCost() << endl;
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				if (newState->state[j][k] != frontier[i]->state[j][k]) {
					//cout << newState->state[j][k] << " does not equal " << frontier[i]->state[j][k] << endl << endl;
					differentState = true;
				}
			}
		}
		if (!differentState)
		{
			//cout << endl << "REPEAT STATE " << endl << endl;
			if (newState->getCost() < frontier[i]->getCost())
			{
				frontier.erase(frontier.begin() + i);
				//cout << "ERASED at " << i << endl;
				break;
			}
			else
			{
				return;
			}
		}
		differentState = false;
	}
	if (frontier.empty())
	{
		frontier.push_back(newState);	
		return;
	}
	for (int i = 0; i < frontier.size(); i++)
	{
		if (newState->getCost() < frontier[i]->getCost()) {
			frontier.insert(frontier.begin() + i, newState);
			break;
		}
		else if (i + 1 == frontier.size())
		{
			//cout << "inserting at the end\n";
			frontier.push_back(newState);
			break;
		}

	}
	//cout << "****************ADDED TO QUEUE ***************" << endl;
	//cout << "CURRENT QUEUE SIZE: " << frontier.size() << endl;
	//print test
	/*
	for (int i = 0; i < frontier.size(); i++)
	{
		cout << frontier[i]->getCost() << ", ";
	}
	cout << endl;
	*/
}

void Problem::popFrontier() {
	Node* topNode;
	if (!frontier.empty()) {
		//cout << "Depth is " << topNode->getCost() << endl;
		frontier.erase(frontier.begin());
	}
}


Node* Problem::moveRight(Node* currNode)
{
	int bCol = currNode->getBlankCol();
	int bRow = currNode->getBlankRow();
	if (bCol < 2)//start counting at zero? only columns 0 and 1 can go right.
	{


		int temp[3][3];
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++) {
				temp[i][j] = currNode->state[i][j];
			}
		}

		temp[bRow][bCol + 1] = currNode->state[bRow][bCol];

		temp[bRow][bCol] = currNode->state[bRow][bCol + 1];

		Node* child = new Node(temp);
		child->set_parent(currNode);
		child->setdepth(currNode);

		return child;
	}
	else
	{
		return NULL;
	}
}


//move left

Node* Problem::moveLeft(Node* currNode)
{

	int bCol = currNode->getBlankCol();
	int bRow = currNode->getBlankRow();
	if (bCol > 0)//start counting at zero? only columns 0 and 1 can go right.
	{

		int temp[3][3];
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++) {
				temp[i][j] = currNode->state[i][j];
			}
		}

		temp[bRow][bCol - 1] = currNode->state[bRow][bCol];

		temp[bRow][bCol] = currNode->state[bRow][bCol - 1];


		Node* child = new Node(temp);
		child->set_parent(currNode);
		child->setdepth(currNode);
		return child;
	}
	else
	{
		return NULL;
	}
}



Node* Problem::moveUp(Node* currNode)
{

	int bCol = currNode->getBlankCol();
	int bRow = currNode->getBlankRow();
	if (bRow > 0)
	{
		int temp[3][3];
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++) {
				temp[i][j] = currNode->state[i][j];
			}
		}

		temp[bRow][bCol] = currNode->state[bRow - 1][bCol];

		temp[bRow - 1][bCol] = currNode->state[bRow][bCol];

		
		Node* child = new Node(temp);
		child->set_parent(currNode);
		child->setdepth(currNode);
		return child;
	}
	else
	{
		return NULL;
	}
}

Node* Problem::moveDown(Node* currNode)
{

	int bCol = currNode->getBlankCol();
	int bRow = currNode->getBlankRow();
	if (bRow < 2)
	{
		int temp[3][3];
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++) {
				temp[i][j] = currNode->state[i][j];
			}
		}

		temp[bRow][bCol] = currNode->state[bRow + 1][bCol];

		temp[bRow + 1][bCol] = currNode->state[bRow][bCol];

		Node* child = new Node(temp);
		child->set_parent(currNode);
		child->setdepth(currNode);
		return child;
	}
	else
	{
		return NULL;
	}
}


void Problem::UniformSolve() {
	Node* newState;
	Node* curNode;
	Node* solution = NULL;
	bool inExplored = false;
	bool goal = true;
	maxFrontierSize = 0;
	numNodesExpanded = 0;
	while (!frontier.empty()) {
		curNode = frontier.at(0);
		goal = true;
		cout << "Best state with g(n) of: " << curNode->getdepth() << ", and h(n) of " << curNode->getHCost() << endl;
		cout << "CURRENT NODE: " << endl;
		curNode->print();
		popFrontier();
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++) {
				if (curNode->state[i][j] != goalState[i][j])
				{
					goal = false;
				}
			}
		}
		if (goal) {
			cout << "Optimal solution found" << endl;
			solution = curNode;
			printSolution(solution);
			cout << "Found after expanding " << numNodesExpanded << " nodes!" << endl;
			cout << "Max Frontier size was: " << maxFrontierSize << " nodes!" << endl; 
			return;
		}
		for (int i = 0; i < explored.size(); i++) {
			inExplored = true;
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < 3; k++) {
					if (curNode->state[j][k] != explored[i]->state[j][k]) 
					{
						inExplored = false;
					}
				}
			}
			if (inExplored) {
				//cout << "We've already done this one!!" << endl;
				break;
			}
		}

		if (inExplored) {
			continue;
		}
		else {
			explored.push_back(curNode);
		}
		newState = moveRight(curNode);
		if (newState != NULL) {

			newState->set_cost(newState, 0);
			/*cout << "MOVING RIGHT WITH COST OF " << newState->getCost() << endl;
			newState->print();
			cout << endl;*/
			addFrontier(newState);
		}
		newState = moveLeft(curNode);
		if (newState != NULL) {
			newState->set_cost(newState, 0);
			/*cout << "MOVING LEFT WITH COST OF " << newState->getCost() << endl;
			newState->print();
			cout << endl;*/
			addFrontier(newState);
		}
		newState = moveDown(curNode);
		if (newState != NULL) { 
			newState->set_cost(newState, 0);
		/*	cout << "MOVING LEFT WITH COST OF " << newState->getCost() << endl;
			newState->print();
			cout << endl;*/
			addFrontier(newState);
		}
		newState = moveUp(curNode);
		if (newState != NULL) { 
			newState->set_cost(newState, 0);
	/*		cout << "MOVING LEFT WITH COST OF " << newState->getCost() << endl;
			newState->print();
			cout << endl;*/
			addFrontier(newState);
		}
		if (maxFrontierSize < frontier.size()) {
			maxFrontierSize = frontier.size();
		}
		numNodesExpanded++;
		cout << "NEW FRONTIER SIZE: " << frontier.size() << endl;

	}
	cout << "After expanding " << numNodesExpanded << ", No solution could be found. \nMax frontier size was: " << maxFrontierSize << endl;
}


void Problem::AMisplacedTileSolve() {
	Node* newState;
	Node* curNode;
	Node* solution = NULL;
	bool inExplored = false;
	bool goal = true;
	maxFrontierSize = 0;
	numNodesExpanded = 0;
	while (!frontier.empty()) {
		curNode = frontier.at(0);
		goal = true;
		cout << "Best state with g(n) of: " << curNode->getdepth() << ", and h(n) of " << curNode->getHCost() << endl;
		cout << "CURRENT NODE: " << endl;
		curNode->print();
		popFrontier();
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++) {
				if (curNode->state[i][j] != goalState[i][j])
				{
					goal = false;
				}
			}
		}
		if (goal) {
			cout << "Optimal solution found" << endl;
			solution = curNode;
			printSolution(solution);
			cout << "Found after expanding " << numNodesExpanded << " nodes!" << endl;
			cout << "Max Frontier size was: " << maxFrontierSize << " nodes!" << endl; 
			return;
		}
		for (int i = 0; i < explored.size(); i++) {
			inExplored = true;
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < 3; k++) {
					if (curNode->state[j][k] != explored[i]->state[j][k])
					{
						inExplored = false;
					}
				}
			}
			if (inExplored) {
				//cout << "We've already done this one!!" << endl;
				break;
			}
		}

		if (inExplored) {
			continue;
		}
		else {
			explored.push_back(curNode);
		}
		newState = moveRight(curNode);
		if (newState != NULL) {
			
			newState->set_cost(newState, misplacedTileCount(newState));
			/*cout << "MOVING RIGHT WITH COST OF " << newState->getCost() << endl;
			newState->print();
			cout << endl;*/
			addFrontier(newState);
		}
		newState = moveLeft(curNode);
		if (newState != NULL) {
			newState->set_cost(newState, misplacedTileCount(newState));
			/*cout << "MOVING LEFT WITH COST OF " << newState->getCost() << endl;
			newState->print();
			cout << endl;*/
			addFrontier(newState);
		}
		newState = moveDown(curNode);
		if (newState != NULL) {
			newState->set_cost(newState, misplacedTileCount(newState));
			/*	cout << "MOVING LEFT WITH COST OF " << newState->getCost() << endl;
				newState->print();
				cout << endl;*/
			addFrontier(newState);
		}
		newState = moveUp(curNode);
		if (newState != NULL) {
			newState->set_cost(newState, misplacedTileCount(newState));
			/*		cout << "MOVING LEFT WITH COST OF " << newState->getCost() << endl;
					newState->print();
					cout << endl;*/
			addFrontier(newState);
		}
		if (maxFrontierSize < frontier.size()) {
			maxFrontierSize = frontier.size();
		}
		numNodesExpanded++;
		cout << "NEW FRONTIER SIZE: " << frontier.size() << endl;

	}
	cout << "After expanding " << numNodesExpanded << ", No solution could be found. \nMax frontier size was: " << maxFrontierSize << endl;
}

int Problem::misplacedTileCount(Node* currnode)//misplaced tile count of current node(h(n))
{
	//define goal here or in parameter?

	int count = 0;//how many misplaced tiles are there


	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (currnode->state[i][j] != goalState[i][j])//if the tile doesn't equal
			{
				count++;

				//return i,j;//return type int[2]? Include in class?
			}//check for invalid input?
		}
	}

	return count;

}


void Problem::AEuclidSolve() {
	Node* newState;
	Node* curNode;
	Node* solution = NULL;
	bool inExplored = false;
	bool goal = true;
	maxFrontierSize = 0;
	numNodesExpanded = 0;
	while (!frontier.empty()) {
		curNode = frontier.at(0);
		goal = true;
		cout << "Best state with g(n) of: " << curNode->getdepth() << ", and h(n) of " << curNode->getHCost() << endl;
//		cout << "CURRENT NODE: " << endl;
		curNode->print();
		popFrontier();
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++) {
				if (curNode->state[i][j] != goalState[i][j])
				{
					goal = false;
				}
			}
		}
		if (goal) {
			cout << "Optimal solution found" << endl;
			solution = curNode;
			printSolution(solution);
			cout << "Found after expanding " << numNodesExpanded << " nodes!" << endl;
			cout << "Max Frontier size was: " << maxFrontierSize << " nodes!" << endl;
			return;
		}
		for (int i = 0; i < explored.size(); i++) {
			inExplored = true;
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < 3; k++) {
					if (curNode->state[j][k] != explored[i]->state[j][k])
					{
						inExplored = false;
					}
				}
			}
			if (inExplored) {
//				cout << "We've already done this one!!" << endl;
				break;
			}
		}

		if (inExplored) {
			continue;
		}
		else {
			explored.push_back(curNode);
		}
		newState = moveRight(curNode);
		if (newState != NULL) {

			newState->set_cost(newState, EuclidCost(newState));
			/*cout << "MOVING RIGHT WITH COST OF " << newState->getCost() << endl;
			newState->print();
			cout << endl;*/
			addFrontier(newState);
		}
		newState = moveLeft(curNode);
		if (newState != NULL) {
			newState->set_cost(newState, EuclidCost(newState));
			/*cout << "MOVING LEFT WITH COST OF " << newState->getCost() << endl;
			newState->print();
			cout << endl;*/
			addFrontier(newState);
		}
		newState = moveDown(curNode);
		if (newState != NULL) {
			newState->set_cost(newState, EuclidCost(newState));
			/*	cout << "MOVING LEFT WITH COST OF " << newState->getCost() << endl;
				newState->print();
				cout << endl;*/
			addFrontier(newState);
		}
		newState = moveUp(curNode);
		if (newState != NULL) {
			newState->set_cost(newState, EuclidCost(newState));
			/*		cout << "MOVING LEFT WITH COST OF " << newState->getCost() << endl;
					newState->print();
					cout << endl;*/
			addFrontier(newState);
		}
		if (maxFrontierSize < frontier.size()) {
			maxFrontierSize = frontier.size();
		}
		numNodesExpanded++;
//		cout << "NEW FRONTIER SIZE: " << frontier.size() << endl;

	}
	cout << "After expanding " << numNodesExpanded << ", No solution could be found. \nMax frontier size was: " << maxFrontierSize << endl;
}

double Problem::EuclidCost(Node* curNode) {

	double totalCost = 0;
	int currentLoc = 0;
	int x = 0;
	int y = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (curNode->state[i][j] != goalState[i][j]) {
				currentLoc = findNum(curNode, goalState[i][j]);
				if (currentLoc > 5) {
					x = 2;
					y = currentLoc - 6;
				}
				else if (currentLoc > 2) {
					x = 1;
					y = currentLoc - 3;
				}
				else {
					x = 0;
					y = currentLoc;
				}
				totalCost += pow(pow((i - x), 2) + pow((y - j), 2), 1 / 2);

			}
		}
	}
	return totalCost;
}

int Problem::findNum(Node* curNode, int searchNum) {
	int dist;
	bool found = false;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) {
			if (curNode->state[i][j] == searchNum)
			{
				found = true;
				dist = (i * 3) + (j);
			}
		}
	}
	return dist;
}
void Problem::printSolution(Node* sol) {
	if (sol == NULL)
	{
		return;
	}
	printSolution(sol->getParent());
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) {
			cout << sol->state[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int Problem::getExpandedTotal() {
	return numNodesExpanded;
}

int Problem::getMaxQueue() {
	return maxFrontierSize;
}