# TODO
from cs50 import get_int

s = get_int("Height: ")
if s > 8:
    s = get_int("Height: ")
elif s < 1:
    s = get_int("Height: ")

i = 0
while i < s:
    c = 0
    i += 1
    while c < s - 1:
        print("#", end = "")
        c += 1