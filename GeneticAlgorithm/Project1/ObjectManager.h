#pragma once
#include "header.h"
#include "Object.h"

class Object;
class ObjectManager
{
private:
	static ObjectManager* Instance;

public:
	static ObjectManager* GetInstance() {
		if (Instance == NULL)
			Instance = new ObjectManager();
		return Instance;
	}

private:
	int pSize = 0;		//인구수(오브젝트리스트의 초창기 크기)
	int nCnt = 0;		//다음세대로 뽑을 때의 개수
	int mCnt = 0;		//돌연변이 만들 개수
	int Len = 5;		//이진수의 길이
	int Min = 0;		//작은 숫자 범s위
	int Max = 0;		//큰 숫자 범위

	//현재 인구 리스트
	vector<Object*> ObjList;
	map<int, int> cntObjList;

public:
	//초기화
	void Init(int _ncnt, int _mcnt, int _len);
	void Init(
		int _psize, int _ncnt, int _mcnt, int _len, int _min, int _max);

public:
	//원래의 인구수(오브젝트리스트의 초창기 크기)
	void SetSize(int _psize) { pSize = _psize; }
	int GetSize() { return pSize; }

	//다음 세대를 뽑을 횟수
	void SetCnt(int _cnt) { nCnt = _cnt; }
	int GetCnt() { return nCnt; }

	//돌연변이를 뽑을 횟수
	void SetmCnt(int _mcnt) { mCnt = _mcnt; }
	int GetmCnt() { return mCnt; }

	//이진법 표기 길이
	void SetLen(int _len) { Len = _len; }
	int GetLen() { return Len; }

	//최솟값
	void SetMin(int _min) { Min = _min; }
	int GetMin() { return Min; }

	//최댓값
	void SetMax(int _max) { Max = _max; }
	int GetMax() { return Max; }

	//오브젝트 리스트에 넣기
	void SetObjList(Object* _Obj);
	void SetObjList(int _cand);
	void SetObjList(vector<int> _binary);

	//현재 인구로 Cross된 오브젝트 넣기
	void SetCrsObjList();
	void SetCrsObjList(Object * _Obj1, Object* _Obj2);

	//현재 인구로 돌연변이 오브젝트 만들어 넣기
	void SetMutObjList();
	void SetMutObjList(int _cnt);
	void SetMutObjList(Object * _Obj);

	//오브젝트 정렬
	void SortObjList();

	//다음세대 선택하기
	void SetSelObjList();
	void SetSelObjList(int _cnt);
	
	//오브젝트 가져오기
	Object* GetObject(int ind) { return ObjList[ind]; }
	vector<Object*>* GetObjList() { return &ObjList; };

	//다음세대 만들기
	int CreateNextGen();
	void CreateNextGen(int _goal);

	int Counting(Object* obj);

	//리스트 보여주기
	void ShowObjList();
	//리스트 해제
	void ObjListRelease();

private:
	ObjectManager() {};
public:
	~ObjectManager() {};
};

