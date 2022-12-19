#pragma once
#include <random>
#include "ObjectManager.h"

class ObjectFactory
{
public:
	//���� �� ��������
	static int GetRandom();
	static int GetRandom(int _min, int _max);

	//�Ϲ� ������Ʈ �����
	static Object* CreateObj(int _cand);
	static Object* CreateObj(vector<int> _binary);

	//ũ�ν� �ڼ� �����
	static vector<int> CrossGene(Object* b1, Object* b2);
	static vector<int> CrossGene(const vector<int>& b1, const vector<int>& b2);

	//ũ�ν� �ڼ� ������Ʈ �����
	static Object* CreateCrossObj(Object *b1,Object* b2);
	static Object* CreateCrossObj(const vector<int>& b1, const vector<int>& b2);

	//�������� �����
	static vector<int> MutationGene(vector<int> _binary);
	static void MutationGene(vector<int>* _binary);

	//�������� ������Ʈ �����
	static Object* CreateMutationObj(Object* _obj);
	static Object* CreateMutationObj(const vector<int>& b);
};

