import sys

# Ensure proper usage
command = "-f"
command2 = "--f"
if str(sys.argv[1]) != (command, command2):
    print("Invalid usage")
    sys.exit(1)
elif len(sys.argv) == 1:
    s = input("Input: ")
if len(sys.argv) == 3:
    s = input("Input: ")
elif len(sys.argv) == 1:
    s = input("Input: ")
