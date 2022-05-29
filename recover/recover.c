#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define BLOCKSIZE 512
typedef uint8_t BYTE;

int inputError()
{
    printf("Usage: ./recover IMAGE\n");
    return 1;
}
int fileError (char filename[])
{
    printf("Unable to open file: %s\n", filename);
    return 1;
}
bool isJpegHeader(BYTE buffer[])
{
    return bytes[0] == 0xff
        && bytes[1] == 0xd8
        && bytes[2] == 0xff
        && (buffer[3] & 0xf0) == 0xe0;
}
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        return inputError();
    }

    char* inputFile = argv[1];
    if(inputFile == NULL)
    {
        return inputError();
    }

    FILE* inputPtr = fopen(inputFile, "r");
    if (inputPtr == NULL)
    {
        return fileError(inputFile);
    }

    char filename[8];
    FILE* outputPtr = NULL;
    BYTE buffer[BLOCKSIZE];
    int jpgCounter = 0;

    while(fread(buffer, sizeof(BYTE), BLOCKSIZE, inputPtr) || feof(inputPtr) == 0)
    {
        if(isJpgHeader(buffer))
        {
            if(outputPtr == NULL)
            {
                fclose(outputPtr);
            }
            sprintf(filename, "%03i.jpg", jpgCounter);
            outputPtr = fopen(filename, "w");
            jpgCounter++;
        }
        if(outputPtr!= NULL)
        {
            fwrite(buffer, sizeof(BYTE), )
        }

    }

    return 0;
}