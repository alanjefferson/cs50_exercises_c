#include <cs50.h>
#include <stdio.h>

void printfirstspace(int totLn, int currLne);
void printlefthash(int currLne);
void printrightthash(int currLne);

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
        printfirstspace(n, i);
        printlefthash(i);
        printf("  ");
        printrightthash(i);
        printf("\n");
    }    
}

/*Function to print the first spaces*/
void printfirstspace(int totLn, int currLne)
{
    for (int d = 0; d < totLn - (currLne + 1); d++)
    {
        printf(" ");
    }
}

/*Function to print left hashes*/
void printlefthash(int currLne)
{
    for (int h = 0; h < currLne + 1; h++)
    {
        printf("#");
    }
}

/*Function to print left hashes*/
void printrightthash(int currLne)
{
    for (int h = 0; h < currLne + 1; h++)
    {
        printf("#");
    }
}
