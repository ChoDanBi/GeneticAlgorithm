#pragma once
#include "Object.h"
#include <random>

class Factory{
public:
	static Object* CreateObj(int _cand) {
		Object* Obj = new Object;
		Obj->SetInit(_cand);
		return Obj;
	}

	static Object* CreateObj(vector<int> _binary) {
		Object* Obj = new Object;
		Obj->SetInit(_binary);
		return Obj;
	}

	static int GetRandom()
	{
		random_device rd;	//�õ尪�� ��� ���� rd ����
		mt19937 gen(rd());	//���� ���� ���� �ʱ�ȭ

		int Min = ObjectManager::GetInstance()->GetMin();
		int Max = ObjectManager::GetInstance()->GetMax();

		uniform_int_distribution<int> dis(Min, Max);	//min~max������ ���� ����
		return dis(gen);
	}

	static int GetRandom(int _min, int _max)
	{
		random_device rd;	//�õ尪�� ��� ���� rd ����
		mt19937 gen(rd());	//���� ���� ���� �ʱ�ȭ
		uniform_int_distribution<int> dis(_min, _max);	//min~max������ ���� ����
		return dis(gen);
	}

};