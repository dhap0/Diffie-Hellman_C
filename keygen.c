
//#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <inttypes.h>

#include "keygen.h"

uint64_t randomRange(uint64_t min, uint64_t max);


/*  find max primes in 0-limit that are bigger than bottom */
int atkinSieve(uint64_t limit, uint64_t bottom, unsigned int max,  uint64_t *primes)
{
	uint8_t sieve[limit];
	for(int i = 0; i < limit; i++)
		sieve[i] = 0;

	for(int x = 1; x*x < limit; x++)
	{
		for(int y = 1; y*y < limit; y++)
		{
			int n = (4*x*x) + (y*y);
			if( n >= bottom && n <= limit && (n%12 == 1 || n%12 == 5))
				sieve[n] ^= 0xff;


			n = (3*x*x) + (y*y);
			if (n >= bottom && n <= limit && n%12==7)
				sieve[n] ^= 0xff;


			n = (3*x*x) - (y*y);
			if(x>y && n >= bottom && n <= limit && n%12==11)
				sieve[n] ^= 0xff;

		}
	}


	for(int i = 5; i*i < limit; i++)
	{
		if(sieve[i])
		{
			for(int j = i*i; j < limit; j += i*i) 
				sieve[j] = 0;
		}
	}

	int j = 0;
	if(bottom < 3)
		primes[j++] = 2;
	if(bottom < 4)
		primes[j++] = 3;
	for(int i = (bottom < 5)? 5: bottom; i < limit && j < max; i++)
	{
		if(i >=bottom && sieve[i])
			primes[j++] = i;
	}
	return j;

}


uint64_t prime(uint64_t limit, uint64_t bottom)
{
	unsigned int max , len;
	max = limit-bottom;
	uint64_t primes[max];
	len = atkinSieve(limit,bottom,max,primes);
//	for(int i = 0; i < len; ++i)
//		printf("%d ",primes[i]);
	uint64_t r = randomRange(0,len);
	return primes[r];
}

uint64_t randomRange(uint64_t min, uint64_t max)
{
	uint64_t d,seed, r;
	d = max - min + 1;
 	seed	= clock();
	srand(seed);
	r = (rand()%d) + min;
	return r;
 		

}

uint64_t generateDiffieHellmanParams(uint64_t *alpha, uint64_t *n, uint64_t *value)
{
	if(alpha==NULL || n==NULL || value ==NULL )
		return -1;
	uint64_t  key;
	*n =prime(100000,7919) ;
	*alpha = randomRange(1,*n); 
	key = randomRange(1,*n);
	*value = (uint64_t) ((int64_t)pow(*alpha,key)) % (*n);

	return key;
	
}

uint64_t diffieHellmanParams(uint64_t alpha, uint64_t n, uint64_t *value)
{
	if(value==NULL)
		return -1;
	
	uint64_t key = randomRange(1,n);
	*value = (uint64_t) ((int64_t)pow(alpha,key)) % (n);
	return key;
}

uint64_t diffieHellman(uint64_t other, uint64_t key, uint64_t n){
	uint64_t secret = (uint64_t) ((int64_t)pow(other,key)) % (n);
	return secret;
}

