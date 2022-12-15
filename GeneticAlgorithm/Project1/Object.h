#pragma once
#include "header.h"
#include "Manager.h"

class Object
{
private:
	int Cand = 0;	//�ĺ���: x
	int Res;		//������: f(x)
	int Len;		//������ ǥ�� ����

	vector<int> Binary;	//������ �׷��� �Ųٷ� ������� Ȯ��
	/*ex)
	7: 00111
	���� ����: 11100
	*/

public:
	//���� - �ĺ��ط� ���� �ǰ� �������� ���� ��
	void SetInit(int _Cand);				//���ڷ� �ʱ�ȭ
	void SetInit(vector<int> _Binary);	//�������� �ʱ�ȭ

	//��������
	int GetCand() { return Cand; };
	int GetRes() { return Res; };
	vector<int> GetBinary() { return Binary; };

	//Ȯ��
	void show() {
		cout << "�ĺ���: " << Cand << " ���յ�: " << Res << " ������: ";
		for (int i = Len - 1; i >= 0; --i)
			cout << Binary[i]; cout << endl;
	};
};

