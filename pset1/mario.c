# include <stdio.h>
# include <cs50.h>

int main()
{
    int h = 0; //sets height variable
    do
    {
        printf("height: ");
        //scanf("%d", &h);
        h = GetInt();
    }
    while(h > 23 || h < 0); //repete if bigger than 23 or smaller than 1
  
    int space = h - 1;// initialize variables for the first row
    int hash = 2;
    
    while (space >= 0)// print lines until you make one with 0 spaces
    
    {
        int a = space; // print a space 'space' times
        while (a > 0)
            {
                printf(" ");
                a--;
            }
        int b = hash; // print a hash 'hash' times
        while (b > 0)
            {
                printf("#");
                b--;
            }
        printf("\n"); //go to next line
        space--; // next line will have one less space and one more hash
        hash++;
    }
    
    return 0;   
}

   
