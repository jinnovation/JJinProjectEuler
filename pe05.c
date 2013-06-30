/* 2520 is the smallest number that can be divided by each of the numbers from 1
   to 10 without any remainder. 

What is the smallest positive number that is evenly divisible by all of the
numbers from 1 to 20? */

#include <stdio.h>

int main()
{
  unsigned int out;
  unsigned int divmax = 20;

  unsigned int c1;
  unsigned int c2;

  for (c1=1 ; ; c1++) {
    for (c2=1 ; c2<=divmax+1 ; c2++) {
      if (c2==divmax+1) {
	out = c1;
	printf("%d\n",out);
	return 0;
      }
      else if (c1%c2!=0)
	break;
    }
  }
}



