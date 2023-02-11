from pyfiglet import Figlet
import sys, random

if (sys.argv[1] == "-f" or sys.argv[1] == "--f"):
    if len(sys.argv) == 3:
        s = input("Input: ")
elif len(sys.argv) == 1:
    s = input("input: ")
else:
    print("Invalid usage")