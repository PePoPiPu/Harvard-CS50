#include <cs50.h>
#include <stdio.h>
// Main program.
int main(void)
{
//Prompt user for an answer.
    string answer = get_string("What's your name? ");
// Prints, hello, "user" and makes a new line with a escape sequence. "\n"
    printf("hello, %s\n", answer);
}