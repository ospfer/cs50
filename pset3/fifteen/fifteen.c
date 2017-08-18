/**
 * fifteen.c
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
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

//variables
int zRow, zCol, tRow, tCol;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int();
        
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

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
            else
            {
                printf("__ "); //Prints underscore characters in place of a 0, which represents the blank.
            }
        }
        if (board[i][j] != 0)
        {
            printf("%.2i ", board[i][j]);
        }
        else
        {
            printf("__ "); //Prints underscore characters in place of a 0, which represents the blank.
        }
    printf("\n");   
    }
}








bool move(int tile)
{
    int i, j; /*zRow, zCol, tRow, tCol;*/
    
    //find 0
    for (i = 0; i < d; ++i)
    {
        for (j = 0; j < d; ++j)
        {
            if (board[i][j] == 0)
            {
                zRow = i;
                zCol = j;
            }
        }
    }
    
    //find tile
    for (i = 0; i < d; ++i)
    {
        for (j = 0; j < d; ++j)
        {
            if (board[i][j] == tile)
            {
                tRow = i;
                tCol = j;
            }
        }
    }
    printf("0 is in Row: %i and Column: %i.\nTile %i is in Row: %i and Column: %i\n", zRow, zCol, tile, tRow, tCol);
    
    if ((tRow == zRow && tCol == zCol - 1) || //Tile is left of zero
        (tRow == zRow - 1 && tCol == zCol) || //Tile above zero
        (tRow == zRow && tCol == zCol + 1) || //Tile is right of zero
        (tRow == zRow + 1 && tCol == zCol)) //Tile is below zero
    {
        printf("Legal move");
        board[zRow][zCol] = tile;
        board[tRow][tCol] = 0;
        
        return true;
    }
    
    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    int i, j;
    int value = 1;
    int max = (d*d);
    
    //Iterates over the board and checks each value to see if they're in order. Function returns true when all values are in order
    for (i = 0; i < d && value < max; ++i)
    {
        for (j = 0; j < d && value < max; ++j)
        {
            if (board[i][j] != value)
            {
                return false;
            }
            ++value;
        }
    }
    
    return true;
}
