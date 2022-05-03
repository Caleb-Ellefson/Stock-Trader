#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int total_sum = 0, pos = 0, total_length = 0;
    long card_number;
    long card_copy;
    do
    {
        card_number = get_long("Enter your card number here  ");
        card_copy = card_number;

        while (card_number != 0)
        {
            if (pos % 2 != 0)
            {
                int temp = 2 * (card_number % 10);
                if (temp > 9)
                {
                    total_sum += (temp % 10 + temp / 10);
                }
                else
                {
                    total_sum += temp;
                }
            }
            else
            {
                total_sum += card_number % 10;
            }
            card_number = card_number / 10;
            pos++;
            total_length++;
        }
    }
    while (card_number != 0);

    if (total_sum % 10 == 0)
    {
        // MasterCard 16 digits starts with 51,52,53,54 or 55
        long master_start = card_copy / 10000000000000;
        if ((total_length == 16) && (master_start >= 51 && master_start <= 55))
        {
            printf("MASTERCARD\n");
            return 0;
        }
        // American Express 15 digits begins with 34 and 37
        long amex_start = card_copy / 1000000000000;
        if ((amex_start == 34 || amex_start == 37) && total_length == 15)
        {
            printf("AMEX\n");
            return 0;
        }
        // Visa 13 or 16 digits starts with the number 4
        long visa_start = card_copy / 10000000000000;
        if ((total_length == 13 || total_length == 16) && (visa_start == 4 || master_start / 10 == 4))
        {
            printf("VISA\n");
            return 0;
        }
    }
    else
    {
        printf("INVAILD\n");
    }

}