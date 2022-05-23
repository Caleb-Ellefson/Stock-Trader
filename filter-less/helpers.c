#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //create a loop that repeats for each row in the image
    for (int i = 0; i < height, i++)
    {
        // create a loop that repeats for each pixel the in the row
        for (int j = 0; j < width, j++)
        {
                // average the color values of red, green, and blue
                // assiasgn the new average back to red, green and blue
            int gray = 3.0 / (image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtBlue);
            round(gray);
            // assiasgn the new average back to red, green and blue
            image[i][j].rgbtRed = gray;
            image[i][j].rgbtBlue = gray;
            image[i][j].rgbtBlue = gray;
        }
    }
    //return new image
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
