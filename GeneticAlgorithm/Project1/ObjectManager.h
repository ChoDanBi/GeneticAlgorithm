#pragma once
#include "header.h"
#include "Object.h"
#include "ObjectFactory.h"

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
	int Size = 0;		//인구수(오브젝트리스트의 초창기 크기)
	int Cnt = 0;		//다음세대로 뽑을 때의 개수
	int mCnt = 0;		//돌연변이 만들 개수
	int Len = 5;		//이진수의 길이
	int Min = 0;		//작은 숫자 범s위
	int Max = 0;		//큰 숫자 범위

	//현재 인구 리스트
	vector<Object*> ObjList;	
	//만들어진 세대 오브젝트 관리 리스트
	vector<Object*> NextObjList;

public:
	//초기화
	void Init();
	void Init(int _cnt, int _mcnt, int _len);
	void Init(
		int _size, int _cnt, int _mcnt, int _len, int _min, int _max);

public:
	//원래의 인구수(오브젝트리스트의 초창기 크기)
	void SetSize(int _size) { Size = _size; }
	int GetSize() { return Size; }

	//다음 세대를 뽑을 횟수
	void SetCnt(int _cnt) { Cnt = _cnt; }
	int GetCnt() { return Cnt; }

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

	void SetNextObjList(Object* _Obj);
	void SetNextObjList(int _cand);
	void SetNextObjList(vector<int> _binary);

	//다음세대 Cross된 오브젝트 넣기
	void SetCrsObjList();
	void SetCrsObjList(Object * _Obj1, Object* _Obj2);

	//다음세대 돌연변이 오브젝트 넣기
	void SetMutObjList();
	void SetMutObjList(int _cnt);
	void SetMutObjList(Object * _Obj);

	//오브젝트 가져오기
	Object* GetObject(int ind) { return ObjList[ind]; }
	vector<Object*>* GetObjList() { return &ObjList; };

	Object* GetNextObject(int ind) { return NextObjList[ind]; }
	vector<Object*>* GetNextObjList() { return &NextObjList; };

	//오브젝트 찾기
	bool FindObjCand(int _cand);
	Object* FindObjMaxRes();

	//리스트 보여주기
	void ShowObjList();
	void ShowNextObjList();

	//리스트 해제
	void ObjListRelease();
	void NextObjListRelease();

private:
	ObjectManager() {};
public:
	~ObjectManager() {};
};

