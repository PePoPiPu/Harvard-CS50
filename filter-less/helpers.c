#include "helpers.h"
#include <math.h>
#include <stdlib.h>
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
            // Using sepia's algorithm. Casting first values to an int so the programm doesn't run out of bits.
            redsepia = round (((int) 0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) + (0.189 * image[i][j].rgbtBlue));
            greensepia = round (((int) 0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) + (0.168 * image[i][j].rgbtBlue));
            bluesepia = round (((int) 0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) + (0.131 * image[i][j].rgbtBlue));
            // Assigning sepia values to the original pixel values
            image[i][j].rgbtRed = redsepia;
            image[i][j].rgbtGreen = greensepia;
            image[i][j].rgbtBlue = bluesepia;

            if (redsepia > 255)
            {
                redsepia = 255;
            }

            if (greensepia > 255)
            {
                greensepia = 255;
            }

            if (bluesepia > 255)
            {
                bluesepia = 255;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        if (width % 2 == 0)
        {
            for (int j = 0; j < width / 2 ; j++)
            {
               RGBTRIPLE tmp[height][width];
                tmp[i][j] = image [i][j];
                image[i][j] = image[i][width - (j + 1)];
                image[i][width - (j + 1 )] = tmp [i][j];
            }
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sumRed = 0;
            float sumGreen = 0;
            float sumBlue = 0;
            float counter = 0;
        }
    }
    return;
}
