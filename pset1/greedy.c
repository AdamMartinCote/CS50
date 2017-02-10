#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>


int main(int argc, string argv[])
{
    float f = 0;
    if (argc < 2)
        {
            string = argv[1];
        }
    else {return 1;}
    while (f < 0)//request again if negative
    {
    printf("O hai! How much change is owed?\n");
    f = GetFloat();//requesting a float value
    }
    int n = 0; //variable for number of pieces
    f = f * 100; // convert to cents and then round
    int cents = round(f);

    while (cents >= 25)// minus one quarter while you can...
        {
            cents = cents - 25;
            n++;// number of pieces up by one count
        }
    while (cents >= 10)//so on...
        {
            cents = cents - 10;
            n++;
        }
    while (cents >= 5)
        {
            cents = cents - 5;
            n++;
        }
    while (cents >= 1)
        {
            cents = cents - 1;
            n++;
        }
        printf("%d\n", n);
    
}
