#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <cs50.h>
#include <stdlib.h>

int main (int argc, string argv[])
{
    if(argc == 2)// run only if 1 arg provided
    {
        
        int k = atoi(argv[1]); //converts the argument to an int
        printf("Enter the code to be encrypted:\n");
        string s = GetString();
        
        for (int i = 0, n = strlen(s); i < n; i++)  //interate for each char
        
        {
        
            if(s[i] >= 'a' || s[i] <= 'z')  //lowercase
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
            else if(s[i] >= 'A' || s[i] <= 'Z')     // if uppercase
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
    else return 1;
}
    
      
      /*
            
            
            
            
            if ((s[i] + k) >= 'z' )    
        }
    }
    else return 1;
}
    
    {
    printf("Please enter a text for encryption: ");
    string s = GetString(); // get a string to encrypt
      
    for(int i = 0, n = strlen(s); i < n; i++)   //iterate for each character of the user's string
    {
        if(s[i] >= 'a' && s[i] <= 'z')   // if a-z, add k
        {
            printf("%c", (s[i]+k);)
            if (e[i] > 'z')
            {
                e[i] -= 26;
            }
            printf("%c", e[i]);
            
        }
        //printf("%c", (s[i]+((int)argv[1])));  //
    }
    printf("\n");
    return 0;
    }
    else return 1;
} */

