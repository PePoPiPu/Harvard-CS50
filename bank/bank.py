s = input("Greeting: ")
s = s.lower()
if s.startswith('Hello', 'hello'):
    print("0$")
elif s.startswith("H", "h"):
    print("20$")
else:
    print("100$")