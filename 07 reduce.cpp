#include<stdio.h>
#include<mpi.h>
int main(int argc, char* argv[])
{
	int sum = 0;
	int rank, numproc;
	MPI_Status status;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numproc);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Reduce(&rank, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	if (rank == 0)
		printf("SUM = %d\n", sum);
	MPI_Finalize();
}