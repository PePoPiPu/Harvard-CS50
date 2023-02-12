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
    orders = []
    while True:
        try:
            item = str.title(input("Item: "))
            if item in taq:
                orders.append(taq[item])
                total = float(sum(orders))
                print(f"Total: ${total:.2f}")
            else:
                continue
        except EOFError:
            print("")
            sys.exit(0)
main()