#include "GeneticAlgorithm.h"

GeneticAlgorithm* GeneticAlgorithm::Instance = NULL;

void GeneticAlgorithm::Start(int _goal)
{
	while (true) { if (Simulating() >= _goal) break; }
	Finish();
}

int GeneticAlgorithm::Simulating()
{
	CrossOver();
	Mutation();
	NM->SortNodeList();
	Replace();
	return Counting(NM->GetNodeList().front());
}

void GeneticAlgorithm::CrossOver()
{
	vector<bool> v(NM->GetPol(), false);

	for (int i = 0; i < NM->GetPol() / 2; ++i) {

		int ind1, ind2;

		while (true) {
			ind1 = NF::GetRandom((NM->GetPol() - 1));
			if (!v[ind1]) { v[ind1] = true; break; }
		}
		while (true) {
			ind2 = NF::GetRandom((NM->GetPol() - 1));
			if (!v[ind2]) { v[ind2] = true; break; }
		}

		NM->SetNodeList(
			NF::CreateCroNode(NM->GetNodeList()[ind1], NM->GetNodeList()[ind2]));
		NM->SetNodeList(
			NF::CreateCroNode(NM->GetNodeList()[ind2], NM->GetNodeList()[ind1]));
	}
}

void GeneticAlgorithm::Mutation()
{
	for (int i = 0; i < NM->GetMut(); ++i) {
		int ind = NF::GetRandom((NM->GetPol() - 1));
		NM->SetNodeList(
			NF::CreateMutNode(
				NM->GetNodeList()[ind]));
	}
}

void GeneticAlgorithm::Replace()
{
	while (NM->GetNodeList().size() > NM->GetSel()) {
		DEL(NM->pGetNodeList()->back());
		NM->pGetNodeList()->pop_back();
	}
	NM->SetPol(NM->GetNodeList().size());
}

int GeneticAlgorithm::Counting(Node* _node)
{
	int num = _node->GetNum();
	if (cntNode.find(num) == cntNode.end())
		cntNode.insert(make_pair(num, 0));
	return ++cntNode[num];
}

void GeneticAlgorithm::Finish()
{
	cout << "FinalNum: "; NM->GetNodeList().front()->Show();
}