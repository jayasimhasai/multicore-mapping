
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/time.h>
#include <time.h>
#include <sched.h>
#include <omp.h>


int main(int argc, char *argv[]){

	int i, physical_id, virtual_id;

#pragma omp parallel for simd private(physical_id, virtual_id, i)
	for (i=0; i<20; i++) {

		virtual_id = omp_get_thread_num();
		physical_id = sched_getcpu();
		printf("I am thread %d, running on core %d\n", virtual_id, physical_id);	
	}

	return 0;
}
