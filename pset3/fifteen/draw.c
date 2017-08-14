/**
 * Prints the board in its current state.
 */

void draw(void)

{
	int i, j;

	for (i = 0; i < d; ++i)
	{
		for (j = 0; j < d - 1; ++j)
		{
			if (board[i][j] != 0)
			{
			    printf("%.2i ", board[i][j]);
			    
			}
		}
		if (board[i][j] != 0)
		{
		    printf("%.2i ", board[i][j]);
		}
	printf("\n");	
	}
}