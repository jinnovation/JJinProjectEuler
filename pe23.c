#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX 28123 // all ints >28123 writeable as sum of two abundant nums

unsigned int sumOfDivisors(unsigned int n)
{
  unsigned int sum = 0;
  unsigned int d; // divisor counter

  for (d=1 ; d<=sqrt(n) ; d++)
    if (n%d==0)
      sum += d==sqrt(n)||d==1 ? d : (d+n/d);

  return sum;
}


/* returns array of all abundant nums less than max parameter,
   outputs size of resulting array to size parameter */
unsigned int *abunNums(unsigned int max, unsigned int *size)
{
  unsigned int *out = NULL;
  unsigned int c;
  unsigned int n = 0; 		/* array size representer */

  for (c=12 ; c<max ; c++) // 12 is smallest abundant num
    if (sumOfDivisors(c)>c || c%12==0) {
      n+=1;
      out = (unsigned int *)realloc(out,sizeof(unsigned int)*n);
      out[n-1] = c;
    }

  *size = n;
  return out;
}


/* returns 1 if n exists in ns,
   0 otherwise */
int inList(unsigned int *ns, unsigned int n, unsigned int numElements)
{
  unsigned int c;

  for (c=0 ; c<numElements ; c++)
    if (n==ns[c])
      return 1;

  return 0;
}


/* returns 1 if n writeable as sum of any two elements in ns,
   0 otherwise */
int summableFromList(unsigned int *ns, unsigned int n, unsigned int numElements)
{
  unsigned int c;

  for (c=0 ; c<numElements ; c++)
    if (inList(ns,n-ns[c],numElements))
      return 1;

  return 0;
}


int main()
{
  clock_t start = clock();

  unsigned int sum = 0;

  unsigned int n;
  unsigned int *abuns = abunNums(MAX, &n);

  unsigned int c;		/* counter */

  for (c=1 ; c<=MAX ; c++)
    /* every even num >46 writeable as sum of two abundant nums */
    if (!summableFromList(abuns,c,n))
      sum+=c;

  printf("%d\n",sum);
  printf("Execution time: %d seconds\n", (clock()-start)/CLOCKS_PER_SEC);
  return 0;
}
