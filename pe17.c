#include <stdio.h>
#include <math.h>

int digispell(unsigned short int n)
{
  switch (n) {
  case 1:
  case 2:
  case 6:
    return 3;
  case 3:
  case 7:
  case 8:
    return 5;
  case 4:
  case 5:
  case 9:
    return 4;
  }
}


int spell(int n)
{
  int count = 0;

  unsigned short int unit_d = n%10;
  unsigned short int ten_d;
  unsigned short int hundred_d;
  unsigned short int thousand_d;

  if (n>=1000) {
    thousand_d = floor(n/1000);

    count += digispell(thousand_d);
    count += 8; // "thousand"

    n -= thousand_d*1000; 
  }


  if (n>=100) {
    hundred_d = floor(n/100);

    count += digispell(hundred_d); // hundreds digit
    count += 7; // "hundred"
    if ((n%100-unit_d)/10!=0 || n%10!=0) // if either 10s or 1s digit is not 0
      count += 3; // "and"

    n -= hundred_d*100;
  }

  if (n>=20) {
    ten_d = (n%100-unit_d)/10;

    switch (ten_d) {
    case 0:
      break;
    case 2: // "twenty"
    case 3: // "thirty"
    case 8: // "eighty"
    case 9: // "ninety"
      count += 6;
      break;
    case 4: // "forty"
    case 5: // "fifty"
    case 6: // "sixty"
      count += 5;
      break;
    case 7: // "seventy"
      count += 7;
      break;
    }

    if (unit_d!=0)
      count += digispell(unit_d);
  }

  else if (n>=10)
    switch (unit_d) {
    case 0: // "ten"
      count += 3;
      break;
    case 1: // "eleven"
    case 2: // "twelve"
      count += 6;
      break;
    case 3: // "thirteen"
    case 4: // "fourteen"
    case 8: // "eighteen"
    case 9: // "nineteen"
      count += 8;
      break;
    case 5: // "fifteen"
    case 6: // "sixteen"
      count += 7;
      break;
    case 7: // "seventeen"
      count += 9;
      break;
    }

  else
    count += digispell(unit_d);

  return count;
}

int main()
{
  unsigned long int count = 0;
  unsigned int c;

  for (c=1 ; c<=1000 ; c++)
    count += spell(c);

  printf("%ld\n", count);
  return 0;
}
