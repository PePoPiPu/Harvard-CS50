# TODO
from cs50 import get_float
while True:
    try:
        owed = get_float("Change owed: ")
        print(f"Change owed: ${owed:.2f}")
    except:
        owed = get_float("Change owed: ")
