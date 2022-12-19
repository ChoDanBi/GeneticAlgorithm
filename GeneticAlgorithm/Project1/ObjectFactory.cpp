#include "ObjectFactory.h"

int ObjectFactory::GetRandom()
{
	random_device rd;	//시드값을 얻기 위한 rd 생성
	mt19937 gen(rd());	//난수 생성 엔진 초기화

	int Min = ObjectManager::GetInstance()->GetMin();
	int Max = ObjectManager::GetInstance()->GetMax();

	//min~max까지의 난수 생성
	uniform_int_distribution<int> dis(Min, Max);
	return dis(gen);
}
int ObjectFactory::GetRandom(int _min, int _max)
{
	random_device rd;	//시드값을 얻기 위한 rd 생성
	mt19937 gen(rd());	//난수 생성 엔진 초기화

	//min~max까지의 난수 생성
	uniform_int_distribution<int> dis(_min, _max);
	return dis(gen);
}


Object* ObjectFactory::CreateObj(int _cand)
{
	Object* Obj = new Object;
	Obj->SetInit(_cand);
	return Obj;
}
Object* ObjectFactory::CreateObj(vector<int> _binary)
{
	Object* Obj = new Object;
	Obj->SetInit(_binary);
	return Obj;
}


vector<int> ObjectFactory::CrossGene(Object* b1, Object* b2)
{
	int len = ObjectManager::GetInstance()->GetLen();
	int helf = len / 2;

	vector<int> nextBin;

	for (int i = 0; i < len; ++i)
		nextBin.push_back(i <= helf ? 
			b1->GetBinary()[i] : 
			b2->GetBinary()[i]);

	return nextBin;
}
vector<int> ObjectFactory::CrossGene(const vector<int>& b1, const vector<int>& b2)
{
	int len = ObjectManager::GetInstance()->GetLen();
	int helf = len / 2;

	vector<int> nextBin;

	for (int i = 0; i < len; ++i)
		nextBin.push_back(i <= helf ? b1[i] : b2[i]);

	return nextBin;
}

Object* ObjectFactory::CreateCrossObj(Object* b1, Object* b2)
{
	Object* Obj = new Object;
	Obj->SetInit(CrossGene(b1,b2));
	return Obj;
}
Object* ObjectFactory::CreateCrossObj(const vector<int>& b1, const vector<int>& b2)
{
	Object* Obj = new Object;
	Obj->SetInit(CrossGene(b1, b2));
	return Obj;
}


vector<int> ObjectFactory::MutationGene(vector<int> _binary)
{
	int ind = GetRandom(0,
		(ObjectManager::GetInstance()->GetLen() - 1));

	_binary[ind] = _binary[ind] == 0 ? 1 : 0;

	return _binary;
}
void ObjectFactory::MutationGene(vector<int>* _binary)
{
	int ind = GetRandom(0,
		(ObjectManager::GetInstance()->GetLen() - 1));

	vector<int>::iterator iter = _binary->begin();
	*(iter + ind) = *(iter + ind) == 0 ? 1 : 0;
}

Object* ObjectFactory::CreateMutationObj(Object* _obj)
{
	Object* obj = new Object;
	obj->SetInit(MutationGene(_obj->GetBinary()));
	return obj;
}
Object* ObjectFactory::CreateMutationObj(const vector<int>& b)
{
	Object* obj = new Object;
	obj->SetInit(MutationGene(b));
	return obj;
}

