#include <stdio.h>

int main()
{
  unsigned int row;
  unsigned int col;

  /* grid initialization */
  int grid[20][20];
  for (row=0 ; row<20 ; row++)
    for (col=0; col<20 ; col++)
      col==19 ? scanf("%d\n", &grid[row][col]) : scanf("%d ", &grid[row][col]);

  unsigned long long int prod;
  unsigned long long int maxprod = 0;

  for (row=0 ; row<20 ; row++)
    for (col=0; col<20 ; col++) {
      /* horizontal product */
      if (col<17) {
  	prod = grid[row][col]
	       * grid[row][col+1]
	       * grid[row][col+2]
	       * grid[row][col+3];
	if (prod>=maxprod)
	  maxprod = prod;
      }

      /* vertical product */
      if (row<17) {
  	prod = grid[row][col]
	       * grid[row+1][col]
	       * grid[row+2][col]
	       * grid[row+3][col];
	if (prod>=maxprod)
	  maxprod = prod;
      }

      /* diagonal product, down-left-right */
      if (col<17 && row<17) {
  	prod = grid[row][col]
	       * grid[row+1][col+1]
	       * grid[row+2][col+2]
	       * grid[row+3][col+3];
	if (prod>=maxprod)
	  maxprod = prod;
      }
    
      /* diagonal product, down-right-left */
      if (col>2 && row<17) {
  	prod = grid[row][col]
	       * grid[row+1][col-1]
	       * grid[row+2][col-2]
	       * grid[row+3][col-3];
	if (prod>=maxprod)
	  maxprod = prod;
      }
    }
  
  printf("%lu\n",maxprod);
  return 0;
}
