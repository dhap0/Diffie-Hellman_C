
#include <inttypes.h>

/*  find <max> primes in 0-<limit> that are bigger or equal than <bottom> */
int atkinSieve(uint64_t limit, uint64_t bottom, unsigned int max,  uint64_t *primes);

uint64_t diffieHellman(uint64_t other, uint64_t key, uint64_t n);
uint64_t diffieHellmanParams(uint64_t alpha, uint64_t n, uint64_t *value);
uint64_t generateDiffieHellmanParams(uint64_t *alpha, uint64_t *n, uint64_t *value);

uint64_t prime(uint64_t limit, uint64_t bottom);
uint64_t randomRange(uint64_t min, uint64_t max);

