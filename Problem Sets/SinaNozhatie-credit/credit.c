#include <cs50.h>
#include <stdio.h>

bool validity(long number);
bool checksum(long number);
int find_lenth(long number);
void choose_bank(long number);

int main(void)
{
    long number;
    do
    {
        number = get_long("Enter Card Number:");

    }
    while (number < 0); // Card number must be Greater than 0

    if (validity(number) == true) //checks validity of card
    {

        choose_bank(number); //Printing the bank name if it was valid

    }
    else
    {
        printf("INVALID\n");
    }
}

bool validity(long number)
{
    int lenth = find_lenth(number); //check the lenth

    if ((lenth == 13 || lenth == 15 || lenth == 16) && (checksum(number) == true))
    {
        return true;
    }
    else
    {
        return false;
    }


}

int find_lenth(long number)
{
    int lenth = 0;

    while (number != 0) //this loop remove the last digit untill the number reach to 0
    {
        lenth++;
        number /= 10; //remove the last Digit
    }
    return lenth;

}

bool checksum(long number)
{
    int sum1 = 0, sum2 = 0, sum;
    int i = 0;

    while (number != 0)
    {
        if (i % 2 != 0) //if it's the second last digit
        {   
            
            int n = (2 * (number % 10)); // multiply the last digit by 2
            

            if (n > 9)
            {  
                sum1 += n % 10 + n / 10;  //if the number was 12 do 1 + 2
            }
            else
            {
                sum1 += n;
                            

            }

        }
        else
        {
            sum2 += number % 10;
        }
        number /= 10;//remove the last Digit
        i++;
    }

    sum = sum1 + sum2; //sum of digits must = 20
        
    if (sum % 10 == 0)// the last digit must = 0
    {
        return true;
    }
    else
    {
        return false;
    }
}

void choose_bank(long number)
{


    if (number / 10000000000000 == 34 || number / 10000000000000 == 37) //if the first 2 digits is 34 or 37
    {
        printf("AMEX\n");
    }

    else if (number / 100000000000000  == 51 || number / 100000000000000  == 52 || number / 100000000000000  == 53
             || number / 100000000000000  == 54 || number / 100000000000000  == 55)
    {
        printf("MASTERCARD\n");
    }

    else if (number / 1000000000000  == 4 || number / 1000000000000000 == 4) //if the first digit is 4
    {
        printf("VISA\n");
    }
    
    else
    {
        printf("INVALID\n");
    }

}

