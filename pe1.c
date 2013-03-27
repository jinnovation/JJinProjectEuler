#include <stdio.h>

int main()
{
  unsigned int sum = 0;
  unsigned int c;

  for (c=0 ; c<1000 ; c++)
    if (c%3==0 || c%5==0)
      sum +=c;

  printf("%d\n",sum);

  return 0;
}
