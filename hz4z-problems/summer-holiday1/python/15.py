# By Andy Shen
n = int(input())
for x in range(1, n + 1):
    for y in range(n - x):
        print(end=" ")
    for y in range(1, 2 * x):
        print(y, end="")
    print()
