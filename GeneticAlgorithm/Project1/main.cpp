#include "header.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"
#include "Object.h"

int main() {
	
	
	ObjectManager::GetInstance()->Init(4, 4, 2, 5, 0, 31);

	cout << "\n*****현재 오브젝트 리스트 안에 들어있는 오브젝트*****\n";
	ObjectManager::GetInstance()->ShowObjList();
	cout << "\n\n***NextObjList*****\n ";
	//ObjectManager::GetInstance()->SetMutNextObjList();
	ObjectManager::GetInstance()->SetCrsNextObjList();

	ObjectManager::GetInstance()->ShowNextObjList();

	/*
	ObjectManager::GetInstance()->Init(4, 2, 5);
	Object* Obj1 = new Object;
	Obj1->SetInit({1,0,0});
	ObjectManager::GetInstance()->SetObjList(Obj1);
	Object* Obj2 = new Object;
	Obj2->SetInit(16);
	ObjectManager::GetInstance()->SetObjList(Obj2);
	cout << "\n\n*****리스트에 들어있는 오브젝트 정보*****\n"; 
	ObjectManager::GetInstance()->ShowObjList();

	cout << "\n\n*****다음세대 리스트에 들어있는 오브젝트 정보*****\n";
	ObjectManager::GetInstance()->SetCrsNextObjList(Obj1, Obj2);
	ObjectManager::GetInstance()->ShowNextObjList();
	*/

	return 0;
}