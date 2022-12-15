#include "Manager.h"
#include <random>

Manager* Manager::Instance = NULL;

void Manager::Init()
{
	cout << "������ ���� ǥ�� �Է�: "; cin >> Len;
	cout << "�̴� Ƚ�� �Է�: "; cin >> Cnt;
	cout << "�ּ� ���� �Է�: "; cin >> Min;
	cout << "�ִ� ���� �Է�: "; cin >> Max;

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
	random_device rd;	//�õ尪�� ��� ���� rd ����
	mt19937 gen(rd());	//���� ���� ���� �ʱ�ȭ
	uniform_int_distribution<int> dis(Min, Max);	//min~max������ ���� ����
	return dis(gen);
}

int Manager::GetRandom(int _min, int _max)
{
	random_device rd;	//�õ尪�� ��� ���� rd ����
	mt19937 gen(rd());	//���� ���� ���� �ʱ�ȭ
	uniform_int_distribution<int> dis(_min, _max);	//min~max������ ���� ����
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
