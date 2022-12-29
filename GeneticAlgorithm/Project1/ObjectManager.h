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
	int pSize = 0;		//�α���(������Ʈ����Ʈ�� ��â�� ũ��)
	int nCnt = 0;		//��������� ���� ���� ����
	int mCnt = 0;		//�������� ���� ����
	int Len = 5;		//�������� ����
	int Min = 0;		//���� ���� ��s��
	int Max = 0;		//ū ���� ����

	//���� �α� ����Ʈ
	vector<Object*> ObjList;
	map<int, int> cntObjList;

public:
	//�ʱ�ȭ
	void Init(int _ncnt, int _mcnt, int _len);
	void Init(
		int _psize, int _ncnt, int _mcnt, int _len, int _min, int _max);

public:
	//������ �α���(������Ʈ����Ʈ�� ��â�� ũ��)
	void SetSize(int _psize) { pSize = _psize; }
	int GetSize() { return pSize; }

	//���� ���븦 ���� Ƚ��
	void SetCnt(int _cnt) { nCnt = _cnt; }
	int GetCnt() { return nCnt; }

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

	//���� �α��� Cross�� ������Ʈ �ֱ�
	void SetCrsObjList();
	void SetCrsObjList(Object * _Obj1, Object* _Obj2);

	//���� �α��� �������� ������Ʈ ����� �ֱ�
	void SetMutObjList();
	void SetMutObjList(int _cnt);
	void SetMutObjList(Object * _Obj);

	//������Ʈ ����
	void SortObjList();

	//�������� �����ϱ�
	void SetSelObjList();
	void SetSelObjList(int _cnt);
	
	//������Ʈ ��������
	Object* GetObject(int ind) { return ObjList[ind]; }
	vector<Object*>* GetObjList() { return &ObjList; };

	//�������� �����
	int CreateNextGen();
	void CreateNextGen(int _goal);

	int Counting(Object* obj);

	//����Ʈ �����ֱ�
	void ShowObjList();
	//����Ʈ ����
	void ObjListRelease();

private:
	ObjectManager() {};
public:
	~ObjectManager() {};
};

