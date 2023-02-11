import sys

# Ensure proper usage
if len(sys.argv) == 3:
    s = input("Inputo: ")
    if str(sys.argv[1]) == ("-f", "--f"):
        s = input("Input: ")