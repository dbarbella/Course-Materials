// David Barbella
// Example code to introduce pragma omp single nowait

#include <stdio.h>
#include "omp.h"
#include <unistd.h>

int main()
{
   #pragma omp parallel
   {
      int thread_id = omp_get_thread_num();
      printf("Hello! %d ", thread_id);
      printf("World! %d\n", thread_id);
	  #pragma omp single nowait
      {
          sleep(1);
		  printf("This should only happen once\n");
		  printf("Thread %d handled it.\n", thread_id);
      }
      printf("Now I am down here! %d\n ", thread_id);
   }
   return 0;
}
