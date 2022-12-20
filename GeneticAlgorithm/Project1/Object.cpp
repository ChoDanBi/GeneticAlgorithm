#include "Object.h"
#include "ObjectManager.h"

void Object::SetInit(int _Cand)
{
	//�ĺ���
	this->Cand = _Cand;
	
	//���յ�
	this->Res = f(Cand);

	//������ ǥ�� ����
	Len = ObjectManager::GetInstance()->GetLen();

	//������
	for (int i = 0; i < Len; ++i) {
		this->Binary.push_back(_Cand % 2);
		_Cand /= 2;
	}

	//Ȯ��
	//this->show();
}

void Object::SetInit(int _Cand, int _len)
{
	//�ĺ���
	this->Cand = _Cand;

	//���յ�
	this->Res = f(Cand);

	//������ ǥ�� ����
	SetLen(_len);

	//������
	for (int i = 0; i < Len; ++i) {
		this->Binary.push_back(_Cand % 2);
		_Cand /= 2;
	}

	//Ȯ��
	//this->show();
}

void Object::SetInit(vector<int> _Binary)
{
	//�ĺ���
	int size = _Binary.size();

	for (int i = 0; i < size; ++i)
		Cand += _Binary[i] * (int)pow(2, i);

	//���յ�
	this->Res = f(Cand);

	//������ ǥ�� ����
	Len = ObjectManager::GetInstance()->GetLen();

	//������
	for (int i = 0; i < Len; ++i)
			this->Binary.push_back(i < size ? _Binary[i] : 0);
	
	//Ȯ��
	//this->show();
}

void Object::SetInit(vector<int> _Binary, int _len)
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

	//���յ�
	this->Res = f(Cand);

	//������ ǥ�� ����
	SetLen(_len);

	//������
	for (int i = 0; i < Len; ++i)
		this->Binary.push_back(i < size ? _Binary[i] : 0);

	//Ȯ��
	//this->show();
}

