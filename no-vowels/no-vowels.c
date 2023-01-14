// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace (string argv[]);
int main(int argc, string argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./no-vowels word\n");
    }
    string word = argv[1];
    printf("%s\n", word);
}

string replace (string argv[])
{

}
