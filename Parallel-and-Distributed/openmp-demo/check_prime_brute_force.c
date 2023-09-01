// Prime calculation code used in ohter examples.

#include <math.h>

unsigned long check_prime_brute_force(unsigned long number) {
	
	unsigned long upper_bound = 0, remainder = 0, divisor = 3;
	
	remainder = number % 2; 
	if (remainder == 0)
		return((unsigned long)0);
	
	/* If I number is not prime, then it can be factored as n = ab.  Consequently 
	one of {a, b} has to be <= sqrt(n), and the other has to be >= sqrt(n).  
	That is, if both a, b are < sqrt(n) then ab < n.  Thanks Tim McLarnan. */

 	upper_bound = (unsigned long)sqrt((double)number);  
	
	while (divisor <= upper_bound) {
		remainder = number % divisor; 

		if (remainder == 0)
			return((unsigned long)0); 

		/* Since we filter all the even numbers, we don't need to divide by
		even divisors.  If we initialize divisor to 3 we can increment by 2
		each time and cut our work in half.  Thanks Tim McLarnan.  */
		divisor += 2;  		
	}
	
	return((unsigned long)1);
}
