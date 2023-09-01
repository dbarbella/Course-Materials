// David Barbella
// Example code that introduces race conditions.

#include <stdio.h>
#include "omp.h"

int main()
{
	int data_array[] =
    {4, 3, 1, 2};
	
    int array_length = sizeof(data_array) / sizeof(data_array[0]);
    int thread_count = 4;
	int total = 0;
	
    #pragma omp parallel num_threads(thread_count)
    {      
	    int thread_id = omp_get_thread_num();
		
		int my_value = data_array[thread_id];
		int my_square = my_value * my_value;
		
		total += my_square;
    }
	printf("Final total: %d\n", total);;	
    return 0;
}
