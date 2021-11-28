#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
void main() {
    int num;
    printf("Enter the number of steps : ");
    scanf("%d",&num);
    int i;
    double step=1.0/(double)num,pi=0.0;
    omp_set_num_threads(num);
    #pragma omp parallel
    {
        #pragma omp for
        for(i=0;i<num;i++) {
            double x=(i+0.5)*step;
            double local_pi=(4.0*step)/(1+x*x);
            #pragma omp critical
                pi+=local_pi;
        }
    }
    printf("Value of Pi = %lf\n",pi);
}