# people = dict() creates an empy dictionary called people. The line of code down below does exactly the same thing but in a shorter manner
people = {
    "Carter": "+1-617-495-1000",
    "David": "+1-949-468-2750"
}

name = input("Name: ")
if name in people:
    print(f"Number: {people[name]}")