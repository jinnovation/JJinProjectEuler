#include <stdio.h>

int main()
{
  unsigned short int ns[100][50];
  unsigned short int sum[52]; // head summation not possible be >3 digits

  /* ==== COUNTERS AND HOLDERS ==== */
  unsigned int l=0; // line
  unsigned int d=0; // digit
  unsigned int tsum; // temporary digit sum holder
  unsigned int carry = 0; // carryover value

  /* ==== PARSING ==== */
  char temp[2];
  temp[1] = '\0';
  for (l=0 ; l<100 ; l++) {
    for (d=0 ; d<50 ; d++) {
      temp[0] = getchar();
      ns[l][d] = atoi(temp);
    }
    getchar(); // end of line (newline or otherwise)
  }

  /* ==== SUMMATION ==== */
  for (d=0 ; d<50 ; d++) {
    tsum = carry;

    for (l=0 ; l<100 ; l++)
      tsum += ns[l][49-d]; // sum relevant digit from each line

    if (d==49) { // sum of 1st digits cannot >3 digits; breaking sum up
      sum[2] = tsum%10;
      sum[1] = (tsum%100-sum[2])/10;
      sum[0] = (tsum-sum[1]*10-sum[2])/100;

      /* ==== OUTPUT ==== */
      unsigned int c;
      for (c=0 ; c<10 ; c++)
	printf("%d",sum[c]);
      putchar('\n');
      return 0;
    }

    else {
      sum[51-d] = tsum%10; // units digit
      carry = (tsum - sum[51-d])/10; // "carryover" operation
    }
  }
}
