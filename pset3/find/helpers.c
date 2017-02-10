/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int middle = low + (high-1)/2;
        
        if (values[middle] == value) 
            return true;
        if (values[middle] < value) 
            low = middle + 1;
        else high = middle - 1;    
    }
    return false;
}
/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // bubble sort; taken from http://www.cprogramming.com/tutorial/computersciencetheory/sorting1.html
    // and adapted
    for (int i = 0; i < n; i++)
    {
        for(int y=0; y < n-1; y++)
        {
            if(values[y] > values[y + 1])
            {
                int tmp = values[y + 1];
                *(values + y + 1) = values[y];
                *(values + y) = tmp;             
            }
        }
    }
    return;
}
