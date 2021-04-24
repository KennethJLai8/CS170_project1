#pragma once
#include <queue>
#include "Node.h"


struct compareCost {
	bool operator()(Node& lhs, Node& rhs) {
		return lhs.getdepth() < rhs.getdepth();
	}
};

class Problem
{
private:
	Node* initial_state;
	int goalState[3][3] = { {1,2,3},{4,5,6}, {7,8,0} };
	priority_queue<Node*, vector<Node*>, compareCost> q;
	int blank_loc_row;
	int blank_loc_col;


public:
	//test
	void addQueue(Node*);
	void popQueue();

	//real
	Problem(string);
	int get_b_row();
	int get_b_col();
	void shift_up();
	void shift_down(/*int [3][3]*/);
	//void shift_left();
	//void shift_down();

	/*
	bool up(int[3][3], int brow, int bcol)//bool? 
	{
		if (brow < 1)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	/*
	Node* up(Node curNode){
	  if(get_b_row == 0){
		return NULL;
	  }
	  else{
		int [3][3] = get the state curNode
		change state();
		new child node = new Node(state, parent = curNode)
		return shifted node;
	  }
	  }
	}
	
	bool down(int[3][3], int brow, int bcol)//bool?
	{
		if (brow < 1)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	*/
	//operators
};