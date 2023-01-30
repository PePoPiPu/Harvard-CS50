#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }
 // Open the memory card
    FILE *card = fopen(argv[1], "r");
// Declaring NULL pointer
    FILE *img = NULL;

// Declaring a buffer of size 512
    BYTE buffer[512];
// Declaring filename
    char filename [3];
// Setting a counter to 0
    int counter = 0;
// Start reading file
    while(fread(buffer, sizeof(BYTE), 512, file) == 512)
    {
        // Check if beginning of JPEG file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // If it's the beginning of a JPEG, set counter to 0
            // Write a new jpeg
            if (counter == 0)
            {
                sprintf(filename,"%03i.jpg", counter)
                img = fopen(filename,"w");
                fwrite(&buffer, sizeof(BYTE), 512, img);
                counter++;
            }
            // If start of img
        }
    }
}