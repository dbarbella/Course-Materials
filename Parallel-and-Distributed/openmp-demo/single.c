// David Barbella
// Example code to introduce pragma omp single

#include <stdio.h>
#include "omp.h"

int main()
{
   #pragma omp parallel
   {
      int thread_id = omp_get_thread_num();
      printf("Hello! %d ", thread_id);
      printf("World! %d\n", thread_id);
	  #pragma omp single
      {
          printf("This should only happen once\n");
		  printf("Thread %d handled it.\n", thread_id);
      }

   }
   return 0;
}
