#pragma once
#include "header.h"
#include "Object.h"

class Manager
{
private:
	static Manager* Instance;

	int Len;		//이진수의 길이
	int Cnt;		//뽑기 개수
	int Min;		//작은 숫자 범s위
	int Max;		//큰 숫자 범위
	vector<Object> ObjectList;	//오브젝트 관리 리스트

	Manager();
	~Manager();

public:
	static Manager* GetInstance() {
		if (Instance == NULL)
			Instance = new Manager();
		return Instance;
	}

	//초기화
	void Init(int _len, int _cnt, int _min, int _max);

	//오브젝트 리스트
	void SetObjectList(Object _Obj);
	void SetObjectList(int _cand);
	void SetObjectList(vector<int> _binary);
	Object GetObject(int ind) { return ObjectList[ind]; }

	//오브젝트 가져오기
	vector<Object> GetObjectList() { return ObjectList; };

	//길이
	void SetLen(int _len) { Len = _len; }
	int GetLen() { return Len; }

	//뽑을 횟수
	void SetCnt(int _cnt) { Cnt = _cnt; }
	int GetCnt() { return Cnt; }
};

