/* The sum of the squares of the first ten natural numbers is,

1^2 + 2^2 + ... + 10^2 = 385
The square of the sum of the first ten natural numbers is,

(1 + 2 + ... + 10)^2 = 55^2 = 3025
Hence the difference between the sum of the squares of the first ten natural
numbers and the square of the sum is 3025  385 = 2640. 

Find the difference between the sum of the squares of the first one hundred
natural numbers and the square of the sum.  */

#include <stdio.h>

unsigned long int sumsquare(int L)
{
  unsigned long int out = 0;

  unsigned int c;

  for (c=1 ; c<=L ; c++)
    out += c*c;

  return out;
}


int sum(int L)
{
  unsigned int out = 0;
  unsigned int c;
  
  for (c=1 ; c<=L ; c++)
    out += c;
 
  return out;
}


unsigned long int squaresum(int L)
{
  int s = sum(L);

  return s*s;
}


int main()
{
  int L = 100;

  unsigned long int s_square = sumsquare(L);
  unsigned long int square_s = squaresum(L);

  printf("%d\n",square_s-s_square);

  return 0;
}

