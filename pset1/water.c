#include <stdio.h>
//#include <cs50.h>

int main(void)
{
    int minutes;
    
    printf("Minutes: ");
    scanf("%i", &minutes);
    //minutes = GetInt();
    
    printf("Bottles: %i\n", minutes * 12);
    
    return 0;
}