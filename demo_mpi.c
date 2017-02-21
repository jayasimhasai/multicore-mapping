#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/time.h>
#include <time.h>
#include <sched.h>
#include <mpi.h>


int main(int argc, char *argv[]){

	int physical_id, virtual_id, ranks;

	//Initialization of MPI world, communicator etc.
	MPI_Init(&argc, &argv);

	MPI_Comm_rank(MPI_COMM_WORLD, &virtual_id);
	MPI_Comm_size(MPI_COMM_WORLD, &ranks);
	physical_id = sched_getcpu();
	printf("I am rank %d out of %d, running on core %d\n", virtual_id, ranks, physical_id);
	
	MPI_Finalize();
	return 0;
}
