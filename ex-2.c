#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
int main() {
	omp_set_num_threads(10);
	#pragma omp parallel
	{
		int i=omp_get_thread_num();
		if(i%2==0)
            printf("Hello World from %d, I am even !\n",i);
        else
            printf("Hello World from %d, I am odd !\n",i);
	}
}
