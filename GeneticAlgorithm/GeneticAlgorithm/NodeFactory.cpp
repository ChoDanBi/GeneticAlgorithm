#include "NodeFactory.h"
#include <random>

Node* NodeFactory::CreateCroNode(Node* _node1, Node* _node2)
{
	int size = _node1->GetBinary().size();
	int helf = size / 2;

	vector<int> Binary;
	for (int i = 0; i < size; ++i)
		Binary.push_back(i <= helf ?
			_node1->GetBinary()[i] : _node2->GetBinary()[i]);

	return new Node(Binary);
}

Node* NodeFactory::CreateCroNode(Node* _node1, Node* _node2, const int& _size)
{
	int size = _node1->GetBinary().size();
	int helf = size / 2;

	vector<int> Binary;
	for (int i = 0; i < size; ++i)
		Binary.push_back(i <= helf ?
			_node1->GetBinary()[i] : _node2->GetBinary()[i]);

	return new Node(Binary, size);
}

Node* NodeFactory::CreateCroNode(const vector<int>& _binary1, const vector<int>& _binary2)
{
	int size = _binary1.size();
	int helf = size / 2;

	vector<int> Binary;
	for (int i = 0; i < size; ++i)
		Binary.push_back(i <= helf ? _binary1[i] : _binary2[i]);

	return new Node(Binary);
}

Node* NodeFactory::CreateCroNode(const vector<int>& _binary1, const vector<int>& _binary2, const int& _size)
{
	int size = _binary1.size();
	int helf = size / 2;

	vector<int> Binary;
	for (int i = 0; i < size; ++i)
		Binary.push_back(i <= helf ? _binary1[i] : _binary2[i]);

	return new Node(Binary, _size);
}

Node* NodeFactory::CreateMutNode(Node* _node)
{
	int ind = GetRandom((_node->GetBinary().size() - 1));
	vector<int> Binary = _node->GetBinary();
	Binary[ind] = Binary[ind] == 0 ? 1 : 0;

	return new Node(Binary);
}
Node* NodeFactory::CreateMutNode(Node* _node, const int& _size)
{
	int ind = GetRandom((_node->GetBinary().size() - 1));
	vector<int> Binary = _node->GetBinary();
	Binary[ind] = Binary[ind] == 0 ? 1 : 0;
	return new Node(Binary, _size);
}
Node* NodeFactory::CreateMutNode(vector<int> _binary)
{
	int ind = GetRandom((_binary.size() - 1));
	_binary[ind] = _binary[ind] == 0 ? 1 : 0;
	return new Node(_binary);
}

Node* NodeFactory::CreateMutNode(vector<int> _binary, const int& _size)
{
	int ind = GetRandom((_binary.size() - 1));
	_binary[ind] = _binary[ind] == 0 ? 1 : 0;
	return new Node(_binary, _size);
}

void NodeFactory::SafeDelet(Node* _node)
{
	if (_node == nullptr) return;
	delete _node; _node = nullptr;
}

int NodeFactory::GetRandom(int _max)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, _max);
	return dis(gen);
}
int NodeFactory::GetRandom(int _min, int _max)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(_min, _max);
	return dis(gen);
}