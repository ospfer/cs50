/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */

void init (void)
{
	int reduce = 0;

	//Assign values to board[d][d] array.
	for (int i = 0; i < d; ++i)
	{
		if (i < d - 1) //The final row of the array has unique characteristics and must be handled separately.  This conditional allows the loop to assign variables up through the final - 1 row.
		{
			for (int j = 0; j < d; ++j)
			{
				board[i][j] = ((d*d) - 1 - reduce);
				++reduce;
			}
		}
		
		else //Assigns values to the last row of the array
		{
			if (d % 2 == 0) //For the Game of Fifteen, boards that have even dimensions (e.g. 4x4, 6x6, 8x8) must swap the 1 and 2 integers.  If dimensions are odd, assign normally
			{
				for (int j = 0; j < d - 3; ++j)
				{
					board[i][j] = ((d*d) - 1 - reduce);
					++reduce;
				}
				board[i][d-2] = 2;
				board[i][d-3] = 1;
			}
			
			else //Handles the case for even dimensions by swapping the 1 and the 2.
			{
				for (int j = 0; j < d - 1; ++j)
				{
					board[i][j] = ((d*d) - 1 - reduce);
					++reduce;
				}
			}
		}
		printf("\n");		
	}
}



