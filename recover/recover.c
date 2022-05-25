#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

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
    size_t bytes_read;

    while (true)
    {
        // Repeat until end of card
        //Read 512 bytes into buffer
        bytes_read = fread(buffer, sizeof(BYTE), BLOCK_SIZE, file);
        if (bytes_read == 0)
        {
            break; // end of file
        }
        // If start of new JPEG
        if ()


    }
 // Repeat until end of card
    //Read 512 bytes into buffer
    // If start of new JPEG
        //If first JPEG
        //Else close old and open new file
    //Else
        //If already found a JPEG

}