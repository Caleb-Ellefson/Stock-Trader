#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //create a loop that repeats for each row in the image
    for (int i = 0; i < height; i++)
    {
        // create a loop that repeats for each pixel the in the row
        for (int j = 0; j < width; j++)
        {
            // average the color values of red, green, and blue
            // assiasgn the new average back to red, green and blue
            int gray = round((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3.0);

            // assiasgn the new average back to red, green and blue
            image[i][j].rgbtRed = gray;
            image[i][j].rgbtBlue = gray;
            image[i][j].rgbtGreen = gray;
        }
    }
    //return new image
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];

            float sepiaRed = round(.393 * pixel.rgbtRed + .769 * pixel.rgbtGreen + .189 * pixel.rgbtBlue);
            float sepiaGreen = round(.349 * pixel.rgbtRed + .686 * pixel.rgbtGreen + .168 * pixel.rgbtBlue);
            float sepiaBlue = round(.272 * pixel.rgbtRed + .534 * pixel.rgbtGreen + .131 * pixel.rgbtBlue);

            image[i][j].rgbtRed = sepiaRed > 255 ? 255 : sepiaRed;
            image[i][j].rgbtBlue = sepiaBlue > 255 ? 255 : sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen > 255 ? 255 : sepiaGreen;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];



    for (int i = 0; i < height; i++)
    {
        int curPos = 0;
        for (int j = width - 1; j >= 0; j--, curPos++)
        {
            temp[i][curPos] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
        RGBTRIPLE temp[height][width];

        for (int row = 0; row < height; row++)
    {
            for (int col = 0; col < width; col++)
            {
                int count = 0;
                int rowcoords[] = { row - 1, row , row+1 };
                int colcoords[] = { col - 1, col , col+1 };
                float totalR = 0, totalG = 0, totalB = 0;

                for(int r = 0; r < 3; r++)
                {
                    for(int c = 0; c < 3; c++)
                    {
                        int curRow = rowcoords[r];
                        int curCol = colcoords[c];

                        if (curRow >= 0 && curRow < height && curCol >= 0 && curCol < width)
                        {
                            RGBTRIPLE pixel = image[curRow][curCol];
                            totalR += pixel.rgbtRed;
                            totalB += pixel.rgbtBlue;
                            totalG += pixel.rgbtGreen;
                            count++;
                        }
                    }
                }
                    temp[row][col].rgbtRed = round(totalR / count);
                    temp[row][col].rgbtBlue = round(totalB / count);
                    temp[row][col].rgbtGreen = round(totalG / count);
            }
    }


    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
    return;
}
