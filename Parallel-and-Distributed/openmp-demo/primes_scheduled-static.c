// David Barbella
// Example code to introduce static scheduling.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <getopt.h>
#include "omp.h"
#include "check_prime_brute_force.h"

int main(int argc, char *argv[]) {
	int debug = 0;	
	unsigned long start_value = 3;
	unsigned long stop_value = 10000;
	unsigned long total_primes = 0;
	int thread_count = 1;	
	int opt = 0; // for command line argument processing
		
	unsigned long upper_bound = 0;
	unsigned long remainder = 0;
	unsigned long divisor = 2;
	unsigned long number = 0; 

	while ((opt = getopt(argc, argv, "de:t:")) != -1)
	{ 
		switch (opt)
		{
			case 'd':
				debug = 1;
				break;

			case 'e':
				stop_value = strtoul(optarg, (char**) NULL, 10);
				break;

			case 't':
				thread_count = strtol(optarg, (char**) NULL, 10);
				break;

			case '?':
				fprintf(stderr, "usage: -d -e <end_value> -t <thread_count>\n"); 
				fprintf(stderr, "where -d enables debugging\n"); 
				exit(1); 

			default:
				break;
		}
	}
	
	// Make sure we have at least one thread
	if (thread_count < 1)
	{
		fprintf(stderr, "thread_count must be greater than or equal to 1\n");  
		exit(1); 
	}
	
	#pragma omp parallel num_threads(thread_count)
	{
		long long int my_primecount = 0;
		int thread_id = omp_get_thread_num();
		
		#pragma omp for schedule(static,1)
		for (int i = start_value; i <= stop_value; i++)
		{			
			if (check_prime_brute_force(i) == 1)
			{
				my_primecount += 1;
			}										
		}
		total_primes += my_primecount;
		// This print statement isn't going to do
		// what we expect; why not?
		// This is also commented out because printing is a time-expensive operation.
		//printf("Thread %d finished.\n", thread_id);
	}

	printf("%lu primes between 3 and %lu\n", total_primes, stop_value); 
	return(0); 		
}