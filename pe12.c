/* The sequence of triangle numbers is generated by adding the natural
   numbers. So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 =
   28. The first ten terms would be: 

   1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

   Let us list the factors of the first seven triangle numbers:

   1: 1
   3: 1,3
   6: 1,2,3,6
   10: 1,2,5,10
   15: 1,3,5,15
   21: 1,3,7,21
   28: 1,2,4,7,14,28
   We can see that 28 is the first triangle number to have over five divisors.

   What is the value of the first triangle number to have over five hundred
   divisors?  */

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

