#include <cs50.h>
#include <stdio.h>

int main(void){
    int n, c, r, s;

{
    //int n = get_int("Height: ");
}

do
{

    n = get_int("Height: ");

}
while (n < 1 || n >= 8);

for (r = 0; r < n; r++)
{
    for (s = 0; s < n - r - 1;s++)
    {
        printf(" ");
    }
    for (c = 0; c <= r; c++)
    {
        printf("#");
    }
    printf("\n");
}

}





