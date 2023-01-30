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
// Declaring NULL pointer
    FILE *img = NULL;

// Declaring a buffer of size 512
    BYTE buffer[512];
// Declaring filename
    char filename [3];
// Setting a counter to 0
    int counter = 0;
// Start reading file
    while(fread(buffer,sizeof(BYTE), 512))
}