// David Barbella
// Example code to introduce a scenario where we might use reduction.

#include <stdio.h>
#include "omp.h"

int main()
{
    //int array_length = 16;
	int our_array[] =
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int array_length = sizeof(our_array) / sizeof(our_array[0]);
    int thread_count = 4;
	int total = 0;
	
    #pragma omp parallel num_threads(thread_count)
    {      
	    int thread_id = omp_get_thread_num();
		#pragma omp for
		for (int i=0; i < array_length; i++)
		{
			total += our_array[i];
		}
    }
	printf("%d is the total.\n", total);
    return 0;
}