#include "header.h"
#include "GeneticAlgorithm.h"
#include <time.h>

void duration(clock_t start, clock_t finish);


int main(void) {
	cout << "[    GeneticAlgorithm    ]\n";

	clock_t start, finish;
	start = clock();
	//==========================

	GENE->Init(4, 4, 2, 31);
	GENE->Start(10);

	//==========================
	finish = clock(); duration(start, finish); return 0;
}

void duration(clock_t start, clock_t finish) {
	double dur = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "\n\n걸린 시간: " << dur << endl;
}