#pragma once
#include "header.h"
#include "Object.h"

class Manager
{
private:
	static Manager* Instance;

	int Len;		//�������� ����
	int Cnt;		//�̱� ����
	int Min;		//���� ���� ��s��
	int Max;		//ū ���� ����
	vector<Object> ObjectList;	//������Ʈ ���� ����Ʈ

	Manager();
	~Manager();

public:
	static Manager* GetInstance() {
		if (Instance == NULL)
			Instance = new Manager();
		return Instance;
	}

	//�ʱ�ȭ
	void Init(int _len, int _cnt, int _min, int _max);

	//������Ʈ ����Ʈ
	void SetObjectList(Object _Obj);
	void SetObjectList(int _cand);
	void SetObjectList(vector<int> _binary);
	Object GetObject(int ind) { return ObjectList[ind]; }

	//������Ʈ ��������
	vector<Object> GetObjectList() { return ObjectList; };

	//����
	void SetLen(int _len) { Len = _len; }
	int GetLen() { return Len; }

	//���� Ƚ��
	void SetCnt(int _cnt) { Cnt = _cnt; }
	int GetCnt() { return Cnt; }
};

