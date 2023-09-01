// David Barbella
// Example code to introduce a master thread.

#include <stdio.h>
#include "omp.h"

int main()
{
    //int array_length = 16;
	int my_array[] =
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	int array_length = sizeof(my_array) / sizeof(my_array[0]);
	int thread_count = 4;
	
    #pragma omp parallel num_threads(thread_count)
    {      
	    int thread_id = omp_get_thread_num();
		#pragma omp master
		{ printf("I'm thread %d, the master thread\n", thread_id); }
	
		#pragma omp for
		for (int i=0; i < array_length; i++)
		{ printf("Thread %d handling: %d.\n", thread_id, my_array[i]); }
		printf("Thread %d finished.\n", thread_id);
    }
    return 0;
}