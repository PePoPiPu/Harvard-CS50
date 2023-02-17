
def main():
    height = get_height()
    for i in range(height):
        print("#")

def get_height():
    while True:
        #Validation of input. "Try to execute unless something happens"
        try:
            n = int(input("Height: "))
            if n > 0:
                return n
        except ValueError:
            print("Not an integer")

main()