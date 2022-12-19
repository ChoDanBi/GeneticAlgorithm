#include "ObjectManager.h"
#include "ObjectFactory.h"

ObjectManager* ObjectManager::Instance = NULL;

void ObjectManager::Init()
{
	int Size;
	cout << "초기 오브젝트 만들 개수: "; cin >> Size;
	cout << "선택할 때 뽑을 개수 입력: "; cin >> Cnt;
	cout << "돌연변이 만들 개수 입력: "; cin >> mCnt;
	cout << "이진수 길이 표시 입력: "; cin >> Len;
	cout << "최소 범위 입력: "; cin >> Min;
	cout << "최대 범위 입력: "; cin >> Max;

	for (int i = 0; i < Size; ++i) {
		int cand = ObjectFactory::GetRandom();
		SetObjList(cand);
	}
}
void ObjectManager::Init(int _cnt,int _mcnt, int _len)
{
	Cnt = _cnt;
	mCnt = _mcnt;
	Len = _len;
}
void ObjectManager::Init(int _size, int _cnt, int _mcnt, int _len, int _min, int _max)
{
	Cnt = _cnt;
	mCnt = _mcnt;
	Len = _len;
	Min = _min;
	Max = _max;
	
	for (int i = 0; i < _size; ++i) {
		int cand = ObjectFactory::GetRandom();
		SetObjList(cand);	
	}
}


void ObjectManager::SetObjList(Object* _Obj) { ObjList.push_back(_Obj); }
void ObjectManager::SetObjList(int _cand) { ObjList.push_back(ObjectFactory::CreateObj(_cand)); }
void ObjectManager::SetObjList(vector<int> _binary) { ObjList.push_back(ObjectFactory::CreateObj(_binary)); }

void ObjectManager::SetNextObjList(Object* _Obj) { NextObjList.push_back(_Obj); }
void ObjectManager::SetNextObjList(int _cand) { NextObjList.push_back(ObjectFactory::CreateObj(_cand)); }
void ObjectManager::SetNextObjList(vector<int> _binary){ NextObjList.push_back(ObjectFactory::CreateObj(_binary));}

void ObjectManager::SetCrsNextObjList()
{
	vector<Object*> v(ObjList.begin(), ObjList.end());
	while (v.size() > 1) {
		int ind1 = ObjectFactory::GetRandom(0, v.size() - 1);
		int ind2;do {
			ind2 = ObjectFactory::GetRandom(0, v.size() - 1);
		} while (ind1 == ind2);

		SetCrsNextObjList(v[ind1], v[ind2]);

		v.erase(v.begin() + ind1);
		v.erase(v.begin() + ind2);
	}
}

void ObjectManager::SetCrsNextObjList(Object* _Obj1, Object* _Obj2)
{
	SetNextObjList(
		ObjectFactory::CreateCrossObj(_Obj1, _Obj2));
	SetNextObjList(
		ObjectFactory::CreateCrossObj(_Obj2, _Obj1));
}

void ObjectManager::SetMutNextObjList()
{
	SetMutNextObjList(mCnt);
}

void ObjectManager::SetMutNextObjList(int _cnt)
{
	for (int i = 0; i < _cnt; ++i) {
		int ind = ObjectFactory::GetRandom(0,
			ObjList.size() - 1);
		SetNextObjList(
			ObjectFactory::CreateMutationObj(ObjList[ind])	);
	}
}

void ObjectManager::SetMutNextObjList(Object* _Obj)
{
	SetNextObjList(
		ObjectFactory::CreateMutationObj(_Obj));
}


bool ObjectManager::FindObjCand(int _cand)
{
	for (vector<Object*>::iterator it = ObjList.begin();
		it != ObjList.end(); ++it) {
		if ((*it)->GetCand() == _cand) 
			return true;
	}
	return false;
}

Object* ObjectManager::FindObjMaxRes()
{
	if (ObjList.empty())return nullptr;

	Object* obj = ObjList[0];
	for (vector<Object*>::iterator it = ObjList.begin();
		it != ObjList.end(); ++it) {
		if (obj->GetRes() < (*it)->GetRes()) obj = (*it);
	}
	return obj;
}

void ObjectManager::ShowObjList(){
	for (vector<Object*>::iterator it = ObjList.begin();
		it != ObjList.end(); ++it)
		(*it)->show();
}
void ObjectManager::ShowNextObjList(){
	for (vector<Object*>::iterator it = NextObjList.begin();
		it != NextObjList.end(); ++it)
		(*it)->show();
}

void ObjectManager::ObjListRelease()
{
	for (vector<Object*>::iterator iter = ObjList.begin();
		iter != ObjList.end(); ++iter) {
		if (*iter) {
			delete(*iter);
			(*iter) = nullptr;
		}
	}
	ObjList.clear();
}
void ObjectManager::NextObjListRelease()
{
	for (vector<Object*>::iterator iter = NextObjList.begin();
		iter != NextObjList.end(); ++iter) {
		if (*iter) {
			delete(*iter);
			(*iter) = nullptr;
		}
	}
	NextObjList.clear();
}
