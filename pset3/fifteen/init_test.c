#define _XOPEN_SOURCE 500

//#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
//bool move(int tile);
//bool move_operation(int tile, int tile_row, int tile_col, int adj_tile_row, int adj_tile_col);
//bool won(void);

#include <stdio.h>

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */

int d = 4;
//int board;

void init (void)
{
	//int board[d][d];
	int reduce = 0;

	//Assign values to board[d][d] array.
	for (int i = 0; i < d; ++i)
	{
		if (i < d - 1) //The final row of the array has unique characteristics and must be handled separately.  This conditional allows the loop to assign variables up through the final - 1 row.
		{
			for (int j = 0; j < d; ++j)
			{
				board[i][j] = ((d*d) - 1 - reduce);
				printf("%.2i ", board[i][j]);
				++reduce;
			}
		}
		else //Assigns values to the last row of the array
		{
			if (d % 2 != 0) //For the Game of Fifteen, boards that have even dimensions (e.g. 4x4, 6x6, 8x8) must swap the 1 and 2 integers.  If dimensions are odd, assign normally
			{
				for (int j = 0; j < d - 1; ++j)
				{
					board[i][j] = ((d*d) - 1 - reduce);
					printf("%.2i ", board[i][j]);
					++reduce;
				}
			}
			else //Handles the case for even dimensions by swapping the 1 and the 2.
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
	void init (void);
	//int d = 4;
  	//int board[d][d];
  	init();

}

