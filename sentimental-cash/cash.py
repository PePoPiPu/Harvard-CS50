# TODO
from cs50 import get_float
def main():
    owed = get_float("Change owed: ")
    if owed > 0:
        print(f"Change owed: ${owed:.2f}")
    else:
        owed = get_float("Change owed: ")
        print(f"Change owed: ${owed:.2f}")

    quarters = quarters(owed)
    owed = owed - quarters * 25

    dimes = dimes(owed)
    owed = owed - dimes * 10

    nickels = nickels(owed)
    owed = owed - nickels * 5

    pennies = pennies (owed)
    owed = owed - pennies * 1

    # Sum coins
    coins = quarters + dimes + nickels + pennies

    # Print total of coins
    print(f"{coins}")
def quarters(owed):
    quarters = 0
    while owed >= 25:
        quarters += 1
        owed = owed - 25
    return quarters

def dimes(owed):
    dimes = 0
    while owed >= 10:
        dimes += 1
        owed = owed - 10
    return dimes
def nickels(owed):
    nickels = 0
    while owed >= 5:
        nickels += 5
        owed = owed - 5
def pennies(owed):
    pennies = 0
    while owed >= 1:
        pennies += 1
        owed = owed - 1

main()