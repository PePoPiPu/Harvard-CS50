# TODO
from cs50 import get_float


def main():
    # Prompting user for input
    owed = get_float("Change owed: ")
    # Keep prompting if non-negative integer is given
    if owed < 0:
        owed = get_float("Change owed: ")

    # Calculating functions call and rounding up owed variable to avoid floating point imprecision
    quarters = calc_quarters(round(owed, 2))
    owed = owed - (quarters * 0.25)

    dimes = calc_dimes(round(owed, 2))
    owed = owed - (dimes * 0.10)

    nickels = calc_nickels(round(owed, 2))
    owed = owed - (nickels * 0.05)

    pennies = calc_pennies(round(owed, 2))
    owed = owed - (pennies * 0.01)

    # Sum coins
    coins = quarters + dimes + nickels + pennies

    # Print total of coins
    print(f"{coins}")

# Calculate quarters


def calc_quarters(owed):
    quarters = 0
    while owed >= 0.25:
        quarters += 1
        owed = owed - 0.25
    return quarters

# Calculate dimes


def calc_dimes(owed):
    dimes = 0
    while owed >= 0.10:
        dimes += 1
        owed = owed - 0.10
    return dimes

# Calculate nickels


def calc_nickels(owed):
    nickels = 0
    while owed >= 0.05:
        nickels += 1
        owed = owed - 0.05
    return nickels

# Calculate pennies


def calc_pennies(owed):
    pennies = 0
    while owed >= 0.01:
        pennies += 1
        owed = owed - 0.01
    return pennies


main()

