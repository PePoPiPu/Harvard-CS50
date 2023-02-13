from cs50 import get_int

s = get_int("Height: ")
if s > 8:
    s = get_int("Height: ")
elif s < 1:
    s = get_int("Height: ")

for i in range(s):
    for j in range(s - 1):
        print("#", end="")
# TODO