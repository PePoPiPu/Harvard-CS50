from sys import argv

# Ensure proper usage
if argv != ["-f", "--ff", "FONT_NAME"]:
    print("Usage: python figlet.py FONT FONT_NAME")
