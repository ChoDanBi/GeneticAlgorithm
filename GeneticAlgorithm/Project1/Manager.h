#pragma once
#include "header.h"
#include "Object.h"

class Object;
class Manager
{
private:
	static Manager* Instance;

public:
	static Manager* GetInstance() {
		if (Instance == NULL)
			Instance = new Manager();
		return Instance;
	}

private:
	int Len;		//이진수의 길이
	int Cnt;		//뽑기 개수
	int Min;		//작은 숫자 범s위
	int Max;		//큰 숫자 범위

	vector<Object*> ObjectList;	//오브젝트 관리 리스트
	vector<Object*> NextObjectList;	//다음세대 오브젝트 관리 리스트

public:
	//초기화
	void Init();
	void Init(int _len, int _cnt, int _min, int _max);

public:

	//길이
	void SetLen(int _len) { Len = _len; }
	int GetLen() { return Len; }

	//뽑을 횟수
	void SetCnt(int _cnt) { Cnt = _cnt; }
	int GetCnt() { return Cnt; }

	//랜덤숫자 가져오기
	int GetRandom();					//이미 설정한 값으로 숫자
	int GetRandom(int _min, int _max);	//min~max 중


	//오브젝트 리스트
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


private:
	Manager() {};
public:
	~Manager() {};
};

