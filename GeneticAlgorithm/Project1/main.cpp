#include "header.h"
#include "ObjectManager.h"

int main() {
	
	

	
	ObjectManager::GetInstance()->Init(4, 4, 2, 5, 0, 31);

	cout << "\n*****현재 오브젝트 리스트 안에 들어있는 오브젝트*****\n";
	ObjectManager::GetInstance()->ShowObjList();
	cout << "\n\n***NextObjList*****\n ";
	//ObjectManager::GetInstance()->SetMutNextObjList();
	ObjectManager::GetInstance()->SetCrsObjList();
	ObjectManager::GetInstance()->SetMutObjList();
	ObjectManager::GetInstance()->ShowObjList();
	

	

	return 0;
}