#pragma once
#include <random>
#include "ObjectManager.h"

class ObjectFactory
{
public:
	//랜덤 값 가져오기
	static int GetRandom();
	static int GetRandom(int _min, int _max);

	//일반 오브젝트 만들기
	static Object* CreateObj(int _cand);
	static Object* CreateObj(vector<int> _binary);

	//크로스 자손 만들기
	static vector<int> CrossGene(Object* b1, Object* b2);
	static vector<int> CrossGene(const vector<int>& b1, const vector<int>& b2);

	//크로스 자손 오브젝트 만들기
	static Object* CreateCrossObj(Object *b1,Object* b2);
	static Object* CreateCrossObj(const vector<int>& b1, const vector<int>& b2);

	//돌연변이 만들기
	static vector<int> MutationGene(vector<int> _binary);
	static void MutationGene(vector<int>* _binary);

	//돌연변이 오브젝트 만들기
	static Object* CreateMutationObj(Object* _obj);
	static Object* CreateMutationObj(const vector<int>& b);
};

