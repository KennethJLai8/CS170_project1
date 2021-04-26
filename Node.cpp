#include "Node.h"
#include <sstream>
#include <iostream>

Node::Node() {
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i != 3 && j != 3)
				state[i][j] = (i * 3 + j) + 1;
			else
				state[2][2] = 0;
		}
	}
	input = "";
	parent = NULL;
}
/*
Node::Node(string in, int d) {
	parent = NULL;
	cost = d;
	cout << "inputing string" << endl;
	input = in;
	stringstream tempStream;
	tempStream << input;
	string check;
	int* temp_int = new int[8];
	int newNumber = 0;
	int numindex = 0;
	while (!tempStream.eof())
	{
		tempStream >> check;
		if (stringstream(check) >> newNumber && numindex < 9) {
			temp_int[numindex] = newNumber;
			numindex++;
		}
		if (numindex >= 9) {
			break;
		}
	}
	if (numindex >= 9)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				state[i][j] = temp_int[i * 3 + j];
				cout << state[i][j] << " ";
			}
			cout << endl;
		}
	}
}
*/
Node::Node(string in) {
	parent = NULL;
	depth = 0;
	cost = 0;
	depth = 0;
	//cout << "inputing string" << endl;
	input = in;
	stringstream tempStream;
	tempStream << input;
	string check;
	int* temp_int = new int[8];
	int newNumber = 0;
	int numindex = 0;
	while (!tempStream.eof())
	{
		tempStream >> check;
		if (stringstream(check) >> newNumber && numindex < 9) {
			temp_int[numindex] = newNumber;
			numindex++;
		}
		if (numindex >= 9) {
			break;
		}
	}
	//cout << "The current numindex is " << numindex << endl;
	if (numindex >= 9)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				state[i][j] = temp_int[i * 3 + j];
				cout << state[i][j] << " ";
				if (state[i][j] == 0) {
					blank_col = j;
					blank_row = i;
				}
			}
			cout << endl;
		}
	}
}

Node::Node(int newState[3][3]) {
	blank_col = 0;
	blank_row = 0;
	cost = 0;
	depth = 0;
	hcost = 0;
	parent = NULL;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			state[i][j] = newState[i][j];
			if (state[i][j] == 0)
			{
				blank_col = j;
				blank_row = i;
			}
		}
	}

}

double Node::getCost() {
	return cost;
}

double Node::getdepth() {
	return depth;
}

void Node::setdepth(Node* p) {
	depth = p->getdepth() + 1;
}

void Node::Add_Child(Node* c, int addCost) {
	c->set_parent(this);
	setdepth(c);
	c->set_cost(c, addCost);
	children.push_back(c);

	//cost = h(n) + g(n)
}

void Node::set_cost(Node* c, double newCost) {
	hcost = newCost;
	cost = c->depth + newCost;
}
void Node::set_parent(Node* p) {
	parent = p;
}

void Node::print() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << state[i][j] << " ";
		}
		cout << endl;
	}
}

int Node::getBlankCol() {
	return blank_col;
}


int Node::getBlankRow() {
	return blank_row;
}

double Node::getHCost() {
	return hcost;
}

Node* Node::getParent() {
	return parent;
}