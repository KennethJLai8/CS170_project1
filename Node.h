#pragma once
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

class Node {
private:
	string input;   //create node function. counter for g(n)
	double depth;
	Node* parent;
	vector<Node*> children;
	int blank_row;
	int blank_col;
	double hcost;
	double cost;
public:
	//test constructor
	Node(string, int);
	//real
	int state[3][3];
	Node();
	Node(string);
	Node(int[3][3]);
	void Add_Child(Node*, int);
	void set_parent(Node*);
	void set_cost(Node*, double);
	double getCost();
	double getdepth();
	int getBlankCol();
	int getBlankRow();
	double getHCost();
	Node* getParent();
	void setdepth(Node*);
	void print();
};

