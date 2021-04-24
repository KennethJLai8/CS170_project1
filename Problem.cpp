#include "Problem.h"
#include <iostream>
Problem::Problem(string start){
	blank_loc_col = 0;
	blank_loc_row = 0;
  initial_state = new Node(start);
  
}

void Problem::addQueue(Node* newState) {
	q.push(newState);
}

void Problem::popQueue() {
	Node* topNode;
	while (!q.empty()) {
		topNode = q.top();
		cout << "Depth is " << topNode->getdepth() << endl;
		q.pop();
	}
}