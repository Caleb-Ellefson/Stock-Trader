#include <cs50.h>
#include <stdio.h>

int main(void) {
int n, c, r;

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
    for (c = 0; c > n; c++)
    {
        printf("#");
    }
    printf("\n");
}

}





