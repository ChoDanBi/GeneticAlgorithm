#pragma once
#include "header.h"
#include "Node.h"
#include "NodeFactory.h"

class Node;
class NodeManager
{
private:
	static NodeManager* Instance;

public:
	static NodeManager* GetInstance() {
		if (Instance == NULL)
			Instance = new NodeManager();
		return Instance;
	}

private:
	int Population;
	int cntSelection;
	int cntMutation;
	int Range;
	int Size;

	vector<Node*> NodeList;

public:	//Init
	void Init(int _pol, int _sel, int _mut, int _range);

public:	//Get&Set
	void SetPol(int _pol) { Population = _pol; }
	int GetPol() { return Population; }

	void SetSel(int _sel) { Population = _sel; }
	int GetSel() { return cntSelection; }

	void SetMut(int _mut) { cntMutation = _mut; }
	int GetMut() { return cntMutation; }

	void SetRange(int _range) { Range = _range; }
	int GetRange() { return Range; }

	void SetSize() { Size = 1; while (Range > pow(2, Size)) ++Size; }
	int GetSize() { return Size; }

public:	//SetList
	void SetNodeList(Node* _node) { NodeList.push_back(_node); }

	void SetNodeList(const int& _num) { NodeList.push_back(NF::CreateNode(_num)); }
	void SetNodeList(const int& _num, const int& _size) { NodeList.push_back(NF::CreateNode(_num, _size)); }

	void SetNodeList(const vector<int>& _binary) { NodeList.push_back(NF::CreateNode(_binary)); }
	void SetNodeList(const vector<int>& _binary, const int& _size) { NodeList.push_back(NF::CreateNode(_binary, _size)); }

public:	//GetList
	Node* GetNode(int ind) { return NodeList[ind]; }
	vector<Node*> GetNodeList() { return NodeList; }
	vector<Node*>* pGetNodeList() { return &NodeList; }


public:	//Ect
	void SortNodeList();
	void ShowNodeList();
	void NodeListRelease();

private:
	NodeManager() :
		Population(0), cntSelection(0), cntMutation(0), Range(0), Size(0), NodeList(NULL) {};
public:
	~NodeManager() {};
};

