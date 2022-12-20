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
	int Size = 0;		//�α���(������Ʈ����Ʈ�� ��â�� ũ��)
	int Cnt = 0;		//��������� ���� ���� ����
	int mCnt = 0;		//�������� ���� ����
	int Len = 5;		//�������� ����
	int Min = 0;		//���� ���� ��s��
	int Max = 0;		//ū ���� ����

	//���� �α� ����Ʈ
	vector<Object*> ObjList;	
	//������� ���� ������Ʈ ���� ����Ʈ
	vector<Object*> NextObjList;

public:
	//�ʱ�ȭ
	void Init();
	void Init(int _cnt, int _mcnt, int _len);
	void Init(
		int _size, int _cnt, int _mcnt, int _len, int _min, int _max);

public:
	//������ �α���(������Ʈ����Ʈ�� ��â�� ũ��)
	void SetSize(int _size) { Size = _size; }
	int GetSize() { return Size; }

	//���� ���븦 ���� Ƚ��
	void SetCnt(int _cnt) { Cnt = _cnt; }
	int GetCnt() { return Cnt; }

	//�������̸� ���� Ƚ��
	void SetmCnt(int _mcnt) { mCnt = _mcnt; }
	int GetmCnt() { return mCnt; }

	//������ ǥ�� ����
	void SetLen(int _len) { Len = _len; }
	int GetLen() { return Len; }

	//�ּڰ�
	void SetMin(int _min) { Min = _min; }
	int GetMin() { return Min; }

	//�ִ�
	void SetMax(int _max) { Max = _max; }
	int GetMax() { return Max; }

	//������Ʈ ����Ʈ�� �ֱ�
	void SetObjList(Object* _Obj);
	void SetObjList(int _cand);
	void SetObjList(vector<int> _binary);

	void SetNextObjList(Object* _Obj);
	void SetNextObjList(int _cand);
	void SetNextObjList(vector<int> _binary);

	//�������� Cross�� ������Ʈ �ֱ�
	void SetCrsObjList();
	void SetCrsObjList(Object * _Obj1, Object* _Obj2);

	//�������� �������� ������Ʈ �ֱ�
	void SetMutObjList();
	void SetMutObjList(int _cnt);
	void SetMutObjList(Object * _Obj);

	//������Ʈ ��������
	Object* GetObject(int ind) { return ObjList[ind]; }
	vector<Object*>* GetObjList() { return &ObjList; };

	Object* GetNextObject(int ind) { return NextObjList[ind]; }
	vector<Object*>* GetNextObjList() { return &NextObjList; };

	//������Ʈ ã��
	bool FindObjCand(int _cand);
	Object* FindObjMaxRes();

	//����Ʈ �����ֱ�
	void ShowObjList();
	void ShowNextObjList();

	//����Ʈ ����
	void ObjListRelease();
	void NextObjListRelease();

private:
	ObjectManager() {};
public:
	~ObjectManager() {};
};

