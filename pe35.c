/* The number, 197, is called a circular prime because all rotations of the
   digits: 197, 971, and 719, are themselves prime. 

   There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71,
   73, 79, and 97. 

   How many circular primes are there below one million? */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 1000000
#define MAXLEN 7

/* returns 1 if any digit in given number is 0 */
int any_zero(int n)
{
  char nstring[MAXLEN];
  sprintf(nstring,"%d",n);

  int len = strlen(nstring);

  int i;
  for (i=0 ; i<len ; i++)
    if (nstring[i]=='0')
      return 1;
  
  return 0;
}

/* return 1 if given int is prime */
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

/* given number, return number of digits in that number */
int numDigits(int n)
{
  return log10(n)+1;
}

/* given number, output array of its digits */
int *numToDigits(int n)
{
  int len = numDigits(n);
  int *out = (int *)calloc(len,sizeof(int));

  char nstring[len];
  sprintf(nstring,"%d",n);

  int i;
  for (i=0 ; i<len ; i++)
    out[i] = nstring[i] - '0';
  
  return out;
}

/* TODO */
/* given number, output array of all possible rotations of digits */
/* Ex:  197 outputs [197, 971, 719] */
int *cPermute(int n)
{
  return 0;
}

/* return 1 if number is circular prime */
int isCPrime(int n)
{
  int i;
  int *permutes = cPermute(n);
  int numPermutes = sizeof(permutes)/sizeof(int);

  for (i=0 ; i < numPermutes ; i++)
    if (!isPrime(permutes[i])) return 0;

  return 1;
}


int main()
{

  int *test = (int *)calloc(3,sizeof(int));
  test = numToDigits(123);

  printf("%d %d %d\n",test[0],test[1],test[2]);

  /* int out = 0; */

  /* int i; */
  /* for (i=0 ; i<MAX ; i++) */
  /*   if (isCPrime(i)) out++; */

  /* printf("%d\n", out); */
  /* return 0; */
}
