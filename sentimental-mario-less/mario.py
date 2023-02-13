# TODO
from cs50 import get_int

s = get_int("Height: ")
if s > 8:
    s = get_int("Height: ")
elif s < 1:
    s = get_int("Height: ")

# loop for s times
    # print 1 space for j times
    # for j + 1 times, print 1 hash

for i in range (s):
    j = s - 1
    for j in range(s):
        print("#",end = "")
        j -= 1