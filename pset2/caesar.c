#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>

int main (int argc, string argv[])
{
    if(argc != 2 || argv[1] == NULL)// run only if 1 arg provided
    {
        printf("\a");
        return 1;
    }
        
        int k = atoi(argv[1]); //converts the argument to an int
        k %= 26;    //convert the key to <=26
        string s = GetString();
        
        for (int i = 0, n = strlen(s); i < n; i++)  //interate for each char
        
        {
            if islower(s[i])
            {
                if((s[i] + k ) > 'z')   // if the letter +k goes beyond z
                {
                    printf("%c", (s[i] + k - 26));  // print char + k - 26
                }
                else 
                {
                    printf("%c", (s[i] + k));  // else print the char +k
                }
            }
            else if isupper(s[i])
                {
                    if((s[i] + k) > 'Z')
                    {
                        printf("%c", (s[i] + k - 26));
                    }
                    else 
                    {
                        printf("%c", (s[i] + k));
                    }
                }
            else   
            {
                printf("%c", s[i]);
            }
        }
    printf("\n");
    return 0;   
}

