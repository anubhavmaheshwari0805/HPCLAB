#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<omp.h>
void main() {
    unsigned long long int num,i;
    printf("Enter the number of steps : ");
    scanf("%llu",&num);
    time_t st,et;
    st=clock();
    double step=1.0/(double)num, pi=0.0;
    double *local_pi=(double*)malloc(num*sizeof(double));
    omp_set_num_threads(num);
    #pragma omp parallel for
    for(i=0;i<num;i++) {
        double x=(i+0.5)*step;
        local_pi[i]=(4.0*step)/(1+x*x);
    }
    for(i=0;i<num;i++)
        pi+=local_pi[i];
    et=clock();
    printf("Time Taken : %lf\n",(double)((double)(et-st)/CLOCKS_PER_SEC));
    printf("Value of Pi = %lf\n",pi);
}