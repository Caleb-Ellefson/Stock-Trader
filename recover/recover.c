#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //one command-line argument
    if (argc =! 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

 // Open the memory card
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("File could not be opened.\n");
        return 1;
    }
    BYTE buffer[BLOCK_SIZE];

    while (fread(buffer, 1, BLOCK_SIZE, raw_file) == BLOCK_SIZE)
 // Repeat until end of card
    //Read 512 bytes into buffer
    // If start of new JPEG
        //If first JPEG
        //Else close old and open new file
    //Else
        //If already found a JPEG

}