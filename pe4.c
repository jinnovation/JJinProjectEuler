#include <stdio.h>
#include <string.h>

/* destructive reverse */
void reverse(char *s)
{
  int L = strlen(s);
  int c,i,j;

  for (i=0, j=L-1 ; i<j ; i++,j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }

  return;
}


int main()
{
  unsigned long int M_prev = 0;
  unsigned long int M;

  char Mstr[7];
  char Mstr_temp[7];

  int n;

  unsigned int mult1, mult2;

  for (mult1=100 ; mult1<1000 ; mult1++)
    for (mult2=100 ; mult2<1000 ; mult2++) {
      M = mult1*mult2;
      sprintf(Mstr,"%d",M);
      strcpy(Mstr_temp,Mstr);
      reverse(Mstr);

      if (strcmp(Mstr,Mstr_temp)==0 && M>=M_prev)
	M_prev = M;
    }

  printf("%d\n", M_prev);

  return 0;
}
