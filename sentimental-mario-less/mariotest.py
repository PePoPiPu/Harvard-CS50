s = 3
j = 0
for i in range(s):
    for j in range(s):
        if j < s:
            print("#", end ="")
            j += 1
    print()