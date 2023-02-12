import sys
taq = {
    "Baja Taco": 4.00,
    "Burrito": 7.50,
    "Bowl": 8.50,
    "Nachos": 11.00,
    "Quesadilla": 8.50,
    "Super Burrito": 8.50,
    "Super Quesadilla": 9.50,
    "Taco": 3.00,
    "Tortilla Salad": 8.00
}

def main():
    while True:
        try:
            item = input("Item: ")
            total = float(taq[item])
            print(f"Total: ${total}")
        except EOFError:
            print("")
            sys.exit(1)
main()