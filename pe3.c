#include <stdio.h>

void factorize(long long int n)
{
  int d = 2;

  if (n < 2) return;

  while (d<n) {
    if (n%d==0) {
      printf("%d x ", d);
      n /= d;
    }
    else {
      if (d == 2) d=3;
      else d+=2;
    }
  }
  printf("%d\n", d);
}


int main()
{
  unsigned long long int n = 600851475143;
  factorize(n);

  return 0;
}
