#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define BLOCK_SIZE 512
typedef uint8_t BYTE;

int inputError()
{
    printf("Usage: ./recover IMAGE\n");
    return 1;
}
int fileError (char filename[])
{
    printf("Unable to open file: %s\n", inputFile);
    return 1;
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
        return fileError;
    }

    return 0;
}