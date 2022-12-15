#include "Manager.h"
#include <random>

Manager* Manager::Instance = NULL;

void Manager::Init()
{
	cout << "이진수 길이 표시 입력: "; cin >> Len;
	cout << "뽑는 횟수 입력: "; cin >> Cnt;
	cout << "최소 범위 입력: "; cin >> Min;
	cout << "최대 범위 입력: "; cin >> Max;

	for (int i = 0; i < Cnt; ++i) {
		int cand = GetRandom();
		SetObjectList(cand);
	}
}

void Manager::Init(int _len, int _cnt, int _min, int _max)
{
	Len = _len;
	Cnt = _cnt;
	Min = _min;
	Max = _max;
	
	for (int i = 0; i < Cnt; ++i) {
		int cand = GetRandom();
		SetObjectList(cand);	
	}
}

//*============*//

int Manager::GetRandom()
{
	random_device rd;	//시드값을 얻기 위한 rd 생성
	mt19937 gen(rd());	//난수 생성 엔진 초기화
	uniform_int_distribution<int> dis(Min, Max);	//min~max까지의 난수 생성
	return dis(gen);
}

int Manager::GetRandom(int _min, int _max)
{
	random_device rd;	//시드값을 얻기 위한 rd 생성
	mt19937 gen(rd());	//난수 생성 엔진 초기화
	uniform_int_distribution<int> dis(_min, _max);	//min~max까지의 난수 생성
	return dis(gen);
}

//*============*//

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
