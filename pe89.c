#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* returns num of lines in given file */
unsigned int fileLines(FILE *file)
{
  char c;
  unsigned int lines = 0;

  while ((c=fgetc(file))!=EOF)
    if (c=='\n')
      lines++;

  return lines;
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


/* converts arabic num to roman */
/* assumes num representable by no higher than M */
char *araRom(unsigned int n)
{
  unsigned int c = 0;		/* counter */
  char *rtemp = (char *)malloc(sizeof(char)*100); /* roman num holder */
  rtemp[0] = '\0';				  /* to be appended onto */

  /* TODO */

  char *out = (char *)malloc(sizeof(char)*(strlen(rtemp)+1)); /* +1 for /0 */
  strcpy(out,rtemp);
  free(rtemp);

  return out;
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


int main()
{
  FILE *file = fopen("roman.txt","r");
  unsigned int array_size = fileLines(file);

  rewind(file);
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

  free(in);
  return 0;
}
