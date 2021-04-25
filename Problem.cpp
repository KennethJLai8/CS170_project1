#include "Problem.h"
#include <iostream>

Problem::Problem(string start) {
	blank_loc_col = 0;
	blank_loc_row = 0;
	initial_state = new Node(start);

}

void Problem::addQueue(Node* newState) {
	Node* curstate = NULL;
	bool differentState = false;
	//cout << "CURRENT NEW STATE COST: " << newState->getCost() << endl;
	for (int i = 0; i < queue.size(); i++)
	{

		//cout << "NEW STATE COST: " << newState->getCost() << " VS. I COST " << queue[i]->getCost() << endl;
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				if (newState->state[j][k] != queue[i]->state[j][k]) {
					//cout << newState->state[j][k] << " does not equal " << queue[i]->state[j][k] << endl << endl;
					differentState = true;
				}
			}
		}
		if (!differentState)
		{
			//cout << endl << "REPEAT STATE " << endl << endl;
			if (newState->getCost() < queue[i]->getCost())
			{
				queue.erase(queue.begin() + i);
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
	if (queue.empty())
	{
		queue.push_back(newState);	
		for (int i = 0; i < queue.size(); i++)
		{
			cout << queue[i]->getCost() << ", " << endl;
		}
		return;
	}
	for (int i = 0; i < queue.size(); i++)
	{
		if (newState->getCost() < queue[i]->getCost()) {
			queue.insert(queue.begin() + i, newState);
			break;
		}
		else if (i + 1 == queue.size())
		{
			//cout << "inserting at the end\n";
			queue.push_back(newState);
			break;
		}

	}
	//cout << "****************ADDED TO QUEUE ***************" << endl;
	//cout << "CURRENT QUEUE SIZE: " << queue.size() << endl;
	//print test
	/*
	for (int i = 0; i < queue.size(); i++)
	{
		cout << queue[i]->getCost() << ", ";
	}
	cout << endl;
	*/
}

void Problem::popQueue() {
	Node* topNode;
	while (!queue.empty()) {
		topNode = queue.at(0);
		cout << "Depth is " << topNode->getdepth() << endl;
		queue.pop_back();
	}
}