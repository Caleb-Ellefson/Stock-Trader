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
    bool is_first_jpeg = false;
    FILE *current_file;
    char filename[100];
    int current_filenumber = 0;
    bool found_jpeg = false;

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
        if ((buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] && 0xf0 == 0xe0))
        {
            found_jpeg = true;
            //if first JPEG
            //MARK IT
            if(!is_first_jpeg)
            {
                is_first_jpeg = true;
            }

            else
            {
                fclose(current_file);
                sprintf(current_filename, "%03i.jpg", current_filenumber);
                current_file = fopen(current_filename, "w");
            }
            sprintf(current_filename, "%03i.jpg", current_filenumber);
            current_file = fopen(current_filename, "w");
            fwrite(buffer, sizeof(BYTE), bytes_read, current_file);
            current_filenumber++;

        }
        else
        {
            if (found_jpeg)
            {
                fwrite(buffer, sizeof(BYTE), bytes_read, current_file);
            }
                //Else
            //If already found a JPEG
        }
        fclose(file);
        fclose(current_file);
        return 0;


    }
 // Repeat until end of card
    //Read 512 bytes into buffer
    // If start of new JPEG
        //If first JPEG
        //Else close old and open new file
    //Else
        //If already found a JPEG

}