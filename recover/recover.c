#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define BLOCK_SIZE 512
typedef uint8_t BYTE;
int JPEG_Count = 0;
char *filename = "000.jpg";
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
            fwrite(buffer, BLOCK_SIZE, sizeof(uint8_t), img);
            JPEG_Count++;
        }

        else
        {
            JPEG_Count++;
            // Close file
            fclose(filename);
            //create new filename
            sprintf(filename, "%03i.jpg", JPEG_Count);

            // open new file
            FILE *img = fopen(filename, "w");

            // write to new file
            fwrite(buffer, BLOCK_SIZE, sizeof(uint8_t), img);
        }
    }
    else
    {
        //if already found JPEG
        //Read 512 check??
    }
    // close remaing files

}