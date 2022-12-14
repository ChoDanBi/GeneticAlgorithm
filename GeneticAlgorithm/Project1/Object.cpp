#include "Object.h"

void Object::SetCand(int _Cand, int _Len)
{
	//�ĺ���
	this->Cand = _Cand;
	
	//���յ�
	this->Res = 80 + (38 * _Cand) - (_Cand * _Cand);

	//����
	this->Len = _Len;

	//������
	for (int i = 0; i < Len; ++i) {
		this->Binary.push_back(_Cand % 2);
		_Cand /= 2;
	}

	//Ȯ��
	this->show();
}

void Object::SetBinary(vector<int> _Binary, int _Len)
{
	//�ĺ���
	int size = _Binary.size();

	int j = 0;
	bool chk = false;

	for (int i = 0; i < size; ++i) {
		//���� 0�� ���
		int ind = size - 1 - i;
		if (!chk && _Binary[ind] == 0) continue;

		//�������� �ĺ��ط� �ٲٱ�
		chk = true;
		this->Cand += _Binary[i] * pow(2, j);
		j++;
	}

	/*
	111�̶� �Ҷ�
	0 0 1 1 1
	0 0 4 2 1 = 7

	���� ���ʹ� 1 1 1 0 0
	*/

	//���յ�
	this->Res = 80 + (38 * this->Cand) - (int)pow(this->Cand, 2);

	//����
	this->Len = _Len;

	//������
	for (int i = 0; i < Len; ++i)
			this->Binary.push_back(i < size ? _Binary[i] : 0);
	
	//Ȯ��
	this->show();
}

