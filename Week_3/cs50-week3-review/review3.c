#include <cs50.h>
#include <stdio.h>
#include <string.h>
// This is a review of structs

// We can create a data type called person that holds 2 arrays
// Struct definitions go before MAIN, the same with function prototypes
typedef struct // Telling the compiler that we're defining our own data structure.
{
    string name;
    string number;
}
person; // Telling the compiler the name of the data structure.

int main (void)
{
    person people[2];
// Setting the values for each variable inside each person struct. We use the DOT operator.
    people[0].name = "Carter";
    people[0].number = "+1-617-495-1000";

    people[1].name = "David";
    people[1].number = "+1-949-468-2750";

    for (int i = 0; i < 2; i++)
    {
        if(strcmp(people[i].name, "David") == 0) // Accessing the "name" variable of the struct.
        {
            printf("Found %s\n", people[i].number); //Accessing the "number" variable of the struct.
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}











// Correct program but bad designed. We would have to carefully maintain each array. Bad when having a lot of data.
//int main (void)
//{
//    string names[] = {"Carter", "David"};
//    string numbers[] = {"+1-617-495-1000", "+1-949-468-2750"};

//    for (int i = 0; i < 2; i++)
//    {
//        if (strcmp(names[i], "David") == 0)
//        {
//            printf("Found %s\n", numbers[i]);
//            return 0;
//        }
//    }
//    printf("Not found\n");
//    return 1;
//}