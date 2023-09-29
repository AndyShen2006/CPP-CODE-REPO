# By Andy Shen
n = int(input())
for x in range(100, n + 1):
    if (
        (x // 100) * (x // 100) * (x // 100)
        + (x // 10 % 10) * (x // 10 % 10) * (x // 10 % 10)
        + (x % 10) * (x % 10) * (x % 10)
    ) == x:
        print(x)
