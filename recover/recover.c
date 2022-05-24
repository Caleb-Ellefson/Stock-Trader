#include <stdio.h>
#include <stdlib.h>
BLOCK_SIZE == 512

int main(int argc, char *argv[])
{
    //one command-line argument
    if (argc =! 1)
    {
        printf("Invaild");
        return 1;
    }

 // Open the memory card
    FILE *file = fopen(argv[1], "r");
    if (file != NULL)
    {
        printf()
    }
 // Repeat until end of card
    //Read 512 bytes into buffer
    // If start of new JPEG
        //If first JPEG
        //Else close old and open new file
    //Else
        //If already found a JPEG

}