#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<mpi.h>
int main(int argc, char* argv[])
{
	int numtasks, rank, rc, count, next, prev, sz, inmsg;
	MPI_Status Stat;
	time_t st, et;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
	sz = (numtasks / 2) * 2;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	st = clock();
	if (rank == 0) prev = sz - 1;
	else prev = rank - 1;
	if (rank == sz - 1) next = 0;
	else next = rank + 1;
	if (rank % 2 == 0 && rank < sz) {
		rc = MPI_Send(&rank, 1, MPI_INT, next, 0, MPI_COMM_WORLD);
		rc = MPI_Recv(&inmsg, 1, MPI_INT, prev, 1, MPI_COMM_WORLD, &Stat);
	}
	else if (rank % 2 == 1 && rank < sz) {
		rc = MPI_Recv(&inmsg, 1, MPI_INT, prev, 0, MPI_COMM_WORLD, &Stat);
		rc = MPI_Send(&rank, 1, MPI_INT, next, 1, MPI_COMM_WORLD);
	}
	MPI_Barrier(MPI_COMM_WORLD);
	et = clock();
	if(rank==0) printf("Time taken by Blocking send/receive : %lf\n", (double)(et - st) / CLOCKS_PER_SEC);
	MPI_Barrier(MPI_COMM_WORLD);
	MPI_Request reqs[2];
	MPI_Status stats[2];
	st = clock();
	if (rank == numtasks - 1) next = 0;
	else next = rank + 1;
	if (rank == 0) prev = numtasks - 1;
	else prev = rank - 1;
	MPI_Irecv(&inmsg, 1, MPI_INT, prev, 0, MPI_COMM_WORLD, &reqs[0]);
	MPI_Isend(&rank, 1, MPI_INT, next, 0, MPI_COMM_WORLD, &reqs[1]);
	MPI_Barrier(MPI_COMM_WORLD);
	et = clock();
	if (rank == 0) printf("Time taken by NonBlocking send/receive : %lf\n", (double)(et - st) / CLOCKS_PER_SEC);
	MPI_Finalize();
}