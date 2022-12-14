#include "Manager.h"
#include <random>

Manager* Manager::Instance = NULL;

void Manager::Init(int _len, int _cnt, int _min, int _max)
{
	Len = _len;
	Cnt = _cnt;
	Min = _min;
	Max = _max;

	//난수 생성
	random_device rd;	//시드값을 얻기 위한 rd 생성
	mt19937 gen(rd());	//난수 생성 엔진 초기화
	uniform_int_distribution<int> dis(_min, _max);	//min~max까지의 난수 생성

	srand(time(NULL));	//C++은 랜덤이 복잡하므로 C로 대체
	for (int i = 0; i < Cnt; ++i) {
		int cand = dis(gen);
		SetObjectList(cand);	
	}
}


void Manager::SetObjectList(Object* _Obj) { ObjectList.push_back(_Obj); }

void Manager::SetObjectList(int _cand) {
	Object* Obj; Obj = new Object;
	Obj->SetInit(_cand);
	ObjectList.push_back(Obj);
}

void Manager::SetObjectList(vector<int> _binary){
	Object* Obj; Obj = new Object;
	Obj->SetInit(_binary);
	ObjectList.push_back(Obj);
}


void Manager::SetNextObjectList(Object* _Obj){}

void Manager::SetNextObjectList(int _cand){
	Object* Obj; Obj = new Object;
	Obj->SetInit(_cand);
	ObjectList.push_back(Obj);
}

void Manager::SetNextObjectList(vector<int> _binary)
{
	Object* Obj; Obj = new Object;
	Obj->SetInit(_binary);
	ObjectList.push_back(Obj);
}
