#include "header.h"
#include "ObjectManager.h"

int main() {
		
	//초기 인구수, 다음세대 인구수, 돌연변이 발생 수, 
	//이진법 표기길이, 최소값, 최대값
	
	ObjectManager::GetInstance()->Init(4, 4, 2, 4, 0, 15);
	//ObjectManager::GetInstance()->Init(4, 4, 2, 5, 0, 31);
	//ObjectManager::GetInstance()->Init(10, 10, 5, 6, 0, 63);
	//ObjectManager::GetInstance()->Init(10, 10, 5, 7, 0, 127);

	ObjectManager::GetInstance()->GetNextObjList(50);
	
	return 0;
}