from pyfiglet import Figlet
import sys, random
figlet = Figlet()
figlet.getFonts()
random.seed()
if len(sys.argv) == 3:
    figlet.setFont(font = {sys.argv[2]})
elif len(sys.argv) < 2:
    figlet.setFont(font = random.seed)
s = input("Input: ")
print(figlet.renderText(s))