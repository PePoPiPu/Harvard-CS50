s = 3
c = s - 1
j = 0
for i in range(s):
    for j in range(s):
        c = s - j
        while c > 0:
            print("#", end ="")
            c -= 1
    print()