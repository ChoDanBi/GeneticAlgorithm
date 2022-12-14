#include "Object.h"

void Object::SetCand(int _Cand, int _Len)
{
	//후보해
	this->Cand = _Cand;
	
	//적합도
	this->Res = 80 + (38 * _Cand) - (_Cand * _Cand);

	//갈이
	this->Len = _Len;

	//이진법
	for (int i = 0; i < Len; ++i) {
		this->Binary.push_back(_Cand % 2);
		_Cand /= 2;
	}

	//확인
	this->show();
}

void Object::SetBinary(vector<int> _Binary, int _Len)
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

	/*
	111이라 할때
	0 0 1 1 1
	0 0 4 2 1 = 7

	실제 벡터는 1 1 1 0 0
	*/

	//적합도
	this->Res = 80 + (38 * this->Cand) - (int)pow(this->Cand, 2);

	//길이
	this->Len = _Len;

	//이진법
	for (int i = 0; i < Len; ++i)
			this->Binary.push_back(i < size ? _Binary[i] : 0);
	
	//확인
	this->show();
}

