#include "ObjectManager.h"
#include "Factory.h"
#include <random>

ObjectManager* ObjectManager::Instance = NULL;

void ObjectManager::Init()
{
	cout << "������ ���� ǥ�� �Է�: "; cin >> Len;
	cout << "�̴� Ƚ�� �Է�: "; cin >> Cnt;
	cout << "�ּ� ���� �Է�: "; cin >> Min;
	cout << "�ִ� ���� �Է�: "; cin >> Max;

	for (int i = 0; i < Cnt; ++i) {
		int cand = Factory::GetRandom();
		SetObjectList(cand);
	}
}

void ObjectManager::Init(int _len, int _cnt, int _min, int _max)
{
	Len = _len;
	Cnt = _cnt;
	Min = _min;
	Max = _max;
	
	for (int i = 0; i < Cnt; ++i) {
		int cand = Factory::GetRandom();
		SetObjectList(cand);	
	}
}


void ObjectManager::SetObjectList(Object* _Obj) { ObjectList.push_back(_Obj); }
void ObjectManager::SetObjectList(int _cand) { ObjectList.push_back(Factory::CreateObj(_cand)); }
void ObjectManager::SetObjectList(vector<int> _binary) { ObjectList.push_back(Factory::CreateObj(_binary)); }

void ObjectManager::SetNextObjectList(Object* _Obj) { NextObjectList.push_back(_Obj); }
void ObjectManager::SetNextObjectList(int _cand) { NextObjectList.push_back(Factory::CreateObj(_cand)); }
void ObjectManager::SetNextObjectList(vector<int> _binary){ NextObjectList.push_back(Factory::CreateObj(_binary));}
