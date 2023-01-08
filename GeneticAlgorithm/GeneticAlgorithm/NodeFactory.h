#pragma once
#include "Node.h"

class NodeFactory
{
public:	//Create Node
	static Node* CreateNode(const int& _num) { return new Node(_num); }
	static Node* CreateNode(const int& _num, const int& _size) { return new Node(_num, _size); }

	static Node* CreateNode(const vector<int>& _binary) { return new Node(_binary); }
	static Node* CreateNode(const vector<int>& _binary, const int& _size) { return new Node(_binary, _size); }

public:	//Create Crossover Node
	static Node* CreateCroNode(Node* _node1, Node* _node2);
	static Node* CreateCroNode(Node* _node1, Node* _node2, const int& _size);

	static Node* CreateCroNode(const vector<int>& _binary1, const vector<int>& _binary2);
	static Node* CreateCroNode(const vector<int>& _binary1, const vector<int>& _binary2, const int& _size);

public: //Create Mutation Node
	static Node* CreateMutNode(Node* _node);
	static Node* CreateMutNode(Node* _node, const int& _size);

	static Node* CreateMutNode(vector<int>_binary);
	static Node* CreateMutNode(vector<int>_binary, const int& _size);

public:	//Release Node
	static void SafeDelet(Node* _node);

public:
	static int GetRandom(int _max);
	static int GetRandom(int _min, int _max);
};

