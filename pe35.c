#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* returns 1 if any digit in given number is 0 */
int any_zero(int n)
{
  char nstring[7];
  sprintf(nstring,"%d",n);

  int len = strlen(nstring);

  int i;
  for (i=0 ; i<len ; i++) {
    if (nstring[i]=='0')
      return 1;
  }
  
  return 0;
}


int isPrime(int n)
{
  unsigned int c;

  for (c=2 ; c<n ; c++) {
    if(c%2==0 && c!=2)
      continue;
    if (n%c==0 && c!=1 && c!=n)
      return 0;
  }

  return 1;
}

/* given number, output array of all possible rotations of digits */
/* Ex:  197 outputs [197, 971, 719] */
int *cpermute(int n)
{
  return 0;
}

/* return 1 if number is circular prime */
int is_cprime(int n)
{
  int i;
  int *permutes = cpermute(n);
  int numPermutes = sizeof(permutes)/sizeof(int);

  for (i=0 ; i < numPermutes ; i++)
    if (!isPrime(permutes[i])) return 0;

  return 1;
}


int main()
{

  return 0;
}
