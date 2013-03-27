#include <stdio.h>

int main()
{
  unsigned long int f = 1;
  unsigned long int s = 1;

  unsigned long int new;

  unsigned long int sum = 0;

  new=f+s;

  while (new <= 4000000) {
    if (new%2==0)
      sum+=new;

    f = s;
    s = new;
    new=f+s;
  }

  printf("%d\n",sum);
  return 0;
}
