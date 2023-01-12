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
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Use sepia's algorithm. Multiply image [i][j].rgbtBYTE by Sepia values and round up to nearest integer.
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
