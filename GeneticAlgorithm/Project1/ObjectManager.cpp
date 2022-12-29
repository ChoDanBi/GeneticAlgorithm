#include "ObjectManager.h"
#include "ObjectFactory.h"

ObjectManager* ObjectManager::Instance = NULL;

void ObjectManager::Init(int _ncnt,int _mcnt, int _len)
{
	nCnt = _ncnt;
	mCnt = _mcnt;
	Len = _len;
}
void ObjectManager::Init(int _psize, int _ncnt, int _mcnt, int _len, int _min, int _max)
{
	pSize = _psize;
	nCnt = _ncnt;
	mCnt = _mcnt;
	Len = _len;
	Min = _min;
	Max = _max;
	
	for (int i = 0; i < pSize; ++i) {
		int cand = ObjectFactory::GetRandom();
		SetObjList(cand);	
	}

	cout << "[     초기세대     ]" << endl;
	ShowObjList(); cout << endl;
}


void ObjectManager::SetObjList(Object* _Obj) { ObjList.push_back(_Obj); }
void ObjectManager::SetObjList(int _cand) { ObjList.push_back(ObjectFactory::CreateObj(_cand)); }
void ObjectManager::SetObjList(vector<int> _binary) { ObjList.push_back(ObjectFactory::CreateObj(_binary)); }


void ObjectManager::SetCrsObjList()
{	
	vector<bool> v(pSize, false);	
	for (int i = 0; i < pSize / 2; ++i) {

		int ind1; while (true) {
			ind1 = ObjectFactory::GetRandom(0, (pSize - 1));
			if (!v[ind1]) { v[ind1] = true; break; }
		}

		int ind2;
		while (true) {
			ind2 = ObjectFactory::GetRandom(0, (pSize - 1));
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
		int ind = ObjectFactory::GetRandom(0, pSize - 1);
		SetObjList(ObjectFactory::CreateMutationObj(ObjList[ind]));
	}
}
void ObjectManager::SetMutObjList(int _cnt)
{
	for (int i = 0; i < _cnt; ++i) {
		int ind = ObjectFactory::GetRandom(0, pSize - 1);

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
	for (int i = ObjList.size(); i > nCnt; --i){
		delete(*iter);
		(*iter) = nullptr; --iter;
		ObjList.pop_back();
	}
	pSize = nCnt;
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
	pSize = nCnt;
}

int ObjectManager::CreateNextGen()
{
	SetCrsObjList();
	SetMutObjList();
	SortObjList();
	SetSelObjList();
	return Counting(ObjList.front());
}

void ObjectManager::CreateNextGen(int _goal)
{
	while (true)
	{
		int cnt = CreateNextGen();
		cout << ", 카운팅: " << cnt << endl;
		if (cnt >= _goal) break;
	}

	cout << "\n최종: "; ObjList.front()->show(); cout << endl;
}

int ObjectManager::Counting(Object* obj)
{
	int _cand = obj->GetCand();
	cout << "후보자: " << _cand;

	if (cntObjList.find(_cand) == cntObjList.end())
		cntObjList.insert(make_pair(_cand, 0));
	return ++cntObjList[_cand];
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
