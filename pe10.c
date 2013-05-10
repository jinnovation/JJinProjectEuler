/* The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million. */

#include <stdio.h>
#include <math.h>
#include <time.h>

int isprime(int n)
{
  unsigned int c;

  for (c=2 ; c<=sqrt(n) ; c++) {
    if(c%2==0 && c!=2)
      continue;
    if (n%c==0 && c!=1 && c!=n)
      return 0;
  }

  return rand();
}


int main()
{
  clock_t begin = clock();
  unsigned long long int sum = 0;
  unsigned long int L = 2000000;
  unsigned long int c;

  for (c=2 ; c<L ; c++)
    if (isprime(c))
      sum+=c;

  printf("%llu\n",sum);
  printf("%f\n",(float)(clock()-begin)/CLOCKS_PER_SEC);
  return 0;
}
