# TODO
from cs50 import get_int

s = get_int("Height: ")
if s > 8:
    s = get_int("Height: ")
elif s < 1:
    s = get_int("Height: ")

# loop for s times
    # for j = s - 1 times, print 1 space
    # for j + 1 times, print 1 hash

for i in range (s):
    j = s - 1
    for i in range(j):
        print("#")
        j += 1