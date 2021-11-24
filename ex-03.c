#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
void main() {
    int n;
    printf("Enter the size of vector : ");
    scanf("%d",&n);
    int *a,x,*y,*z,i=0;
    a=(int*)malloc(n*sizeof(int));
    y=(int*)malloc(n*sizeof(int));
    z=(int*)malloc(n*sizeof(int));
    omp_set_num_threads(n);
    x=rand()%100;
    #pragma omp parallel
    {
        #pragma omp for
        for(i=0;i<n;i++) {
            srand(i);
            a[i]=rand()%100;
            y[i]=rand()%100;
            z[i]=a[i]*x+y[i];
        }
    }
    printf(" A  *  X  +  Y  =  Z \n");
    for(i=0;i<n;i++) {
        if(i==n/2)
            printf("%3d * %3d + %3d = %3d\n",a[i],x,y[i],z[i]);
        else
            printf("%3d         %3d   %3d\n",a[i],y[i],z[i]);
    }
}