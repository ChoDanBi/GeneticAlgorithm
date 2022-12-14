#pragma once
#include "header.h"

class Object
{
private:
	int Cand = 0;	//�ĺ���: x
	int Res;		//������: f(x)
	int Len;	
	vector<int> Binary;	//������ �׷��� �Ųٷ� ������� Ȯ��
	/*
	ex)
	7: 00111
	���� ����: 11100
	*/

public:
	//���� - �ĺ��ط� ���� �ǰ� �������� ���� ��
	void SetCand(int _Cand, int _Len);
	void SetBinary(vector<int> _Binary, int _Len);

	//��������
	int GetCand() { return Cand; };
	int GetRes() { return Res; };
	int GetLen() { return Len; };
	vector<int> GetBinary() { return Binary; };

	//Ȯ��
	void show() {
		cout << "�ĺ���: " << Cand << " ���յ�: " << Res << " ������: ";
		for (int i = Len - 1; i >= 0; --i)
			cout << Binary[i]; cout << endl;
	};
};

