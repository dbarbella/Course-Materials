// David Barbella
// A basic exmaple to introduce specifying a thread count.

#include <stdio.h>
#include "omp.h"

int main()
{
   int thread_count = 6;
   #pragma omp parallel num_threads(thread_count)
   {      
	  int thread_id = omp_get_thread_num();
      printf("Hello! %d ", thread_id);
      printf("World! %d\n", thread_id);
   }
   return 0;
}
