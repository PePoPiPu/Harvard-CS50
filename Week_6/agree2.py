s = input("Do you agree? ")
# "If s is in the following list"
# Python supports object-oriented programming, certain types of values have attributes and functions built into them
# Strings come with a lot of functions, to access them we add a . as we were to access a struct in c
# docs.python.org
s = s.lower() # Returns a copy of the original string, you lose the original bytes
if s in ["y", "Y"]:
    print("Agreed.")
elif s in ["N", "n"]:
    print("Not agreed.")