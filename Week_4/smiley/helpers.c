#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    // Iterating through columns of pixels
    for (int i = 0; i < height; i++)
    {
        // Iterating through lines of pixels
        for (int j = 0; j < width; j++)
        {
            // If pixel is black (0x00), change to specific color.
            if (image[i][j].rgbtRed == 0x00 && image[i][j].rgbtGreen == 0x00 && image [i][j].rgbtBlue == 0x00)
            {
                image[i][j].rgbtRed = 0xff;
                image[i][j].rgbtGreen = 0xfa;
                image[i][j].rgbtBlue = 0xbc;
            }
        }
    }

}
