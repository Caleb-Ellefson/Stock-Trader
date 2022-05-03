#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int total_sum = 0, pos = 0;
    long card_number;
    do
        {
        card_number = get_long("Enter your card number here  ");
        }
    while (card_number != 0)

        if (pos % 2 != 0)

// checksum multiply every other digit by 2 starting with the second to last digit

    // 1234
    //sum of 1 + 3
    //1234 % 10 => 4, pos = 0
    //123 % 10 => 3, pos = 1 => odd
    //12 % 10 => 2, pos = 2 => even
    //1 % 10 => 1, pos = 3 => odd

// then add the products of the digits togther

//add the sum of that to the sum of the digits that were not multiplied if the total's last digit = 0 card = vaild


// American Express 15 digits begins with 34 and 37

// MasterCard 16 digits starts with 51,52,53,54 or 55

// Visa 13 or 16 digits starts with the number 4



















}