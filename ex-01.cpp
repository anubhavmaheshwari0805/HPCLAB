#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
int main() {
	int i;
	omp_set_num_threads(10);
	#pragma omp parallel
	{
		i=omp_get_num_threads();
		int num=omp_get_thread_num();
		printf("Hello World - %d\n",num);
	}
	printf("Number of threads = %d\n",i);
}
