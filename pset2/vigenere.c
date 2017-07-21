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
    
    //check for only alphabetical characters in command line argument
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (isalpha(argv[1][i]))
        {
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

    //encipher plaintext with key
    for (int i = 0, j = 0, n = strlen(plain), m = strlen(argv[1]); i < n; i++)
    {
        //if text in plain is not an alpha, print the character and move on
        if (!isalpha(plain[i]))
        {
            printf("%c", plain[i]);
        }
        
        //if text in plain is lowercase, encipher with key and retain case
        else if (islower(plain[i]))
        {
            int key = j % m; //identifies location in argv[1] array to use for key enciphering
            int shift = toupper(argv[1][key]) - 65; //generates number to shift for key. toupper function allows upper or lower case keytext to be treated as same alphabetical index
            int cipher = ((((plain[i] + shift) - 97) % 26) + 97); //encipher plaintext with character from key array. Retains lower case
            printf("%c", cipher); //prints the enciphered character
            j++; //advances to next character in key
        }
        
        else
        {
            int key = j % m; //identifies location in argv[1] array to use for key enciphering
            int shift = toupper(argv[1][key]) - 65; //generates number to shift for key. toupper function allows upper or lower case keytext to be treated as same alphabetical index
            int cipher = ((((plain[i] + shift) - 65) % 26) + 65); //encipher plaintext with character from key array. Retains upper case
            printf("%c", cipher); //prints the enciphered character
            j++; //advances to next character in key
        }
    }
    printf("\n"); 
    return 0; //exit cleanly
}
    
