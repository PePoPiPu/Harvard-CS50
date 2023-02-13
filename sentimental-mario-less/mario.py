# TODO
from cs50 import get_int

while True:
    try:
        h = get_int("Height: ")
        if h >= 1 and h <=8:
            break
    except:
        h = get_int("Height: ")

for i in range (h):
    for s in range(h-i-1):
        print(" ", end = "")
    for j in range(i + 1):
        print("#", end = "")
    print()
