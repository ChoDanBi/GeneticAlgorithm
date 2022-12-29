#include "header.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"
#include <time.h>

int main() {
	cout << "*****GeneAlgorithm*****\n";

	clock_t start, finish;
	double duration;
	start = clock();

	//�ʱ� �α���, �������� �α���, �������� �߻� ��, 
	//������ ǥ�����, �ּҰ�, �ִ밪	
	ObjectManager::GetInstance()->Init(4, 4, 2, 5, 0, 31);
	ObjectManager::GetInstance()->CreateNextGen(20);
	
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "�ɸ��ð�: " << duration;

	return 0;
}