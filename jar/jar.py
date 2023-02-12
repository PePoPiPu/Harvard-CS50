class Jar:
    def __init__(self, capacity=12):
        self.capacity = capacity
        self.first_set = 0
        self.size = 0
        ...

    def __str__(self):
        ...

    def deposit(self, n):
        ...

    def withdraw(self, n):
        ...

    @property
    def capacity(self):
        ...

    @property
    def size(self):
        ...

def main():
    jar = Jar()
    print(str(jar.capacity))

main()