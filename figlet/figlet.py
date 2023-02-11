import sys

# Ensure proper usage
if len(sys.argv) == 3:
    s = input("Input: ")
    if sys.argv[1] == ("-f", "--f"):
        s = input("Input: ")

elif len(sys.argv) == 1:
    s = input("Input: ")
else:
    print("Invalid usage")
    sys.exit(1)
