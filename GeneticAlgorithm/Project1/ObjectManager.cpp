#include "ObjectManager.h"
#include "Factory.h"
#include <random>

ObjectManager* ObjectManager::Instance = NULL;

void ObjectManager::Init()
{
	cout << "초기 오브젝트 만들 개수: "; cin >> Size;
	cout << "선택할 때 뽑을 개수 입력: "; cin >> Cnt;
	cout << "이진수 길이 표시 입력: "; cin >> Len;
	cout << "최소 범위 입력: "; cin >> Min;
	cout << "최대 범위 입력: "; cin >> Max;

	for (int i = 0; i < Size; ++i) {
		int cand = Factory::GetRandom();
		SetObjectList(cand);
	}
}

void ObjectManager::Init(int _size, int _cnt, int _len)
{
	Size = _size;
	Cnt = _cnt;
	Len = _len;
}

void ObjectManager::Init(int _size, int _cnt, int _len, int _min, int _max)
{
	Size = _size;
	Cnt = _cnt;
	Len = _len;
	Min = _min;
	Max = _max;
	
	for (int i = 0; i < Size; ++i) {
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


bool ObjectManager::FindObjCand(int _cand)
{
	for (vector<Object*>::iterator it = ObjectList.begin();
		it != ObjectList.end(); ++it) {
		if ((*it)->GetCand() == _cand) 
			return true;
	}
	return false;
}

Object* ObjectManager::FindObjMaxRes()
{
	if (ObjectList.empty())return nullptr;
	Object* obj = ObjectList[0];
	for (vector<Object*>::iterator it = ObjectList.begin();
		it != ObjectList.end(); ++it) {
		if (obj->GetRes() < (*it)->GetRes()) obj = (*it);
	}
	return obj;
}

void ObjectManager::ShowObjList(){
	for (vector<Object*>::iterator it = ObjectList.begin();
		it != ObjectList.end(); ++it)
		(*it)->show();
}

void ObjectManager::ShowNextObjList(){
	for (vector<Object*>::iterator it = NextObjectList.begin();
		it != NextObjectList.end(); ++it)
		(*it)->show();
}

void ObjectManager::ObjListRelease()
{
	for (vector<Object*>::iterator iter = ObjectList.begin();
		iter != ObjectList.end(); ++iter) {
		if (*iter) {
			delete(*iter);
			(*iter) = nullptr;
		}
	}
	ObjectList.clear();
}

void ObjectManager::NextObjListRelease()
{
	for (vector<Object*>::iterator iter = NextObjectList.begin();
		iter != NextObjectList.end(); ++iter) {
		if (*iter) {
			delete(*iter);
			(*iter) = nullptr;
		}
	}
	NextObjectList.clear();
}
