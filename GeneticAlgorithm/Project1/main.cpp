#include "header.h"
#include "ObjectManager.h"



int main() {
	
	ObjectManager::GetInstance()->Init(4, 4, 5, 0, 31);
	

	cout << "\n*****���� ������Ʈ ����Ʈ �ȿ� ����ִ� ������Ʈ*****\n";
	ObjectManager::GetInstance()->ShowObjList();

	cout << "\n\n*****������ ������Ʈ ����Ʈ*****\n";
	ObjectManager::GetInstance()->SortObjList();
	ObjectManager::GetInstance()->ShowObjList();
	

	return 0;
}