#include <stdio.h>
#include <math.h>

int main()
{
  unsigned int divisorL = 500;
  unsigned int numDivisors;

  unsigned long long int currentTri = 0;

  /* ==== counters ==== */
  unsigned long long int n; // trial
  unsigned long long int d; // divisor determination

  for (n=1 ; ; n++) {
    numDivisors = 1;
    currentTri+=n;

    for (d=1 ; d<=sqrt(currentTri) ; d++)
      if (currentTri%d==0)
	numDivisors+=2;

    if (numDivisors>divisorL) {
      printf("%llu\n",currentTri);
      return 0;
    }
  }
}

