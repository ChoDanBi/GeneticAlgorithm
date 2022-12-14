#include "Manager.h"

Manager* Manager::Instance = NULL;

void Manager::Init(int _len, int _cnt, int _min, int _max)
{
	Len = _len;
	Cnt = _cnt;
	Min = _min;
	Max = _max;

	srand(time(NULL));	//C++은 랜덤이 복잡하므로 C로 대체
	for (int i = 0; i < Cnt; ++i)
		SetObjectList(rand() % Min + Max);	
}


void Manager::SetObjectList(Object _Obj) { ObjectList.push_back(_Obj); }

void Manager::SetObjectList(int _cand) {
	Object Obj; Obj.SetCand(_cand, Len);
	ObjectList.push_back(Obj);
}

void Manager::SetObjectList(vector<int> _binary)
{
	Object Obj; Obj.SetBinary(_binary, Len);
	ObjectList.push_back(Obj);
}

Manager::Manager(){}
Manager::~Manager(){}