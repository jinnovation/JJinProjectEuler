#include <stdio.h>
#include<math.h>

unsigned int Mn(unsigned long int n)
{
  unsigned int largest = 0;
  unsigned int a;

  for (a=1 ; a<n ; a++)
    if ((a*a)%n==a && a>=largest)
      largest = a;

  return largest;
}

int main()
{
  unsigned long long int sum = 0;
  unsigned long int a;

  for (a=0 ; a<(pow(10,7)+1) ; a++)
    sum += Mn(a);

  printf("%llu\n", sum);

  return 0;
}
