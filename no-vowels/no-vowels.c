// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch
#include <cs50.h>
#include <stdio.h>
// Function prototypes
char replace (char argv[i]);


int main(int argc, char* argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./no-vowels word\n");
        return 1;
    }
    // 
    printf("%c\n", replace(argv[1]));

}

