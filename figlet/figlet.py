from pyfiglet import Figlet
import sys, random

if len(sys.argv) == 3:
    s = input("Input: ")
elif (sys.argv[1] == "-f" or sys.argv[1] == "--f"):
    if len(sys.argv) == 3:
        s = input("Input: ")
else:
    print("Invalid usage")