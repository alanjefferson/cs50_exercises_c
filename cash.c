#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    /*Getting users change owed*/ 
    float dollars;
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars <= 0);

    /*Keeping track of remaining change owed*/
    int change = round(dollars * 100);
    
    /*keep track of how many coins used*/
    int coins = 0;

    /*Add Quarters Coins to Total Coins*/
    int remainchangeq = change % 25;
    int quarters = change - remainchangeq;
    int quarterCoins = quarters / 25;
    change = change - quarters;
    coins = coins + quarterCoins;

    /*Add Dimes Coins to Total Coins*/
    int remainchanged = change % 10;
    int dimes = change - remainchanged;
    int dimeCoins = dimes / 10;
    change = change - dimes;
    coins = coins + dimeCoins;

    /*Add Nickels Coins to Total Coins*/
    int remainchangen = change % 5;
    int nickels = change - remainchangen;
    int nickelCoins = nickels / 5;
    change = change - nickels;
    coins = coins + nickelCoins;

    /*Add Pennies Coins to Total Coins*/
    int penniesCoins = change;
    coins = coins + penniesCoins;
    printf("%i\n", coins);
}