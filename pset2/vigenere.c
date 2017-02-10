#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>

int main (int argc, string argv[])
{   
/****************************************************************
***********this block verify for the proper argument************/

    if(argc != 2 || argv[1] == NULL)        // abort if not exactly 1 argument
    {
        printf("\a");
        return 1;
    }
    int keylen = strlen (argv[1]);          //declare variable for the length of argv[1]
    
    int key[50] = {0};
    
    
    for (int i = 0; i < keylen; i++)
    {
        if (isalpha(argv[1][i]))
        {
            key[i] = (toupper(argv[1][i]) - 65 );
        }
        else 
        {
            printf("\a");
            return 1;
        }
    }

    
/****************************************************************
*********************** modified caesar ************************/

    string plain = GetString();
    
    for (int i = 0,j = 0, n = strlen(plain); i < n; i++)  //interate for each char  
    {
            if (isalpha(plain[i]) == false)    
                {
                    printf("%c", plain[i]);
                }
            else if islower(plain[i])
            {
                char enc = (((plain[i] - 97) + (key[j % keylen])) % 26) + 97;
                printf("%c", enc);
                j++;
            }
            else if isupper(plain[i])
            {
                char enc = (((plain[i] - 65) + (key[j % keylen])) % 26) + 65;
                printf("%c", enc);
                j++;
            }
    }
    printf("\n");
    return 0;   
}


