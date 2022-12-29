#include "header.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"
#include <time.h>

int main() {
	cout << "*****GeneAlgorithm*****\n";

	clock_t start, finish;
	double duration;
	start = clock();

	//초기 인구수, 다음세대 인구수, 돌연변이 발생 수, 
	//이진법 표기길이, 최소값, 최대값	
	ObjectManager::GetInstance()->Init(4, 4, 2, 5, 0, 31);
	ObjectManager::GetInstance()->CreateNextGen(20);
	
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "걸린시간: " << duration;

	return 0;
}