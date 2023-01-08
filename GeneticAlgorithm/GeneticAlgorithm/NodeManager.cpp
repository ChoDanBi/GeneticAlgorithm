#include "NodeManager.h"
#include <algorithm>

NodeManager* NodeManager::Instance = NULL;

void NodeManager::Init(int _pol, int _sel, int _mut, int _range)
{
	Population = _pol;
	cntSelection = _sel;
	cntMutation = _mut;
	Range = _range;
	SetSize();

	for (int i = 0; i < _pol; ++i)
		NodeList.push_back(NF::CreateNode(NF::GetRandom(Range), Size));
}

void NodeManager::SortNodeList()
{
	sort(NodeList.begin(), NodeList.end(), Node::cmp);
}

void NodeManager::ShowNodeList() {
	for (vector<Node*>::iterator it = NodeList.begin();
		it != NodeList.end(); ++it)
		(*it)->Show();
}

void NodeManager::NodeListRelease()
{
	for (vector<Node*>::iterator iter = NodeList.begin();
		iter != NodeList.end(); ++iter) DEL(*iter);
	NodeList.clear();
}
