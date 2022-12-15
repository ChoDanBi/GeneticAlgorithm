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
		random_device rd;	//시드값을 얻기 위한 rd 생성
		mt19937 gen(rd());	//난수 생성 엔진 초기화

		int Min = ObjectManager::GetInstance()->GetMin();
		int Max = ObjectManager::GetInstance()->GetMax();

		uniform_int_distribution<int> dis(Min, Max);	//min~max까지의 난수 생성
		return dis(gen);
	}

	static int GetRandom(int _min, int _max)
	{
		random_device rd;	//시드값을 얻기 위한 rd 생성
		mt19937 gen(rd());	//난수 생성 엔진 초기화
		uniform_int_distribution<int> dis(_min, _max);	//min~max까지의 난수 생성
		return dis(gen);
	}

};