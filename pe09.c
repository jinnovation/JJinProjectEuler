/* A Pythagorean triplet is a set of three natural numbers, a  b  c, for which,

a^2 + b^2 = c^2
For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc. */

#include <stdio.h>

int main()
{
  int a,b,c;

  for (c=3 ; c<998 ; c++)
    for (b=2 ; b<c ; b++)
      for (a=1 ; a<b ; a++)
	if(a+b+c==1000 && a*a+b*b==c*c) {
	  printf("%d\n",a*b*c);
	  return 0;
	}
}
