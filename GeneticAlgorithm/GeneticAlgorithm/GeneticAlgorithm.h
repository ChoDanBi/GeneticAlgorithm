#pragma once
#include "header.h"
#include "NodeManager.h"

class GeneticAlgorithm
{
private:
	static GeneticAlgorithm* Instance;

public:
	static GeneticAlgorithm* GetInstance() {
		if (Instance == NULL)
			Instance = new GeneticAlgorithm();
		return Instance;
	}

private:
	map<int, int> cntNode;

public:	//Init
	void Init(int _pol, int _sel, int _mut, int _range) { NM->Init(_pol, _sel, _mut, _range); }

public:	//Genetic
	void Start(int _goal);
	void Finish();
	int Simulating();

public:	//function
	void CrossOver();
	void Mutation();
	void Replace();

	int Counting(Node* _node);
};

