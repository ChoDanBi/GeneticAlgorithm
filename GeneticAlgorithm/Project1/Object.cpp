#include "Object.h"
#include "ObjectManager.h"

void Object::SetInit(int _Cand)
{
	//후보해
	this->Cand = _Cand;
	
	//적합도
	this->Res = 80 + (38 * _Cand) - (_Cand * _Cand);

	//이진법 표기 길이
	Len = ObjectManager::GetInstance()->GetLen();

	//이진법
	for (int i = 0; i < Len; ++i) {
		this->Binary.push_back(_Cand % 2);
		_Cand /= 2;
	}

	//확인
	this->show();
}

void Object::SetInit(vector<int> _Binary)
{
	//후보해
	int size = _Binary.size();

	int j = 0;
	bool chk = false;

	for (int i = 0; i < size; ++i) {
		//앞이 0일 경우
		int ind = size - 1 - i;
		if (!chk && _Binary[ind] == 0) continue;

		//이진수를 후보해로 바꾸기
		chk = true;
		this->Cand += _Binary[i] * pow(2, j);
		j++;
	}

	//적합도
	this->Res = 80 + (38 * this->Cand) - (int)pow(this->Cand, 2);

	//이진법 표기 길이
	Len = ObjectManager::GetInstance()->GetLen();

	//이진법
	for (int i = 0; i < Len; ++i)
			this->Binary.push_back(i < size ? _Binary[i] : 0);
	
	//확인
	this->show();
}

