#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Initializing float rgbgray
    float rgbgray;
    // Iterating through height pixels
    for (int i = 0; i < height; i++)
    {
        // Iterating through width pixels
        for (int j = 0; j < width; j++)
        {
            rgbgray = round ((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue)/3);
            image[i][j].rgbtRed = rgbgray;
            image[i][j].rgbtGreen = rgbgray;
            image[i][j].rgbtBlue = rgbgray;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Initialzing sepia floats for each pixel color
    float redsepia;
    float greensepia;
    float bluesepia;
    // Iterating through height pixels
    for (int i = 0; i < height; i++)
    {
        // Iterating through width pixels
        for (int j = 0; j < width; j++)
        {
            // Using sepia's algorithm. Casting first values to an int so the program doesn't lose any bits.
            redsepia = round (((int) 0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) + (0.189 * image[i][j].rgbtBlue));
            greensepia = round (((int) 0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) + (0.168 * image[i][j].rgbtBlue));
            bluesepia = round (((int) 0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) + (0.131 * image[i][j].rgbtBlue));
            // Stablishing maximum pixel value to 255 so it doesn't fall over that value.
            redsepia = min (redsepia, 255);
            greensepia = min (greensepia, 255);
            bluesepia = min (bluesepia, 255);
        }
    }
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
