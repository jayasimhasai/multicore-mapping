#define _GNU_SOURCE
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sched.h>
#include <semaphore.h>
#include <sys/time.h>

sem_t mutex;
int count=0;

double dtime()
{
    double tseconds = 0.0;
    struct timeval mytime;
    gettimeofday(&mytime,(struct timezone*)0);
    tseconds = (double)(mytime.tv_sec + mytime.tv_usec*1.0e-6);
    return( tseconds );
}

void* DoWork(void* threadid) {
    printf("ID: %lu, CPU: %d\n", pthread_self(), sched_getcpu());
	sleep(2);
	sem_wait(&mutex);	
	count++;
	sleep(.1);
	printf("ThreadID: %d, Count: %d, ID: %lu, CPU: %d\n", (int) threadid,count,pthread_self(), sched_getcpu());
	sem_post(&mutex);
    return 0;
}

int main() {   

    int numberOfProcessors = sysconf(_SC_NPROCESSORS_ONLN);
    int i;
double tstart,tstop;
    printf("Number of processors: %d\n", numberOfProcessors);

    pthread_t threads[numberOfProcessors];

    pthread_attr_t attr;
    cpu_set_t cpus;
    pthread_attr_init(&attr);
    sem_init(&mutex, 0, 1);
tstart = dtime();
    for (i=0; i < numberOfProcessors; i++) {
       CPU_ZERO(&cpus);
       CPU_SET(i, &cpus);
       pthread_attr_setaffinity_np(&attr, sizeof(cpu_set_t), &cpus);
       pthread_create(&threads[i], &attr, DoWork, (void *)i);
    }

    for (i=0; i < numberOfProcessors; i++) {
        pthread_join(threads[i], NULL);
    }
	tstop = dtime();
printf("Execution time = %10.3lf\r\n",tstop-tstart);
    return 0;
}
