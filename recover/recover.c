#include <stdio.h>
#include <stdlib.h>

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
 // Declaring a buufer
    char buffer[512];
    fread (&buffer, sizeof(buffer), 512, card);
 // Look for the beginning of a JPEG (0xff, 0xd8, 0xff)
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff)
    {
        if (buffer[3] == 0xe1 || buffer[3] == 0xe2 || buffer[3] == 0xe3 || buffer[3] == 0xe4 || buffer[3] == 0xe5 || buffer[3] == 0xe6 || buffer[3] == 0xe7 || buffer[3] == 0xe8 || buffer[3] == 0xe9 || buffer[3] == 0xea || buffer[3] == 0xeb || buffer[3] == 0xec || buffer[3] == 0xed || buffer[3] == 0xee || buffer[3] == 0xef)
        {
            int filename[2];
            sprintf(filename[0], "%03i.jpg", 2);
            FILE *img = fopen(filename, "w");
            fwrite(nimg *ptr, 512, sizeof(card), FILE *jpeg);
        }
    }
 // Open a new JPEG file
 // Write 512 bytes until a new JPEG is found
 // Stop at the end of the file
}