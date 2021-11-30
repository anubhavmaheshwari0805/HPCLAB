#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<omp.h>
void main() {
    int num,i;
    printf("Enter the number of steps : ");
    scanf("%d",&num);
    time_t st,et;
    st=clock();
    double step=1.0/(double)num,pi=0.0;
    omp_set_num_threads(num);
    #pragma omp parallel for reduction(+:pi)
    for(i=0;i<num;i++) {
        double x=(i+0.5)*step;
        double local_pi=(4.0*step)/(1+x*x);
        pi+=local_pi;
    }
    et=clock();
    printf("Time Taken : %lf\n",(double)((double)(et-st)/CLOCKS_PER_SEC));
    printf("Value of Pi = %lf\n",pi);
}