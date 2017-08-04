#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //check to make sure there are only two arguments - the filename and the key
    if (argc != 2)
    {
        printf("Enter one command line argument\n");
        return 1;
    }
    
    //Turn key into integer
    
    int k = atoi(argv[1]);
    //printf("%i", k);

    //Prompt user for plaintext
    printf("plaintext: ");
    string text = get_string();
    printf("ciphertext: ");
    //iterate over plaintext
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //check to make sure the characters entered are alphas
        if (isalpha(text[i]))
        {
            //if the character is lowercase, keep case
            if (islower(text[i]))
            {
                int cipher = ((((text[i] - 97) + k) % 26) + 97);
                printf("%c", cipher);
            }
            //if the character is uppercase, keep case
            if (isupper(text[i]))
            {
                int cipher = ((((text[i] - 65) + k) % 26) + 65);
                printf("%c", cipher);
            }
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
    return 0;
}