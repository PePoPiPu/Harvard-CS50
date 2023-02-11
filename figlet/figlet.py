import sys

# Ensure proper usage
if len(sys.argv) == 3:
    if sys.argv[1] != ("-f", "--f"):
        print("Invalid usage")
    else:
        print(f"{sys.argv[1]}")
elif len(sys.argv) == 1:
    s = input("Input: ")
else:
    print("Invalid usage")
    sys.exit(1)
