// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Prototypes
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    // Storing the Header into an array, which in itself is a data type of an unsigned integer
    uint8_t header[HEADER_SIZE];

        fread (&(header[HEADER_SIZE]), 1, 1, input);
        fwrite (&(header[HEADER_SIZE]), 1, 1, output);

    // TODO: Read samples from input file and write updated data to output file
    // Storing the samples into an array, which in itself is a data type of signed integer
    int16_t buffer;

    while(fread(&buffer, sizeof(int16_t), 1, input))
    {
        //Update the volume
        buffer *= factor;
        fwrite(&buffer, sizeof(int16_t), 1, output;
    }

    // Close files
    fclose(input);
    fclose(output);
}
