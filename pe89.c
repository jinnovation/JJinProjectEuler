#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* returns num of lines in given file */
unsigned int fileLines(FILE *file)
{
  char c;
  unsigned int lines = 0;

  while ((c=fgetc(file))!=EOF)
    if (c=='\n')
      lines++;

  rewind(file);

  return lines;
}


/* copies each line of file as string into element in "out" string array
 (size of "out" array determined prior) */
void file_parse(FILE *file, char **out)
{
  char *n = (char *)malloc(sizeof(char)*100); /* string holder */
  unsigned int c = 0;		/* array index */
  size_t s;			/* string length holder */

  while (fgets(n,100,file)!=NULL) {
    out[c] = (char *)malloc(sizeof(char)*strlen(n)); /* +1 for \0, -1 for \n */
    strcpy(out[c],n);

    /* strips away trailing newlines (inc. by strcpy) */
    s = strlen(out[c]);
    if (s && (out[c][s-1]=='\n')) out[c][--s]=0;
    
    c++;
  }

  free(n);
  return;
}


/* roman numeral "digit" -> arabic num */
int romAra_single(char digit)
{
  switch (digit) {
  case 'M':
    return 1000;
  case 'D':
    return 500;
  case 'C':
    return 100;
  case 'L':
    return 50;
  case 'X':
    return 10;
  case 'V':
    return 5;
  case 'I':
    return 1;
  default:
    fprintf(stderr,"romAra_single: invalid Roman numeral given\n");
    exit(1);
  }
}


/* multi-"digit" roman num -> arabic num */
/* assumes no more than one concurrent "subtraction" */
unsigned long int romAra(char *roman)
{
  unsigned long int ara = 0; 	/* output */

  unsigned short int d; 	/* digit counter */
  unsigned int c;		/* digit value container */

  for (d=0 ; roman[d]!='\0' ; d++) {
    c=romAra_single(roman[d]);

    if (roman[d+1]=='\0')
      ara+=c;
    else if (c<romAra_single(roman[d+1]))
      ara-=c;
    else
      ara+=c;
  }

  return ara;
}


/* in: digit and its "place" (units, tens, etc.) repped as 1, 10, 100, or 1000 */
/* out: combination of letters to best represent in roman */
char *araRom_single(int digit, int place)
{
  char *temp = (char *)malloc(sizeof(char)*100);
  unsigned short int c;

  switch (place) {
  case 1:
    switch (digit) {
    case 1:
      temp = "I\0";
      break;
    case 2:
      temp = "II\0";
      break;
    case 3:
      temp = "III\0";
      break;
    case 4:
      temp = "IV\0";
      break;
    case 5:
      temp = "V\0";
      break;
    case 6:
      temp = "VI\0";
      break;
    case 7:
      temp = "VII\0";
      break;
    case 8:
      temp = "VII\0";
      break;
    case 9:
      temp = "IX\0";
      break;
    default:
      return "\0";
    }
    break;
  case 10:
    switch (digit) {
    case 1:
      temp = "X\0";
      break;
    case 2:
      temp = "XX\0";
      break;
    case 3:
      temp = "XXX\0";
      break;
    case 4:
      temp = "XL\0";
      break;
    case 5:
      temp = "L\0";
      break;
    case 6:
      temp = "LX\0";
      break;
    case 7:
      temp = "LXX\0";
      break;
    case 8:
      temp = "LXX\0";
      break;
    case 9:
      temp = "XC\0";
      break;
    default:
      return "\0";
    }
    break;
  case 100:
    switch (digit) {
    case 1:
      temp = "C\0";
      break;
    case 2:
      temp = "CC\0";
      break;
    case 3:
      temp = "CCC\0";
      break;
    case 4:
      temp = "CD\0";
      break;
    case 5:
      temp = "D\0";
      break;
    case 6:
      temp = "DC\0";
      break;
    case 7:
      temp = "DCC\0";
      break;
    case 8:
      temp = "DCC\0";
      break;
    case 9:
      temp = "CM\0";
      break;
    default:
      return "\0";
    }
    break;
  case 1000:
    switch (digit) {
    case 0:
      return "\0";
    default:
      for (c=0 ; c<digit ; c++)
	temp[c] = 'M';
      temp[c] = '\0';
      break;
    }
    break;
  }

  char *out = (char *)malloc(sizeof(char)*(strlen(temp)+1));
  strcpy(out,temp);
  free(temp);
  return out;
}


/* converts arabic num to roman */
/* assumes num representable by no higher than M */
char *araRom(unsigned int n)
{
  unsigned int c = 0;		/* counter */
  char *rtemp = (char *)malloc(sizeof(char)*100); /* roman num holder */
  rtemp = "\0";				  /* to be appended onto */

  unsigned short int d[4];

  /* 1's digit */
  d[3] = n%10;
  /* 10's digit */
  d[2] = (n%100 - d[3])/10;
  /* 100's digit */
  d[1] = (n%1000 - d[2] - d[3])/100;
  /* 1000's digit */
  d[0] = n/1000;


  for (c=0 ; c<4 ; c++)
    strcat(rtemp,araRom_single(d[c],pow(10,c)));

  char *out = (char *)malloc(sizeof(char)*(strlen(rtemp)+1)); /* +1 for /0 */
  strcpy(out,rtemp);
  free(rtemp);

  return out;
}


int main()
{
  FILE *file = fopen("roman.txt","r");
  unsigned int array_size = fileLines(file);

  char **in = (char **)malloc(sizeof(char *)*array_size);
  file_parse(file,in);
  fclose(file);
 
  unsigned int saved = 0;	/* num characters saved (output val) */

  /* for (c=0 ; c<array_size ; c++) */
  /*   /\* assumes rewritten num always shorter than original */
  /*      (seems like reasonable assumption to make) *\/ */
  /*   saved += strlen(in[c])-strlen(araRom(romAra(in[c]))); */

  /* printf("Number of character saved by writing each Roman numeral "); */
  /* printf("in minimal form: %d\n",saved); */

  /* SEGFAULTING */
  /* printf("%s\n",araRom(1000)); */
  printf("%s\n",araRom_single(1,1));

  free(in);
  return 0;
}
