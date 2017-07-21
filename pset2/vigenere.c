#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //check for only 2 command line arguments
    if (argc != 2)
    {
        printf("Enter one argument only\n");
        return 1;
    }
    
    //check for only alphabetical characters in argument
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (isalpha(argv[1][i]))
        {
            //printf("%c", argv[1][i]);
            continue;
        }
        else
        {
            printf("Argument must have alphabetical characters only\n");
            return 1;
        }
    }
    //request plaintext user input
    printf("plaintext: ");
    string plain = get_string();
    printf("ciphertext: ");

    for (int i = 0, j = 0, n = strlen(plain), m = strlen(argv[1]); i < n; i++)
    {
        if (!isalpha(plain[i]))
        {
            printf("%c", plain[i]);
        }
        
        else if (islower(plain[i]))
        {
            int key = j % m;
            int shift = toupper(argv[1][key]) - 65;
            int cipher = ((((plain[i] + shift) - 97) % 26) + 97);
            printf("%c", cipher);
            j++;
        }
        
        else
        {
            int key = j % m;
            int shift = toupper(argv[1][key]) - 65;
            int cipher = ((((plain[i] + shift) - 65) % 26) + 65);
            printf("%c", cipher);
            j++;
        }
    }
    printf("\n");
    return 0;
}
    
