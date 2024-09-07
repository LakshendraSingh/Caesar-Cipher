#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{

    if (argc == 2)
    {
        for (int i = 0, len = strlen(argv[1]); i < len; i++)
        {
            if (isdigit(argv[1][i]))
            {
            }
            else
            {
                printf("Usage ./caesar key\n");
                return 1;
            }
        }
    }
    else
    {
        printf("Usage ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);
    // ci = (pi + key) % 26
    string pt = get_string("plaintext:  ");
    printf("ciphertext: ");
    for (int i = 0, length = strlen(pt); i < length; i++)
    {
        if (islower(pt[i]))
        {
            char cil = (((int) pt[i] - 'a' + key) % 26) + 'a';
            printf("%c", cil);
        }
        else if (isupper(pt[i]))
        {
            char ciu = (((int) pt[i] - 'A' + key) % 26) + 'A';
            printf("%c", ciu);
        }
        else
        {
            printf("%c", pt[i]);
        }
    }
    printf("\n");
}
