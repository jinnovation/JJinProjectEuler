vc/********************************************************************************/
/* If we list all the natural numbers below 10 that are multiples of 3 or 5, we */
/*    get 3, 5, 6 and 9. The sum of these multiples is 23.		        */
/* 									        */
/* Find the sum of all the multiples of 3 or 5 below 1000.		        */
/********************************************************************************/

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
