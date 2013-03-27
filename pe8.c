#include <stdio.h>

int main()
{
  int out = 0;
  int outtemp = 0;
  unsigned int numdigits = 1000;

  short int digits[numdigits];
  char temp[2];

  unsigned int c;

  for (c=0 ; c<numdigits ; c++) {
    temp[0] = (char)getchar();
    temp[1] = '\0';
    digits[c] = atoi(temp);
  }

  for (c=4; c<numdigits ; c++) {
    outtemp=digits[c]*digits[c-1]*digits[c-2]*digits[c-3]*digits[c-4];
    if (outtemp >= out)
      out = outtemp;
  }

  printf("%d\n",out);

  return 0;
}

