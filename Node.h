#pragma once
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;
class Node {
private:
  string input;   //create node function. counter for g(n)
  int depth;
  int cost;
  Node* parent;    
  vector<Node*> children;
public:
	int state[3][3]; 
	Node();
	Node(string);
	Node(string, int);
  Node(int[3][3]);
  void Add_Child(Node*, int);
  void set_parent(Node*);
  void set_cost(Node*, int);
  int getdepth();
  void setdepth(Node*);
  void print();
	~Node();
};

