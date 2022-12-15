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
	int Len;		//�������� ����
	int Cnt;		//�̱� ����
	int Min;		//���� ���� ��s��
	int Max;		//ū ���� ����

	vector<Object*> ObjectList;	//������Ʈ ���� ����Ʈ
	vector<Object*> NextObjectList;	//�������� ������Ʈ ���� ����Ʈ

public:
	//�ʱ�ȭ
	void Init();
	void Init(int _len, int _cnt, int _min, int _max);

public:

	//����
	void SetLen(int _len) { Len = _len; }
	int GetLen() { return Len; }

	//���� Ƚ��
	void SetCnt(int _cnt) { Cnt = _cnt; }
	int GetCnt() { return Cnt; }

	//�������� ��������
	int GetRandom();					//�̹� ������ ������ ����
	int GetRandom(int _min, int _max);	//min~max ��


	//������Ʈ ����Ʈ
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


private:
	Manager() {};
public:
	~Manager() {};
};

