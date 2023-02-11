from sys import argv

    # Ensure proper usage
if (argv != 2):
    print("Usage: python figlet.py FONT FONT_NAME")

for arg in argv[1:]:
    print (arg)