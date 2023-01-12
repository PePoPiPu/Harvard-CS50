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
            rgbgray = round ((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue)/3.0);
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
            redsepia = round (( .393 * image[i][j].rgbtRed) + (.769 * image[i][j].rgbtGreen) + (.189 * image[i][j].rgbtBlue));
            greensepia = round (( .349 * image[i][j].rgbtRed) + (.686 * image[i][j].rgbtGreen) + (.168 * image[i][j].rgbtBlue));
            bluesepia = round (( .272 * image[i][j].rgbtRed) + (.534 * image[i][j].rgbtGreen) + (.131 * image[i][j].rgbtBlue));
            // Assigning sepia values to the original pixel values
            image[i][j].rgbtRed = redsepia;
            image[i][j].rgbtGreen = greensepia;
            image[i][j].rgbtBlue = bluesepia;

            if (redsepia > 255)
            {
                redsepia = (int) 255;
            }

            if (greensepia > 255)
            {
                greensepia = (int) 255;
            }

            if (bluesepia > 255)
            {
                bluesepia = (int) 255;
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
    // Create a temporary copy of the image
    RGBTRIPLE temp[height][width];
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                temp [i][j] = image[i][j];
            }
        }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j ++)
        {
            int totalRed, totalBlue, totalGreen;
            totalRed = totalBlue = totalGreen = 0;
            float counter = 0.00;

            // Getting the neighbouring pixels
            for (int x = - 1; x < 2; x++)
            {
                for ( int y = - 1; y < 2; y++)
                {
                    int currentX = i + x;
                    int currentY = j + y;

                    // Checking if the neighbouring pixel is a valid pixel
                    if (currentX < 0 || currentX > (height - 1) || currentY < 0 || currentY > (width - 1))
                    {
                        continue;
                    }

                    // Getting the image value
                    totalRed += image[currentX][currentY].rgbtRed;
                    totalGreen += image[currentX][currentY].rgbtGreen;
                    totalBlue += image[currentX][currentY].rgbtBlue;

                    counter++;
                }

                // Average of the neighbouring pixels
                temp[i][j].rgbtRed = round(totalRed / counter);
                temp[i][j].rgbtGreen = round(totalGreen / counter);
                temp[i][j].rgbtBlue = round(totalBlue / counter);
            }
        }
    }

    // Copying values to the original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
}
