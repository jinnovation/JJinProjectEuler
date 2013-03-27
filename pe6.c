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

