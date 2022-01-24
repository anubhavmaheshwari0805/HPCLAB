#include<stdio.h>
#include<mpi.h>
int main(int argc, char** argv)
{
    int iproc, rank, numproc=10;
    int value, sum = 0;
    int Source, Source_tag;
    int Destination, Destination_tag;
    MPI_Status status;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numproc);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    if (rank == 0) {
        for (iproc = 1; iproc < numproc; iproc++) {
            Source = iproc;
            Source_tag = 0;
            MPI_Recv(&value, 1, MPI_INT, Source, Source_tag, MPI_COMM_WORLD, &status);
            sum = sum + value;
        }
        printf("rank = %d, SUM = %d\n", rank, sum);
    }
    else {
        Destination = 0;
        Destination_tag = 0;
        MPI_Send(&rank, 1, MPI_INT, Destination, Destination_tag, MPI_COMM_WORLD);
    }
    MPI_Finalize();
}