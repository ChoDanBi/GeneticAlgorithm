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
	int Size;		//���� ������Ʈ�� ����
	int Cnt;		//������ ���� ����
	int Len;		//�������� ����
	int Min;		//���� ���� ��s��
	int Max;		//ū ���� ����

	vector<Object*> ObjectList;	//������Ʈ ���� ����Ʈ
	vector<Object*> NextObjectList;	//�������� ������Ʈ ���� ����Ʈ

public:
	//�ʱ�ȭ
	void Init();
	void Init(int _size, int _cnt, int _len, int _min, int _max);

public:
	//������Ʈ ����Ʈ ũ��
	void SetSize(int _size) { Size = _size; }
	int GetSize() { return Size; }

	//������ ǥ�� ����
	void SetLen(int _len) { Len = _len; }
	int GetLen() { return Len; }

	//�ѹ� ���� Ƚ��
	void SetCnt(int _cnt) { Cnt = _cnt; }
	int GetCnt() { return Cnt; }

	//�ּڰ�
	void SetMin(int _min) { Min = _min; }
	int GetMin() { return Min; }

	//�ִ�
	void SetMax(int _max) { Max = _max; }
	int GetMax() { return Max; }

	//������Ʈ ����Ʈ�� �ֱ�
	void SetObjectList(Object* _Obj);
	void SetObjectList(int _cand);
	void SetObjectList(vector<int> _binary);

	void SetNextObjectList(Object* _Obj);
	void SetNextObjectList(int _cand);
	void SetNextObjectList(vector<int> _binary);

	//������Ʈ ��������
	Object* GetObject(int ind) { return ObjectList[ind]; }
	vector<Object*>* GetObjectList() { return &ObjectList; };

	Object* GetNextObject(int ind) { return NextObjectList[ind]; }
	vector<Object*>* GetNextObjectList() { return &NextObjectList; };

	//����Ʈ �����ֱ�
	void ShowObjList();
	void ShowNextObjList();

	void ObjListRelease();
	void NextObjListRelease();

private:
	ObjectManager() {};
public:
	~ObjectManager() {};
};

