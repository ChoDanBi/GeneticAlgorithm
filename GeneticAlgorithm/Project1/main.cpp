#include "header.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"
#include "Object.h"

int main() {
	
	
	ObjectManager::GetInstance()->Init(4, 4, 2, 5, 0, 31);

	cout << "\n*****���� ������Ʈ ����Ʈ �ȿ� ����ִ� ������Ʈ*****\n";
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
	cout << "\n\n*****����Ʈ�� ����ִ� ������Ʈ ����*****\n"; 
	ObjectManager::GetInstance()->ShowObjList();

	cout << "\n\n*****�������� ����Ʈ�� ����ִ� ������Ʈ ����*****\n";
	ObjectManager::GetInstance()->SetCrsNextObjList(Obj1, Obj2);
	ObjectManager::GetInstance()->ShowNextObjList();
	*/

	return 0;
}