#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])

{
    if (argc != 2) // can't enter anything but ./caesar key
    {
        printf("Usage: ./caesar key\n");

        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)

    {
        if (!isdigit(argv[1][i])) // checks if the key is a digit or not
        {
            printf("Usage: ./caesar key\n");

            return 1;
        }
    }

    string key = argv[1];

    int k = atoi(key); // turning string key to an int

    string plaintext = get_string("plaintext:");

    printf("ciphertext:");

    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isupper(plaintext[i]))
        {
            printf("%c", ((((plaintext[i] - 65) + k) % 26) +
                          65)); // shifting as the fourmeula with the help of ASCII table and keeping the upper case
        }

        else if (islower(plaintext[i]))
        {
            printf("%c", ((((plaintext[i] - 97) + k) % 26) + 97)); // same thing but for lower cases
        }

        else
        {
            printf("%c", plaintext[i]); // printing everything without changes
        }
    }
    printf("\n");
}
