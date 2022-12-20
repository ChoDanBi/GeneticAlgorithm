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
	Size = _size;
	Cnt = _cnt;
	mCnt = _mcnt;
	Len = _len;
	Min = _min;
	Max = _max;
	
	for (int i = 0; i < Size; ++i) {
		int cand = ObjectFactory::GetRandom();
		SetObjList(cand);	
	}
}


void ObjectManager::SetObjList(Object* _Obj) { ObjList.push_back(_Obj); }
void ObjectManager::SetObjList(int _cand) { ObjList.push_back(ObjectFactory::CreateObj(_cand)); }
void ObjectManager::SetObjList(vector<int> _binary) { ObjList.push_back(ObjectFactory::CreateObj(_binary)); }


void ObjectManager::SetCrsObjList()
{	
	vector<bool> v(Size, false);	
	for (int i = 0; i < Size / 2; ++i) {

		int ind1; while (true) {
			ind1 = ObjectFactory::GetRandom(0, (Size - 1));
			if (!v[ind1]) { v[ind1] = true; break; }
		}

		int ind2;
		while (true) {
			ind2 = ObjectFactory::GetRandom(0, (Size - 1));
			if (!v[ind2]) { v[ind2] = true; break; }
		}

		SetCrsObjList(ObjList[ind1], ObjList[ind2]);
	}	
}
void ObjectManager::SetCrsObjList(Object* _Obj1, Object* _Obj2)
{
	SetObjList(
		ObjectFactory::CreateCrossObj(_Obj1, _Obj2));
	SetObjList(
		ObjectFactory::CreateCrossObj(_Obj2, _Obj1));
}


void ObjectManager::SetMutObjList(){
	for (int i = 0; i < mCnt; ++i) {
		int ind = ObjectFactory::GetRandom(0, Size - 1);
		SetObjList(ObjectFactory::CreateMutationObj(ObjList[ind]));
	}
}
void ObjectManager::SetMutObjList(int _cnt)
{
	for (int i = 0; i < _cnt; ++i) {
		int ind = ObjectFactory::GetRandom(0, Size - 1);

		SetObjList(ObjectFactory::CreateMutationObj(ObjList[ind]));
	}
}
void ObjectManager::SetMutObjList(Object* _Obj)
{
	SetObjList(ObjectFactory::CreateMutationObj(_Obj));
}


void ObjectManager::SortObjList() { 
	sort(ObjList.begin(), ObjList.end(), Object::cmp); 
}

void ObjectManager::SetSelObjList()
{
	vector<Object*>::iterator iter = (ObjList.begin() + (ObjList.size()-1));
	for (int i = ObjList.size(); i > Cnt; --i){
		delete(*iter);
		(*iter) = nullptr;
		--iter;
		ObjList.pop_back();
	}
}

void ObjectManager::SetSelObjList(int _cnt)
{
	vector<Object*>::iterator iter = (ObjList.begin() + (ObjList.size() - 1));
	for (int i = ObjList.size(); i > _cnt; --i) {
		delete(*iter);
		(*iter) = nullptr;
		--iter;
		ObjList.pop_back();
	}
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
