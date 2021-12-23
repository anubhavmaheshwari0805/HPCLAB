#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
void main() {
    int r,i,ans=0;
    printf("Enter number of sections : ");
    scanf_s("%d",&r);
    int **arr=(int**)malloc(r*sizeof(int*));
    int *size=(int*)malloc(r*sizeof(int));
    omp_set_num_threads(r);
	#pragma omp parallel
    {
        #pragma omp for
        for (i=0;i<r;i++) {
            srand(i);
            int j,sum=0;
            size[i]=rand()%20;
		    arr[i]=(int*)malloc(size[i]*sizeof(int));
		    for (j=0;j<size[i];j++) {
			    arr[i][j]=rand()%100;
                sum+=arr[i][j];
            }
            #pragma omp critical
                ans+=sum;
	    }
    }
    for(i=0;i<r;i++) {
        printf("Section - %2d ( %3d Items ) : ",i,size[i]);
        for(int j=0;j<size[i];j++)
            printf("%3d ",arr[i][j]);
        printf("\n");
    }
    printf("Total Amount : %d",ans);
}