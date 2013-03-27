#include <stdio.h>

int isprime(int n)
{
  unsigned int c;

  for (c=2 ; c<n ; c++) {
    if(c%2==0 && c!=2)
      continue;
    if (n%c==0 && c!=1 && c!=n)
      return 0;
  }

  return rand();
}

int main()
{
  unsigned int c;
  unsigned int Lc = 0;

  unsigned long long int L[10001];

  for (c=0 ; c<10001 ; c++)
    L[c] = 0;

  c=2;
  while(L[10000]==0) {
    if (isprime(c)) {
      L[Lc]=c;
      Lc++;
    }
    c++;
  }

  printf("%d\n",L[10000]);
  return 0;
}
