#include <stdio.h>
//#include <cs50.h>
#include <math.h>

int main(void)
{
    //Declare variables
    float change;
    int count;
    float quarter = 25;
    float dime = 10;
    float nickle = 05;
    float penny = 01;
    
    //Ask the user for how much change is to be given, assuming a non-negative number
    do
    {
        printf("How much change? ");
        scanf("%f", &change);
        //change = GetFloat(); Commented out from cs50.
    }
    while (change <= 0);
    
    //Convert change to cents
    int cents = (int)round(change*100);
    
    /*
    The for loop keeps a running sum of the amount of coins needed to reduce the balance 
    owed to 0
    
    Inside the for loop, check to see if change balance exceeds avaialbe coins in decending
    order from greatest to least denomination
    */
    
    for (count = 0; cents > 0; count ++)
    {
        if (cents >= quarter)
            cents -= quarter;
        
        else if (cents >= dime)
            cents -= dime;
            
        else if (cents >= nickle)
            cents -= nickle;
            
        else
            cents -= penny;
    }
    //Print the minimum amount of coins required to make the change.
    printf("%i\n", count);
}
