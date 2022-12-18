#pragma once
#include "header.h"

class Object
{
private:
	int Cand = 0;	//후보해: x
	int Res;		//적랍도: f(x)
	int Len;		//이진법 표기 개수

	vector<int> Binary;	//이진법 그러나 거꾸로 저장됨을 확인
	/*ex)
	7: 00111
	실제 저장: 11100
	*/

public:
	//세팅 - 후보해로 만들어도 되고 이진수로 만들어도 됨
	//숫자로 초기화
	void SetInit(int _Cand);
	void SetInit(int _Cand, int _len);
	//이진수로 초기화
	void SetInit(vector<int> _Binary);
	void SetInit(vector<int> _Binary, int _len);

	void SetLen(int _len) { Len = _len; }

	//가져오기
	int GetCand() { return Cand; };
	int GetRes() { return Res; };
	vector<int> GetBinary() { return Binary; };

	//확인
	void show() {
		cout << "후보해: " << Cand << " 적합도: " << Res << " 이진법: ";
		for (int i = Len - 1; i >= 0; --i)
			cout << Binary[i]; cout << endl;
	};
};

