#include <stdio.h>
//#include <cs50.h>

int main(void) 
{
	// Declare and intialize variables
	int height;
	
	// Grab user input, check it and ask for retry if not within bounds  
	do 
	{
		printf("Height: ");
		scanf("%i", &height);
		//height = GetInt();
    } 
    while (height < 1 || height > 23);

	/*
		The outer loop handles the count of rows to print.
		The inner loops are responsible for printing the correct number of 
		spaces and hashes. The first of the two inner loop handles spaces
        It takes the value of the loop counter form the outer loop
		plus 2 as border value since we starting the pyramid with 2 blocks;
	*/ 
	for(int i = 0; i < height; i++) 
	{
		// Print the required spaces
        for(int space1 = 0; space1 < height-i-1; space1++)
        {
            printf("%s", " ");
        }
        // Print the '#' character.
		for(int hash1 = 0; hash1 < i+2; hash1++)
		{
			printf("#");
		}
		//print the double space between the two pyramids
		
		printf("  ");
		
		//print the hashes for the right side of the pyramid
		for(int hash2 = 0; hash2 < i+2; hash2++)
		{
		    printf("#");
		}
		//print spaces on the right side
		for(int space2 = 0; space2 < height-i-1; space2++)
		{
		    printf("%s", " ");
		}
		printf("\n");
	}	
	return 0;
}