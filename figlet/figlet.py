import sys

# Ensure proper usage
if len(sys.argv) == 3:
    if sys.argv[1] == ("-f", "--f"):
        s = input("Input: ")
if len(sys.argv) == 1:
    s = input("Input: ")
else:
    print("Invalid usage")
    sys.exit(1)
