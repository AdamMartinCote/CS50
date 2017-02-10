#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(void)
{
    string s = GetString();
    printf("%c", toupper(s[0])); // Print first lettre in uppercase
    for(int i = 0, n = strlen(s); i < n; i++)
    {
         if(s[i] == ' ')    //search every char of the string for a space
         {
            printf("%c", toupper(s[i+1]));    //print the char right after a space in uppercase
         }
    }
    printf("\n");
}
