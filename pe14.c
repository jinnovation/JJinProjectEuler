/* The following iterative sequence is defined for the set of positive integers:

n -> n/2 (n is even)
n -> 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1

It can be seen that this sequence (starting at 13 and finishing at 1) contains
10 terms. Although it has not been proved yet (Collatz Problem), it is thought
that all starting numbers finish at 1. 

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million. */

#include <stdio.h>
#include <time.h>
#define MAX 1000000

/* in:  starting num
   out: length of generated collatz sequence */
unsigned long int collatz(unsigned long int n)
{
  unsigned long int L = 1;
  unsigned long int s = n;

  while (s!=1) {
    if (s%2!=0)
      s=3*s+1;
    else
      s/=2;

    L++;
  }

  return L;
}

int main()
{
  clock_t begin, end;
  begin = clock();

  unsigned long int start;
  unsigned long int longestStart;
  unsigned long int longestL = 0;
  unsigned long int c;

  for (start=1 ; start<MAX ; start++) {
    c = collatz(start);
    if (c>=longestL) {
      longestL = c;
      longestStart = start;
    }
  }

  printf("Starting num producing longest length: %lu\n",longestStart);
  printf("Function run time: %fms\n",1000*(float)(clock()-begin)/CLOCKS_PER_SEC);
  return 0;
}
