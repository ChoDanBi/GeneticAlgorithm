#include "header.h"
#include "Manager.h"

int main() {
	
	Manager::GetInstance()->Init(5, 4, 0, 31);
	//Manager::GetInstance()->Init();
	return 0;
}