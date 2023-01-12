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
    FILE *card = fopen(arv[1], "r");
 // Look for the beginning of a JPEG
 // Open a new JPEG file
 // Write 512 bytes until a new JPEG is found
 // Stop at the end of the file
}