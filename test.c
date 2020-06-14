#include <stdio.h>
#include <inttypes.h>
#include "keygen.h"


int main(){
	uint64_t n,alpha, keya, keyb, valuea, valueb, sA, sB;

	keya = generateDiffieHellmanParams(&alpha, &n,&valuea);

	keyb = diffieHellmanParams(alpha,n,&valueb);

	sA = diffieHellman(valueb, keya, n);
	sB = diffieHellman(valuea, keyb, n);



	printf("alpha=%lu, n=%lu, keya=%lu keyb=%lu Sa=%lu Sb=%lu\n",alpha,n,keya,keyb, sA, sB);
	return 0;
}
