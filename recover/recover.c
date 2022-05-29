#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define BLOCK_SIZE 512
typedef uint8_t BYTE;
int JPEG_Count = 0;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("INVAILD\n");
        return 1;
    }
