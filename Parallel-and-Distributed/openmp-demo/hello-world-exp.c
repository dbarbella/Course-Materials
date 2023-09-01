// David Barbella
// A basic example to introduce OpenMP to students.

#include <stdio.h>
#include "omp.h"

int main()
{
   #pragma omp parallel
   {
      int thread_id = omp_get_thread_num();
      printf("Hello! %d ", thread_id);
      printf("World! %d\n", thread_id);
   }
   return 0;
}
