#include <stdio.h>
#include <stdlib.h>
// Function prototypes
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }
 // Open the memory card
    FILE *card = fopen(arv[1], "r");
    fread (buffer[i] *ptr, 512, sizeof(card), FILE *card);
 // Look for the beginning of a JPEG (0xff, 0xd8, 0xff)
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff)
    {
        if (buffer[3] && 0xf0 == 0xe0)
        {
            
        }
    }
 // Open a new JPEG file
 // Write 512 bytes until a new JPEG is found
 // Stop at the end of the file
}