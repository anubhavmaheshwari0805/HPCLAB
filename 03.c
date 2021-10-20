#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
int main() {
	int m,n;
	printf("Enter the size of square matrix : ");
	scanf("%d",&n);
	printf("Enter the size of vector : ");
	scanf("%d", &m);
	if (m!=n) {
		printf("Multiplication is not possible.\n");
		exit(0);
	}
	int i=0,j=0;
	int **arr=(int**)malloc(n*sizeof(int*));
	for (i=0;i<n;i++) {
		arr[i]=(int*)malloc(n*sizeof(int));
		for (j=0;j<n;j++)
			arr[i][j]=rand()%100;
	}
	int *vec=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		vec[i]=rand()%100;
	int *res=(int*)malloc(n*sizeof(int));
	printf("natrix :\n");
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++)
			printf("%d ",arr[i][j]);
		printf("\n");
	}
	printf("Vector :\n");
	for(i=0;i<n;i++)
		printf("%d\n",vec[i]);
	#pragma omp parallel
	{
		#pragma omp for
		for(i=0;i<n;i++) {
			res[i]=0;
			for(j=0;j<n;j++)
				res[i]+=arr[i][j]*vec[j];
		}
	}
	printf("Resultant matrix multiplication : \n");
	for(i=0;i<n;i++)
		printf("%d\n",res[i]);
}
