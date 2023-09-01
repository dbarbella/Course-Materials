// David Barbella
// Example code to show off parallel code operation with OpenMP.

#include <stdio.h>
#include "omp.h"

int main()
{
    //int array_length = 16;
	int my_array[] =
    {4, 7, 1, 7, 
	 3, 12, 8, 7,
	 3, 6, 13, 6,
	 2, 5, 3, 1};
	
    int array_length = sizeof(my_array) / sizeof(my_array[0]);
	
    int thread_count = 4;
	
	// This assumes that the number of threads evenly divides
	// the length of the array.
	int vals_per_thread = array_length / thread_count;
	
    #pragma omp parallel num_threads(thread_count)
    {      
	    int thread_id = omp_get_thread_num();
		
		// current_index is initially the start location.
		int current_index = vals_per_thread * thread_id;
		int end_loc = current_index + vals_per_thread;
		
		while (current_index < end_loc)
		{
		    printf("Thread %d handling: %d.\n", thread_id, my_array[current_index]);
			current_index += 1;
		}
    }
    return 0;
}
