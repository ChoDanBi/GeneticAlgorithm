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
	int Size;		//만들 오브젝트의 개수
	int Cnt;		//선택할 때의 개수
	int Len;		//이진수의 길이
	int Min;		//작은 숫자 범s위
	int Max;		//큰 숫자 범위

	vector<Object*> ObjectList;	//오브젝트 관리 리스트
	vector<Object*> NextObjectList;	//다음세대 오브젝트 관리 리스트

public:
	//초기화
	void Init();
	void Init(int _size, int _cnt, int _len, int _min, int _max);

public:
	//오브젝트 리스트 크기
	void SetSize(int _size) { Size = _size; }
	int GetSize() { return Size; }

	//이진법 표기 길이
	void SetLen(int _len) { Len = _len; }
	int GetLen() { return Len; }

	//한번 뽑을 횟수
	void SetCnt(int _cnt) { Cnt = _cnt; }
	int GetCnt() { return Cnt; }

	//최솟값
	void SetMin(int _min) { Min = _min; }
	int GetMin() { return Min; }

	//최댓값
	void SetMax(int _max) { Max = _max; }
	int GetMax() { return Max; }

	//오브젝트 리스트에 넣기
	void SetObjectList(Object* _Obj);
	void SetObjectList(int _cand);
	void SetObjectList(vector<int> _binary);

	void SetNextObjectList(Object* _Obj);
	void SetNextObjectList(int _cand);
	void SetNextObjectList(vector<int> _binary);

	//오브젝트 가져오기
	Object* GetObject(int ind) { return ObjectList[ind]; }
	vector<Object*>* GetObjectList() { return &ObjectList; };

	Object* GetNextObject(int ind) { return NextObjectList[ind]; }
	vector<Object*>* GetNextObjectList() { return &NextObjectList; };

	//리스트 보여주기
	void ShowObjList();
	void ShowNextObjList();

	void ObjListRelease();
	void NextObjListRelease();

private:
	ObjectManager() {};
public:
	~ObjectManager() {};
};

