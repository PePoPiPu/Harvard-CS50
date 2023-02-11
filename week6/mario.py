from cs50 import get_int

# Python's equivalent to do while loops is:
# This is "the pythonic" way
while True:
    n = get_int("Height: ")
    if n > 0:
        break
for i in range(n):
    print("#")