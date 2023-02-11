# The input function gives back a string by default, we have to convert it to an int
x = int (input ("x: "))
y = int (input ("y: "))
# In c, dividing an int by an int, it would round down to the nearest integer causing TRUNCATION
# Python handles the truncation by converting ints automatically to a float
# A problem that remains is floating point imprecision
z = x / y
print(f"{z:.50f}")