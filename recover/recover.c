#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define BLOCK_SIZE 512
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("INVAILD\n");
        return 1
    }
    // Create a buffer the size of a JPEG
    buffer[BLOCK_SIZE];
    // Open Memory Card
    FILE *file = fopen(argv[1], "r");

    //check if the file is a JPEG
    if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff)


}