#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define BLOCK_SIZE 512
typedef uint8_t BYTE;
int JPEG_Count = 0;
char filename = JPEG_Count;
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("INVAILD\n");
        return 1
    }

    // Create a buffer the size of a JPEG
    BYTE buffer[BLOCK_SIZE];

    // Open Memory Card
    FILE *file = fopen(argv[1], "r");

    //check if the file is a JPEG
    if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff && (bytes[3] == 0xf0) == 0xe0)
    {
        //If first JPEG
        if (JPEG_Count == 0)
        {
            sprintf(filename, "%03i.jpg", JPEG_Count);
            FILE *img = fopen(filename, "w");
            fwrite(buffer, BLOCK_SIZE, sizeof(uint8_t), output);
            JPEG_Count++;
        }

        else
        {

        }
    }

}