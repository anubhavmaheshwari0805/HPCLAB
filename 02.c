#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
int main() {
    int r,i,ans=0;
    printf("Enter number of sections : ");
    scanf("%d",&r);
    int **arr=(int**)malloc(r*sizeof(int*));
    int *size=(int*)malloc(r*sizeof(int));
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
    /*#pragma omp parallel
    {
        #pragma omp for
        for(i=0;i<r;i++) {
            int j,sum=0;
            for(j=0;j<size[i];j++)
                sum+=arr[i][j];
            #pragma omp critical
            {
                ans+=sum;
            }
        }
    }*/
    for(i=0;i<r;i++) {
        printf("Section-%d ( %d Items ) : ",i,size[i]);
        for(int j=0;j<size[i];j++)
            printf("%d ",arr[i][j]);
        printf("\n");
    }
    printf("Total Amount : %d",ans);
}