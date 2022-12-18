#pragma once
#include "header.h"

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
	//���ڷ� �ʱ�ȭ
	void SetInit(int _Cand);
	void SetInit(int _Cand, int _len);
	//�������� �ʱ�ȭ
	void SetInit(vector<int> _Binary);
	void SetInit(vector<int> _Binary, int _len);

	void SetLen(int _len) { Len = _len; }

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

