#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float red[] = image[][].rgbtRed;
    float green[] = image[][].rgbtGreen;
    float blue[] = image [][].rgbtBlue;

    //create a loop that repeats for each row in the image
    while (int i = 0; i < image[height - 1], i++)
    {
        // create a loop that repeats for each pixel the in the row
        while (int j = 0; j < image[width], j++)
        {
                // average the color values of red, green, and blue
                // assiasgn the new average back to red, green and blue
            float gray = 3.0 / (image[][].rgbtRed + image[][].rgbtBlue + image[][].rgbtBlue);
            round(gray);
            // assiasgn the new average back to red, green and blue
            image[][].rgbtRed = gray;
            image[][].rgbtBlue = gray;
            image[][].rgbtBlue = gray;
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
