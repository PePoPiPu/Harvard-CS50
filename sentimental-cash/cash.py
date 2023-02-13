# TODO
from cs50 import get_float

owed = get_float("Change owed: ")
if owed > 0:
    print(f"Change owed: ${owed:.2f}")
else:
    owed = get_float("Change owed: ")
    print(f"Change owed: ${owed:.2f}")
