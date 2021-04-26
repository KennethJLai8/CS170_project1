#pragma once
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

class Node {
private:
	string input;   //create node function. counter for g(n)
	int depth;
	Node* parent;
	vector<Node*> children;
	int blank_row;
	int blank_col;
	int hcost;
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
	void set_cost(Node*, int);
	int getCost();
	int getdepth();
	int getBlankCol();
	int getBlankRow();
	int getHCost();
	Node* getParent();
	void setdepth(Node*);
	void print();
	int cost;
};

