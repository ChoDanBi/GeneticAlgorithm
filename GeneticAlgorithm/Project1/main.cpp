#include "header.h"
#include "ObjectManager.h"
#include "Object.h"



int main() {
	

	ObjectManager::GetInstance()->Init(4, 4, 5, 0, 31);
	

	cout << "\n*****���� ������Ʈ ����Ʈ �ȿ� ����ִ� ������Ʈ*****\n";
	ObjectManager::GetInstance()->ShowObjList();

	

	return 0;
}