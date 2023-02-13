# TODO
from cs50 import get_int

s = get_int("Height: ")
if s > 8:
    s = get_int("Height: ")
elif s < 1:
    s = get_int("Height: ")


for i in range(s):
    c = 0
    d = 0
    while c < s - 1:
        print(" ", end = "")
        c += 1
    while d < s:
        print("#")
        d += 1
