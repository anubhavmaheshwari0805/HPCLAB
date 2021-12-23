#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<omp.h>
int main() {
	int n, i;
	time_t st, et;
	st = clock();
	printf("Enter the number of students : ");
	scanf_s("%d", &n);
	double* arr = (double*)malloc(n * sizeof(double));
	double arr_max = 0;
	#pragma omp parallel for
	for (i = 0; i < n; i++) {
		srand(i);
		arr[i] = (double)(rand() % 10000)/10 ;
	}
	printf("CGPA of students : ");
	for (i = 0; i < n; i++)
		printf("%.2lf ", arr[i]);
	printf("\n");
	#pragma omp parallel for
	for (i = 0; i < n; i++) {
		#pragma omp critical
		if (arr_max < arr[i])
			arr_max = arr[i];
	}
	et = clock();
	printf("Student with highest CGPA = %.2lf\n", arr_max);
	printf("Time Taken : %.2lfms\n", ((double)(et - st) * 1000 / CLOCKS_PER_SEC));
}