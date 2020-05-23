#include<stdio.h>
#include<cs50.h>
#include<math.h>

int main(void)
{
    long int card = get_long("Input : ");
    long int n = 1, sum = 0, temp = 0, temp2 = 0, ksum = 0, fdigit, copy, copy1;
    copy = card;
    copy1 = card;
    // Takes every digit of the card number
    while (card >= 1)
    {
        temp = card % 10;
        if (n % 2 == 0)
        {
            // Multiplying of alternate digits by 2 and if becomes two digit number breaking it in single digits again
            temp = temp * 2;
            if ((temp / 10) >= 1)
            {
                ksum = 0;
                while (temp >= 1)
                {
                    temp2 = temp % 10;
                    ksum = ksum + temp2;
                    temp = temp / 10;
                }
                temp = ksum;
            }
        }
        // addition of digits
        sum = sum + temp;
        card = card / 10;
        n++;
    }
    n = n - 1;
    // checking for unit digit of sum
    fdigit = sum % 10;
    // verification of card by it's starting digits and its length
    if (fdigit == 0 && (n == 13 || n == 15 || n == 16))
    {
        // Checks for last two digit number
        while (copy >= 100)
        {
            copy = copy / 10;
        }
        // Checks for last one digit number
        while (copy1 >= 10)
        {
            copy1 = copy1 / 10;
        }
        if (copy1 == 4 && (n == 13 || n == 16))
        {
            printf("VISA\n");
        }
        else if ((copy == 34 || copy == 37) && n == 15)
        {
            printf("AMEX\n");
        }
        else if ((copy == 51 || copy == 52 || copy == 53 || copy == 54 || copy == 55) && n == 16)
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
        printf("INVALID\n");
    }
}
