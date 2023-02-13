# TODO
from cs50 import get_float
def main():
    owed = get_float("Change owed: ")
    if owed > 0:
        print(f"Change owed: ${owed:.2f}")
    else:
        owed = get_float("Change owed: ")
        print(f"Change owed: ${owed:.2f}")

def quarters(owed):
    quarters = 0
    while owed >= 25:
        quarters += 1

        owed = owed - 25
main()