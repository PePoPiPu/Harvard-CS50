#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main (void)
{
    string names[] = {"Bill", "Charlie", "Fred", "George", "Ginny", "Percy", "Ron"};

    for (int i = 0; i < 7; i++)
    {
        // Correct string comparison using strcmp. Returns a negative value if the first string comes before the second one, a positive value if it comes after and a 0 if it's the same string.
        if (strcmp(names[i], "Bill") == 0)
        {
            printf("Found\n");
            return 0;
        }
    printf ("Not found\n");
    return 1;
    }
}

// Example of an incorrect conditional. Trying to compare a string as an integer returns an error.
        //if (names[i] == "Ron")
        //{
        //    printf("Found\n");
        //    return 0;
        //}
