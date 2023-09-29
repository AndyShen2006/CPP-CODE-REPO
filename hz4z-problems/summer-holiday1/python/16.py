# By Andy Shen
n = int(input())
for x in range(1, n + 1):
    for y in range(n - x):
        print(end=" ")
    for y in range(2 * x - 1):
        print("*", end="")
    print()
for x in range(n - 1, 0, -1):
    for y in range(n - x):
        print(end=" ")
    for y in range(2 * x - 1):
        print("*", end="")
    print()
