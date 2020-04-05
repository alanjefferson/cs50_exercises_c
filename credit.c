#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long cardnum;
    long creditcardnum;
    do
    {
        creditcardnum = get_long("Number: ");
    }
    while (creditcardnum <= 0);

    cardnum = creditcardnum;

    int lastdig = 0;
    bool ohterdigit = false;
    int firstsum = 0;
    int secondsum = 0;
    int numbersize = 0;

    do
    {
        //printf("cardnum: %ld\n", cardnum);
        /*Get credit card number last digit*/
        lastdig = cardnum % 10;
        //printf("lastdig: %i\n", lastdig);

        /*If the digit position is "other digit" (counting from the last to the first), */
        int digitprod = lastdig * 2;
        
        if (ohterdigit)
        {
            //printf("digitprod: %i\n", digitprod);
            /*Before sum, verify if the number is bigger than 1 digit.*/
            /*If true, it is necessary to sum each digit. Example: 12 -> 1 + 2*/
            if (digitprod >= 10)
            {
                int digprodsum = 0; /*Final digits sum*/
                int lastdigitprod = 0; 
                int qtddigtprod = digitprod;
                do
                {
                    //printf("Complete number: %i\n", qtddigtprod);
                    lastdigitprod = qtddigtprod % 10;
                    digprodsum = digprodsum + lastdigitprod;
                    //printf("Soma: %i\n", digprodsum);
                    //printf("Last digit: %i\n", lastdigitprod);
                    qtddigtprod = qtddigtprod / 10;
                }
                while ((lastdigitprod != qtddigtprod) && qtddigtprod > 0);
                /*Add the sum of the product*/
                digitprod = digprodsum;
                //printf("digitprod: %i\n", digitprod);
                //printf("\n");
            }

            firstsum = firstsum + digitprod;
            //printf("firstsum: %i\n", firstsum);
        }
        else
        {
            secondsum = secondsum + lastdig;
            //printf("secondsum: %i\n", secondsum);
        }

        ohterdigit = !ohterdigit;

        /*Update credit card number without last digit*/
        cardnum = cardnum / 10;
        //printf("cardnum: %ld\n", cardnum);
        //printf("lastdig: %i\n", lastdig);
        //printf("\n");
        numbersize = numbersize + 1;
    }
    //while (cardnum != lastdig);
    //while (cardnum > 10 || (cardnum < 10 && lastdig > 0));
    while (cardnum > 0);
    
    /*Sum total*/
    int total = firstsum + secondsum;
    //printf("firstsum: %i\n", firstsum);
    //printf("secondsum: %i\n", secondsum);
    //printf("Total: %i\n", total);

    /*Total Last Digit*/
    int totallastdigt = total % 10;
    //printf("Total Last Digit: %i\n", totallastdigt);

    if (totallastdigt == 0)
    {
        //Verify the size of the credit card number.
        //printf("Credit card number size: %i\n", numbersize);
        if (numbersize >= 13 && numbersize <= 16)
        {
            //American Express numbers start with 34 or 37 and uses 15-digit numbers.
            if (numbersize == 15)
            {
                int firstdigits = creditcardnum / 10000000000000;
                //printf("Fisrts AMEX card digits: %i\n", firstdigits);
                if (firstdigits == 34 || firstdigits == 37)
                {
                    printf("AMEX\n");
                }
                else
                {
                    printf("INVALID\n");
                }
                
            }
            else
            {
                if (numbersize == 16)
                {
                    //Visa numbers start with 4 and uses 13- and 16-digit numbers.
                    int firstdigit = creditcardnum / 1000000000000000;
                    //MasterCard numbers start with 51, 52, 53, 54, or 55 and uses 16-digit numbers.
                    int firstdigits = creditcardnum / 100000000000000;
                    
                    if (firstdigit == 4)
                    {
                        printf("VISA\n");
                    }
                    else if (firstdigits >= 51 && firstdigits <= 55)
                    {
                        printf("MASTERCARD\n");
                    }
                    else
                    {
                        printf("INVALID\n");
                    }
                }
                else
                {
                    //Visa numbers start with 4 and uses 13- and 16-digit numbers.
                    int firstdigit = creditcardnum / 1000000000000000;
                    if (firstdigit == 4)
                    {
                        printf("VISA\n");
                    }
                    else
                    {
                        printf("INVALID\n");
                    }                    
                }
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}