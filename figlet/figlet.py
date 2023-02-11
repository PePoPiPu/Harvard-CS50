from pyfiglet import Figlet
import sys, random
figlet = Figlet()
figlet.getFonts()
validfont = figlet.getFonts()
if len(sys.argv) == 1:
    s = input("Input: ")
    figlet.setFont(font = random)
    print(figlet.renderText(s))
    sys.exit()
elif (sys.argv[1] == "-f" or sys.argv[1] == "--font"):
    if len(sys.argv) == 3:
        if sys.argv[2] not in validfont:
            print("Invalid usage")
        else:
            s = input("Input: ")
            figlet.setFont(font = sys.argv[2])
            print(figlet.renderText(s))
            sys.exit()
else:
    print("Invalid usage")
    sys.exit(1)


