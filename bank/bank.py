s = input("Greeting: ")
s = s.lower()
if s.startswith("Hello") == True:
    print("0$")
elif s.startswith("H") == True:
    print("20$")
else:
    print("100$")