import sys

# Ensure proper usage
if len(sys.argv) == 3:
    s = input("Inputo: ")
elif str(sys.argv[1]) != ("-f", "--f"):
    print("Invalid usage")