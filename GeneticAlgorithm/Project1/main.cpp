#include "header.h"
#include "ObjectManager.h"

int main() {
	
	

	
	ObjectManager::GetInstance()->Init(4, 4, 2, 5, 0, 31);

	cout << "\n*****���� ������Ʈ ����Ʈ �ȿ� ����ִ� ������Ʈ*****\n";
	ObjectManager::GetInstance()->ShowObjList();
	cout << "\n\n***NextObjList*****\n ";
	//ObjectManager::GetInstance()->SetMutNextObjList();
	ObjectManager::GetInstance()->SetCrsNextObjList();

	ObjectManager::GetInstance()->ShowNextObjList();
	

	

	return 0;
}