# TODO
from cs50 import get_int
# Prompt user for input
while True:
    try:
        h = get_int("Height: ")
        if h >= 1 and h <= 8:
            break
    except:
        h = get_int("Height: ")
# Loop through height range
for i in range(h):
    # Print spaces
    for s in range(h-i-1):
        print(" ", end="")
    # Print hashes
    for j in range(i + 1):
        print("#", end="")
    print()
