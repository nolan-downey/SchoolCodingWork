#ifndef PRIMES_H
#define PRIMES_H


bool isPrime( long unsigned int n ){
	
	if( n == 2 || n == 3){
		return true;
	}
	
	if( n == 1 || n % 2 == 0 ){
		return false;
	}
	
	for( long unsigned int i = 3; i * i <= n; i += 2 ){
		if( n % i == 0 ){
			return false;
		}
	}
	
	return true;
}


long unsigned int nextPrime( long unsigned int n ){
	
	// If n is even, make it odd
	if( n % 2 == 0 ){
		++n;
	}
	
	for( ; !isPrime(n); n+=2 ){
		// Do Nothing
	}
	
	return n;
}



#endif