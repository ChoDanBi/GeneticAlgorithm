#include "header.h"
#include "ObjectManager.h"

int main() {
	
	ObjectManager::GetInstance()->Init(5, 4, 0, 31);
	//Manager::GetInstance()->Init();
	return 0;
}