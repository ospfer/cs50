/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

//Returns true if value is in array of n values, else false.
// O(log (n)) searching algorithm
bool search(int value, int values[], int n)
{
	int lowerBound = 0;
	int upperBound = n;
	
	do
	{
		if (upperBound < lowerBound)
		{
			return false;
		}
		
		int midPoint = lowerBound + (upperBound - lowerBound) / 2;
		
		if (values[midPoint] < value)
		{
			lowerBound = midPoint + 1;
		}
		
		if (values[midPoint] > value)
		{
			upperBound = midPoint - 1;
		}
		
		if (values[midPoint] == value)
		{
			return true;
		}
	} while (true);
}



//Returns true if value is in array of n values, else false.
// O(n) search algorithm
/*
bool search(int value, int values[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        if (values[i] == value)
        {
            return true;
        }
    }
    return false;
}
*/




//Sorts array of n values.
void sort(int values[], int n)
{
    // O(n^2) sorting algorithm
    int i, j, temp;

	for (i = 0; i < n-1; ++i)
	{
		for (j = i + 1; j < n; ++j)
		{
			if (values[i] > values[j])
			{
				temp = values[i];
				values[i] = values[j];
				values[j] = temp;
			}
		}
	}
	return;
}
    

