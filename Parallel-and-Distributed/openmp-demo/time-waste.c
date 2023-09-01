// David Barbella
// Example code for introducing characteristics of parallel for

#include <stdio.h>
#include "omp.h"
#include <unistd.h>

int main()
{
	
    int thread_count = 4;
	int total_jobs = 16;
	
    #pragma omp parallel num_threads(thread_count)
    {      
	    int thread_id = omp_get_thread_num();
		#pragma omp for
		for (int i=0; i < total_jobs; i++)
		{
			printf("Thread %d handling: %d.\n", thread_id, i);
			sleep(i);
		}
		printf("Thread %d finished.\n", thread_id);
    }
    return 0;
}

