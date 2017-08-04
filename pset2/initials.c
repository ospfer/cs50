#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    // ask the user for a string
    string s = GetString();
    // prints the first character in upper case
    printf("%c", toupper(s[0]));
    // iterates over all characters of the string
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // when the character is a space, print the i'th plus 1 character
        if (s[i] == ' ')
        {
            printf("%c", toupper(s[i+1]));
        }
    }
    printf("\n");
}