#include <stdio.h>

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */

void init (int d)
{
	int board[d][d];
	int reduce = 0;

	for (int i = 0; i < d; ++i)
	{
		if (i < d - 1)
		{
			for (int j = 0; j < d; ++j)
			{
				board[i][j] = ((d*d) - 1 - reduce);
				printf("%.2i ", board[i][j]);
				++reduce;
			}
		}
		else
		{
			if (d % 2 != 0)
			{
				for (int j = 0; j < d - 1; ++j)
				{
					board[i][j] = ((d*d) - 1 - reduce);
					printf("%.2i ", board[i][j]);
					++reduce;
				}
			}
			else
			{
				for (int j = 0; j < d - 3; ++j)
				{
					board[i][j] = ((d*d) - 1 - reduce);
					printf("%.2i ", board[i][j]);
					++reduce;
				}
				board[i][d-2] = 1;
				board[i][d-3] = 2;
				printf("%.2i %.2i\n", board[i][d-2], board[i][d-3]);
			}
		}
		printf("\n");		

	}
}
int main (void)
{
  init(4);  
}

