#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>
int main(int argc, char** argv)
{
    int rank, numproc;
    int sum = 0;
    int total_sum = 0;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numproc);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    srand(rank);
    sum = rand() % 100;
    printf("Robot %d picked %d mangoes.\n", rank, sum);
    MPI_Reduce(&sum, &total_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    if (rank == 0)
        printf("Total Mangoes picked by %d Robots = %d\n", numproc, total_sum);
    MPI_Finalize();
}