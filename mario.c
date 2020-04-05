#include <cs50.h>
#include <stdio.h>

void printdot(int totLn, int currLne);
void printhash(int currLne);

int main(void)
{
    /*Getting from user the height*/ 
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    /*Call funcitons to print dots, hashes and lines.*/
    for (int i = 0; i < n; i++)
    {
        printdot(n, i);
        printhash(i);
        printf("\n");
    }
}

/*Function to print dots*/
void printdot(int totLn, int currLne)
{
    for (int d = 0; d < totLn - (currLne + 1); d++)
    {
        printf(" ");
    }
}

/*Function to print hashes*/
void printhash(int currLne)
{
    for (int h = 0; h < currLne + 1; h++)
    {
        printf("#");
    }
}